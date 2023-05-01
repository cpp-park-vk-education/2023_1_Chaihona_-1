#include <format>
#include <string>
#include <iostream>
#include "DBConnection.hpp"

int main() {
    auto dbcm = new DBConnection ();
    dbcm->enter(true);
    dbcm->exit();
    return 0;
}