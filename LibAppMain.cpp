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


#include "LibApp.h"

#include "Date.h"


int main() {

    sdds::sdds_day = 10;

    sdds::sdds_mon = 12;

    sdds::sdds_year = 2021;

    sdds::sdds_test = true;

    sdds::LibApp theApp("LibRecs.txt");

    theApp.run();


    return 0;

}