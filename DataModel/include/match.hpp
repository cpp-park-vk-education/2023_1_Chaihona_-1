#pragma once
#include "user.hpp"
#include <string>
#include <vector>
#include "form.hpp"

class Match {
private:
    unsigned id;
    Form form1;
    Form form2;
    bool type;
public:
    Match (Form _f1, Form _f2, bool _type) : form1(_f1), form2(_f2), type(_type) {}; 
    Match () {}
    unsigned getId(){return id;};
    Form getForm1 (){return form1;}
    Form getForm2() {return form2;}
    bool getType() {return type;};   
};