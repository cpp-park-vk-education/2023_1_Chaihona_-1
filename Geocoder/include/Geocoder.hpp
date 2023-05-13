#include <string>
#include <curl/curl.h>
#include <iostream>
#include <fstream>
#include <json.hpp>
#include <format>

using json = nlohmann::json;

class Geocoder {
public:
    Geocoder() {};    
    std::string getIp ();
    std::string getCityByIp (std::string ip);
    std::string getCityByCoords (double lat, double lon);
};