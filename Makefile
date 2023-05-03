.PHONY: build run test coverage linter

build:
	mkdir build
	mkdir log
	
run:
	@echo "RUN"
	@cd build && cmake .. > cmakelog.txt && make > makelog.txt && ./chaihona
	@rm -r build

test:
	@echo "TESTING"
	@cd build && cmake .. -DTEST=ON > ../log/cmakelog_dbtest.txt && make > ../log/makelog_dbtest.txt && ./test/dbTest/db_test > ../log/test_log_db.txt 	
	@cd build && ./test/dbRequestsTest/db_requests_test
	@cd build && ./test/geocoderTest/geocoder_test

coverage:
	@echo "COVERAGE"
	@cd build && cmake .. -DTEST=ON > ../log/cmakelog_dbtest.txt && make > ../log/makelog_dbtest.txt && ./test/dbTest/db_test > ../log/test_log_db.txt 	
	@cd build && lcov -t "test/dbTest/db_test" -o coverage.info -c -d .
	@cd build && lcov --remove coverage.info '*/usr/local/include/pqxx*' '*/nlohmann/*' '*/13.1.0/*' '*/usr/include/gtest*' -o mycoverage.info
	@cd build && genhtml -o report mycoverage.info > ../log/dbtest_cov.txt

linter:
	@cpplint main.cpp