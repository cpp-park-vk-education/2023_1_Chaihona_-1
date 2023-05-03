#include <gtest/gtest.h>
#include <format>
#include "DBConnection.hpp"
#include "DBWork.hpp"
#include "SQLProvider.hpp"
#include "contact.hpp"


TEST (db_test, conn_test) {
    auto dbcm = new DBConnection ();
    dbcm->enter(true);
    dbcm->exit();
}


TEST (db_test, operations_test) {
    auto dbcm = new DBConnection ();
    auto dbWork = new DBWork(dbcm);
    std::pair<std::vector<std::string>, std::vector<std::vector<std::string>>> output;
    EXPECT_EQ(dbWork->insert("a"), 1);
    EXPECT_EQ(dbWork->select("a"), output);
    dbWork->update("a");
}


TEST(db_test, sqlprovider_test) {
    auto provider = new SQLProvider();
    std::string expected = "SELECT b FROM c";
    std::string a("a");
    auto args = std::make_format_args("b","c");
    EXPECT_EQ(provider->getRequest(a,args), expected);
}


int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}