#pragma once
enum class CONTACTTYPES {PHONE, TELEGRAM, WHATSAPP, VK, STEAM, TWITTER, FACEBOOK, SPOTIFY};

class Contact {
private: 
    unsigned id;
    CONTACTTYPES contactType;
    std::string value;
public:
    Contact() {}; 
    unsigned getId() {return 1;};
    CONTACTTYPES getContactType() {return CONTACTTYPES::PHONE;};
    std::string getContactValue() {return std::string("+7(999)999-99-99");};   
};