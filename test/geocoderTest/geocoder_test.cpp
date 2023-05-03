#include <gtest/gtest.h>
#include "Geocoder.hpp"


/*
* Тест функции, возвращающей ip-адрес
* Возможные варианты:
* 1) Успешная работа функции
* 2) Сервис определения ip-адреса упал, но это никак не протестировать =(
*/
TEST(geocoder_test, get_ip_test) {
    Geocoder geocoder;
    EXPECT_EQ(geocoder.getIp(), "46.242.12.19");
}

/*
* Тест функции, возвращающей название город по ip
* Возможные варианты:
* 1) Успешная работа функции
* 2) Передача неверного ip-адреса
* Закомментированные строчки не проходят тест, так как ещё не готова реализация.
*/
TEST (geocoder_test, city_by_ip_test) {
    Geocoder geocoder;
    EXPECT_EQ(geocoder.getCityByIp("46.242.12.19"),"Moscow"); 
    //EXPECT_THROW(Geocoder->getCityByIp("777.888.999.1000"), std::exception); 
}

/*
* Тест функции, возвращающей название города по координатам
* Возможные варианты:
* 1) Успешная работа функции
* 2) Передача некорректных координат
* 3) Передач точки, не являющейся населённым пунктом
* Закомментированные строчки не проходят тест, так как ещё не готова реализация.
*/
TEST (geocoder_test, city_by_coords_test) {
    Geocoder geocoder;
    EXPECT_EQ(geocoder.getCityByCoords("55.7522N, 37.6156E"),"Moscow");
    //EXPECT_THROW(Geocoder->getCityByCoords("777.7522A, 666.6156B"), std::exception);
    //EXPECT_THROW(Geocoder->getCityByCoords("55.560397N, 37.529192E"), std::exception);
}


int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}