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
	@cd build && cmake .. -DTEST=ON > ../log/cmakelog_sample.txt && make > ../log/makelog_sample.txt && ./test/sample_test > ../log/test_log_sample.txt 	
	@rm -r build

coverage:
	@echo "COVERAGE"
	@cd build && cmake .. -DTEST=ON > ../log/cmakelog_static.txt && make > ../log/makelog_static.txt && ./test/sample_test
	@cd build && lcov -t "test/sample_test" -o coverage.info -c -d sample/ && genhtml -o report coverage.info > ../log/static_cov.txt

linter:
	@cpplint main.cpp