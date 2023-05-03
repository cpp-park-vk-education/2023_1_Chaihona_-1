#include <gtest/gtest.h>
#include <format>
#include "DBConnection.hpp"
#include "DBWork.hpp"
#include "SQLProvider.hpp"
#include "contact.hpp"


/*
* Тест подстановки параметров запросов в шаблоны
* Возможные варианты
* 1) Успешная подстановка
* 2) Передано недостаточное количество параметров
* Закомментированные строчки не проходят тест, так как ещё не готова реализация.
*/
TEST(sql__sqlprovider_test, sqlprovider_test) {
    auto provider = new SQLProvider();
    std::string expected = "SELECT b FROM c";
    std::string a("a");
    auto args = std::make_format_args("b","c");
    EXPECT_EQ(provider->getRequest(a,args), expected);
    //auto args = std::make_format_args("b");
    //EXPECT_EQ(provider->getRequest(a,args), std::exception());
}


/*
* Тест подключения к базе данных
* Возможные варианты
* 1) Успешное подключение
* 2) Ошибка подключения из-за неверно переданного конфига базы данных
*/
TEST (conn_test, conn_test) {
    auto dbcm = new DBConnection ();
    dbcm->enter(true);
    dbcm->exit();
}


/*
* Тест операции вставки в БД
* Возможные варианты
* 1) Успешная вставка
* 2) Попытка вставить в поле значение несоответствующего типа
* 3) Попытка вставить в поле значение, размер которого превышает допустимый размер поля
* 4) Попытка добавить FOREIGN KEY на несуществующее поле
* 5) Попытка вставки в несуществующую таблицу
* Закомментированные строчки не проходят тест, так как ещё не готова реализация.
*/
TEST (operations_test, insert_test) {
    auto dbcm = new DBConnection ();
    auto dbWork = new DBWork(dbcm);
    EXPECT_EQ(dbWork->insert("INSERT INTO a VALUES ('1', '228', 'text', '1')"), 1);
    //EXPECT_THROW(dbWork->insert("INSERT INTO a VALUES ('1', 'abc', 'texxxt', '1')"), std::exception());
    //EXPECT_THROW(dbWork->insert("INSERT INTO a VALUES ('1', '228', 'texxxt', '1')"), std::exception());
    //EXPECT_THROW(dbWork->insert("INSERT INTO a VALUES ('1', '228', 'texxxt', '1000')"), std::exception());
}


/*
* Тест операции редактирования в БД
* Возможные варианты
* 1) Успешное редактирование
* 2) Попытка вставить в поле значение несоответствующего типа
* 3) Попытка вставить в поле значение, размер которого превышает допустимый размер поля
* 4) Попытка изменить поле с FOREIGN KEY на несуществующий внешний ключ.
* 5) Попытка редактирования несуществующей таблицы/поля в таблице
* Закомментированные строчки не проходят тест, так как ещё не готова реализация.
*/
TEST (operations_test, update_test) {
    auto dbcm = new DBConnection ();
    auto dbWork = new DBWork(dbcm);
    dbWork->update("INSERT INTO a VALUES ('1', '228', 'text')");
    //EXPECT_THROW(dbWork->update("b"), std::exception());
    //EXPECT_THROW(dbWork->update("c"), std::exception());
    //EXPECT_THROW(dbWork->update("c"), std::exception());
}


/*
* Тест операции удаления из БД
* Возможные варианты
* 1) Успешное удаление
* 2) Удаление из несуществующей таблицы
* 3) Удаление поля с ограничением RESTRICT
* Закомментированные строчки не проходят тест, так как ещё не готова реализация.
*/
TEST (operations_test, delete_test) {
    auto dbcm = new DBConnection ();
    auto dbWork = new DBWork(dbcm);
    dbWork->update("DELETE FROM a WHERE");
    //EXPECT_THROW(dbWork->update("DELETE FROM a WHERE"), std::exception());
    //EXPECT_THROW(dbWork->update("DELETE FROM a WHERE"), std::exception());
}


int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}