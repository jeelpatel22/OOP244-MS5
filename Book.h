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

#ifndef SDDS_BOOK_H


#define SDDS_BOOK_H


#include "Publication.h"




namespace sdds


{
    class Book : public Publication

    {

    private:


        char* authorName;


    public:

        Book();

        ~Book();


        Book(const Book& book);


        Book& operator=(const Book& book);

        void setBookEmpty();


        char type() const;


        std::ostream& write(std::ostream& os) const;


        std::istream& read(std::istream& is);



        virtual void set(int member_id);


        operator bool() const;


    };

}

#endif 
