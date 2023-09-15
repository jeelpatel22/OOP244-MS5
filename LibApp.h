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

#ifndef SDDS_LIBAPP_H

#define SDDS_LIBAPP_H


#include <iostream>

#include "Menu.h"

#include "Lib.h"

#include "Streamable.h"

#include "Publication.h"

#include "Book.h"


namespace sdds

{

    class LibApp

    {
    private:


        bool m_changed;


        Menu m_mainMenu;



        Menu m_exitMenu;



        char m_filename[SDDS_MAX_FILENAME + 1];

        Publication* m_PPA[SDDS_LIBRARY_CAPACITY];

        int m_NOLP;

        int m_LLRN;



        Menu m_publicationType;



        bool confirm(const char* message);





        void load();

        void save();

        int search(int searchType);

        void returnPub();



        void newPublication();

        void removePublication();

        void checkOutPub();

    public:


        LibApp(const char* fileName);

        ~LibApp();

        void run();

        Publication* getPub(int libRef);

    };

}


#endif