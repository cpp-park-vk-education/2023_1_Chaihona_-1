#include <vector>

#include "form.hpp"

class SelectRecForms {
private:    
    std::string location;
    time_t birthDate;
public:
    SelectRecForms() {};
    std::vector<Form> exec() {};
};