#include <string>

class Geocoder {
    std::string getIp ();
    std::string getCityByIp (std::string ip);
    std::string getCityByCoords (std::string coords);
};