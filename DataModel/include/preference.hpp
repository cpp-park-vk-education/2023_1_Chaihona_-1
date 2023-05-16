#pragma once
#include <boost/json.hpp>


class Preference {
private:
    unsigned minAge;
    unsigned maxAge;
    unsigned radius;
    char gender; //F for female, M for male
public:
    Preference() {}
    Preference(unsigned _mina, unsigned _maxa, unsigned _rad, char _gender) : minAge(_mina), maxAge(_maxa), radius(_rad), gender(_gender) {}
    unsigned getMinAge() const {return minAge;}
    unsigned getMaxAge() const {return maxAge;}
    unsigned getRadius() const {return radius;}
    char getGender() const {return gender;}
};


void tag_invoke(const boost::json::value_from_tag&, boost::json::value& jv, Preference const& user);

Preference tag_invoke(boost::json::value_to_tag<Preference>, boost::json::value const& jv);