#include <string>

class Geocoder {
public:
    Geocoder() {};    
    std::string getIp () {return std::string("46.242.12.19");};
    std::string getCityByIp (std::string ip) {return std::string("Moscow");};
    std::string getCityByCoords (std::string coords) {return std::string("Moscow");};
};