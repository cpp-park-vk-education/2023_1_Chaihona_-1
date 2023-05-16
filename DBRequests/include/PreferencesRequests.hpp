#include "preference.hpp"

class PreferencesRequests{
private:
    unsigned formId;
public:
    PreferencesRequests(unsigned _fid): formId(_fid) {}
    Preference getUserPreferences();    
};