enum CONTACTTYPES {PHONE, TELEGRAM, WHATSAPP, VK, STEAM, TWITTER, FACEBOOK, SPOTIFY}


class Contact {
private:    
    CONTACTTYPES contactType;
    std::string value;
public:
    Contact();    
};