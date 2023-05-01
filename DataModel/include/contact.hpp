#pragma once
enum class CONTACTTYPES {PHONE, TELEGRAM, WHATSAPP, VK, STEAM, TWITTER, FACEBOOK, SPOTIFY};

class Contact {
private:    
    CONTACTTYPES contactType;
    std::string value;
public:
    Contact(); 
    CONTACTTYPES getContactType() {return CONTACTTYPES::PHONE;};
    std::string getContactValue() {return std::string("+7(999)999-99-99");};   
};