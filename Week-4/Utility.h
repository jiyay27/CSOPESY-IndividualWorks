#pragma once
#include <iostream>
#include <string>

class Utility
{
public:
    typedef std::string String;

    static Utility& getInstance() {
        static Utility instance;
        return instance;
    }

    static String truncateLeftLine(const String& str, int maxLength);
    static String truncateRightLine(const String& str, int maxLength);
};