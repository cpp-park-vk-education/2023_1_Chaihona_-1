#include <ctype.h>
#include <vector>

#include "profile.hpp"
#include "interest.hpp"
#include "lifestyle.hpp"

class Form{
private:
    Profile profile;
    std::vector<Interest> interests;
    std::vector<Lifestyle> lifestyle;
    std::string description;
    std::string university;
    std::string career;
    std::string location;
    time_t birthDate;
public:
    Form();    
};