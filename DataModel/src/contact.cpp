#include "contact.hpp"

void tag_invoke(const boost::json::value_from_tag &, boost::json::value &jv, Contact const &contact) {
    jv = {
        {"contact type", contact.getContactType()},
        {"value", contact.getContactValue()}
    };
}

Contact tag_invoke(boost::json::value_to_tag<Contact>, boost::json::value const& jv) {
    boost::json::object const &obj = jv.as_object();
    return Contact{
        boost::json::value_to<std::string>(obj.at("contact type")),
        boost::json::value_to<std::string>(obj.at("value"))
    };
}