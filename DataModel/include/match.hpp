#pragma once
#include "user.hpp"
#include <string>
#include <vector>
#include "form.hpp"

class Match {
private:
    unsigned id;
    unsigned form1_id;
    unsigned form2_id;
    bool type;
public:
    Match (unsigned _f1, unsigned _f2, bool _type) : form1_id(_f1), form2_id(_f2), type(_type) {}; 
    Match () {}
    unsigned getId(){return id;};
    unsigned getForm1Id(){return form1_id;}
    unsigned getForm2Id() {return form2_id;}
    bool getType() {return type;};   
};