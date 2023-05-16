#include "Geocoder.hpp"


size_t writeCityIpCallback(char* contents, size_t size, size_t nmemb, std::string& out) {
    std::string content (contents);
    content = content.substr(0, content.size()-5);
    json userp = json::parse(content);
    out = userp["location"]["value"];
    return nmemb;
}

size_t writeCoordsCityCallback(char* contents, size_t size, size_t nmemb, std::string& out) {
    std::string content (contents);
    content = content.substr(0, content.size()-5);
    json userp = json::parse(content);
    out = userp["suggestions"][1]["data"]["region"];
    return nmemb;
}

size_t writeIpCallback(char* contents, size_t size, size_t nmemb, std::string& content) {
    content = std::string(contents);
    return nmemb;
}


std::string Geocoder::getIp() {
    curl_global_init(CURL_GLOBAL_ALL);
    CURL *curl = curl_easy_init();
 
    curl_easy_setopt(curl, CURLOPT_URL, "https://ipinfo.io/ip");
    curl_easy_setopt(curl, CURLOPT_HTTPGET, 1L);

    std::string ip;
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, writeIpCallback);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &ip);

    CURLcode res = curl_easy_perform(curl);
    if(res != CURLE_OK) {
        std::cerr << "Failed to get ip: " << curl_easy_strerror(res) << std::endl;
    }

    curl_easy_cleanup(curl);
    curl_global_cleanup();
    return ip;
}

std::string Geocoder::getCityByIp(std::string ip) {
    curl_global_init(CURL_GLOBAL_ALL);
    CURL *curl = curl_easy_init();
    std::setlocale(LC_ALL, "Russian");
    curl_easy_setopt(curl, CURLOPT_URL, "https://suggestions.dadata.ru/suggestions/api/4_1/rs/iplocate/address?ip=46.242.12.19");
    curl_easy_setopt(curl, CURLOPT_HTTPGET, 1L);

    struct curl_slist *headers = nullptr;
    headers = curl_slist_append(headers, "Accept: application/json");
    headers = curl_slist_append(headers, "Authorization: Token 644713333a8d93d09baa7fb7dfbbd78047d14782");
    curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);

    std::string resPost;
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, writeCityIpCallback);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &resPost);

    CURLcode res = curl_easy_perform(curl);
    if(res != CURLE_OK) {
        std::cerr << "curl_easy_perform() failed: " << curl_easy_strerror(res) << std::endl;
    }

    curl_easy_cleanup(curl);
    curl_global_cleanup();   
    
    return resPost;
}


std::string Geocoder::getCityByCoords(double lat, double lon) {
    curl_global_init(CURL_GLOBAL_ALL);
    CURL *curl = curl_easy_init();
    curl_easy_setopt(curl, CURLOPT_URL, "https://suggestions.dadata.ru/suggestions/api/4_1/rs/geolocate/address");
    curl_easy_setopt(curl, CURLOPT_POST, 1L);

    struct curl_slist *headers = nullptr;
    headers = curl_slist_append(headers, "Content-Type: application/json");
    headers = curl_slist_append(headers, "Accept: application/json");
    headers = curl_slist_append(headers, "Authorization: Token 644713333a8d93d09baa7fb7dfbbd78047d14782");
    curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);

    std::string latLon = std::format(" \"lat\": \"{}\", \"lon\": \"{}\" ", lat, lon);
    latLon = "{" + latLon + "}"; //нельзя добавить сразу, чтобы не ломался std::format
    const char *data = latLon.c_str(); //libcurl не хочет работать с std::string, только с char*
    curl_easy_setopt(curl, CURLOPT_POSTFIELDS, data);

    std::string resPost;
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, writeCoordsCityCallback);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &resPost);
    CURLcode res = curl_easy_perform(curl);

    if(res != CURLE_OK) {
        std::cerr << "curl_easy_perform() failed: " << curl_easy_strerror(res) << std::endl;
    }

    curl_easy_cleanup(curl);
    curl_global_cleanup();   
    return resPost;
}