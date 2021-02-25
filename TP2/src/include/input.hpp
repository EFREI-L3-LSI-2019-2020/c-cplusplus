#ifndef __INPUT_H__
#define __INPUT_H__

#include <iostream>
#include <string>
#include <stdbool.h>
#include <sstream>

namespace Input
{
    template< typename T>
    std::istream& read(std::istream &istr, T &val)
    {
        std::string s;
        std::getline(istr, s);

        if (istr.good()) 
        {
            std::stringstream iss(s);

            if (!(iss >> val))
            {
                istr.setstate(std::ios::failbit);
            }
        }

        return istr;
    }

    //Sécuration de l'input
    template<typename T>
    void input(std::string str, T &data)
    {
        for(;;)
        {
            std::cout << str;

            if(read<T>(std::cin, data))
            {
                break;
            }

            std::cin.clear();
        }   
    }

    void input(std::string str, std::string &data)
    {
        std::cout << str;

        std::string s;
        std::getline(std::cin, s);

        std::stringstream iss(s);
        data = iss.str();
    }
}

#endif