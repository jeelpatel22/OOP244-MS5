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



#include "Book.h"

#include <iostream>

#include <cstring>

#include <iomanip>



namespace sdds

{

    Book::Book() : Publication()

    {

        setBookEmpty();

    }

    Book::~Book()

    {

        delete[] authorName;

    }




    Book::Book(const Book& book) : Publication(book)


    {


        if (authorName)


        {


            delete[] authorName;

            authorName = nullptr;
        }



        authorName = new char[strlen(book.authorName) + 1];


        strcpy(authorName, book.authorName);

    }

    Book& Book::operator=(const Book& book)


    {
        Publication::operator=(book);



        if (authorName)


        {

            delete[] authorName;

            authorName = nullptr;

        }


        if (book.authorName)

        {

            authorName = new char[strlen(book.authorName) + 1];



            strcpy(authorName, book.authorName);

        }


        return *this;

    }


    void Book::setBookEmpty()


    {

        authorName = nullptr;

    }


    char Book::type() const
    {

        return 'B';

    };


    std::ostream& Book::write(std::ostream& os) const


    {



        Publication::write(os);

        if (conIO(os))


        {

            char author[SDDS_AUTHOR_WIDTH + 1] = { 0 };

            std::strncpy(author, authorName, SDDS_AUTHOR_WIDTH);

            os << " ";

            os << std::setw(SDDS_AUTHOR_WIDTH) << std::left << std::setfill(' ') << author << " |";
        }

        else

        {

            os << "\t" << authorName;

        }

        return os;


    }


    std::istream& Book::read(std::istream& is)


    {
        char authName[256] = { 0 };


        Publication::read(is);

        if (authorName)

        {

            delete[] authorName;

            authorName = nullptr;

        }

        if (conIO(is))

        {

            is.ignore();

            std::cout << "Author: ";

        }
        else

        {

            is.ignore(1000, '\t');

        }

        is.get(authName, 256);

        if (is)


        {

            authorName = new char[strlen(authName) + 1];

            strcpy(authorName, authName);
        }


        return is;

    }






    void Book::set(int member_id)



    {
        Publication::set(member_id);

        Publication::resetDate();
    }



    Book::operator bool() const

    {

        return authorName && Publication::operator bool();


    }

}