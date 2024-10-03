#include "Utility.h"
#include <string>

typedef std::string String;

Utility::String Utility::truncateLeftLine(const std::string& str, int maxLength) 
{
    if (str.length() > maxLength) {
        return "..." + str.substr(str.length() - (maxLength - 3));
    }
return str;
}

Utility::String Utility::truncateRightLine(const std::string& str, int maxLength) 
{
    if (str.length() > maxLength) {
        return str.substr(0, maxLength - 3) + "...";
    }
    return str; 
}