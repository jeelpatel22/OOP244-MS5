/*
Final Project Milestone 1

Version 1.0
Author	:Jeelkumar Vinodkumar Patel
Email: jpatel391@myseneca.ca
Student ID: 115766222
Revision History
---------------------------------------------------------- -
Date      Reason
2023 / 08 / 06
---------------------------------------------------------- -
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
---------------------------------------------------------- -
*/





#include <iostream>
using namespace std;
#include "Utils.h"

namespace sdds
{
    int getIntegerInput(int minRange, int maxRange, const char* message) {
        int input;
        bool validInt = false;
        while (validInt == false)
        {
            cin >> input;
            if (!cin || input < minRange || input > maxRange)
            {
                std::cout << message;
                cin.clear();
                cin.ignore(1000, '\n');
                validInt = false;
            }
            else
            {
                validInt = true;
            }

        }
        return input;
    }
}