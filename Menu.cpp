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

#include "Menu.h"


#include "Utils.h"

#include <cstring>


namespace sdds {

    MenuItem::MenuItem()
    {

        setEmpty();
    }



    MenuItem::MenuItem(const char* textContent) {

        if (textContent && textContent[0]) {


            menuContent = new char[strlen(textContent) + 1];


            strcpy(menuContent, textContent);
        }





        else {
            setEmpty();


        }
    }




    MenuItem::~MenuItem() {

        delete[] menuContent;
    }





    void MenuItem::setEmpty() {
        menuContent = nullptr;

    }



    MenuItem::operator bool() const {
        return (menuContent && menuContent[0]);


    };




    MenuItem::operator const char* () const {

        return menuContent;
    }



    std::ostream& MenuItem::display(std::ostream& os) {


        if (*this) {

            os << menuContent;
        }




        return os;

    }


    Menu::Menu() {

        pointerCount = 0;
    };

    Menu::Menu(const char* title) : menuTitle(title) {};


    Menu::~Menu() {

        unsigned int i;

        for (i = 0; i < MAX_MENU_ITEMS; i++)
        {

            delete menuItems[i];

        }
    };


    std::ostream& Menu::displayMenuTitle(std::ostream& os) {

        if (menuTitle) {

            menuTitle.display();
        }



        return os;


    }


    std::ostream& Menu::displayMenu(std::ostream& os) {

        if (menuTitle)

        {

            menuTitle.display();

            os << std::endl;
        }



        unsigned int i;

        for (i = 0; i < pointerCount; i++)
        {

            os.width(2);

            os.setf(std::ios::right);

            os.fill(' ');

            os << i + 1 << "- ";


            os.unsetf(std::ios::right);



            menuItems[i]->display(os);

            os << std::endl;
        }

        os << " 0- Exit" << std::endl;

        os << "> ";

        return os;
    }

    Menu::operator int() {
        return pointerCount;
    }

    Menu::operator unsigned int() {
        return pointerCount;
    }

    Menu::operator bool() {
        return (pointerCount > 0);
    }

    std::ostream& operator<<(std::ostream& os, Menu& menu) {
        return (menu.displayMenuTitle(os));
    }

    int Menu::run() {
        int user_input;
        displayMenu();
        user_input = getIntegerInput(0, pointerCount);
        return user_input;
    }

    int Menu::operator~() {
        return run();
    }

    Menu& Menu::operator<<(const char* menuitemContent) {
        if (pointerCount < MAX_MENU_ITEMS)
        {
            MenuItem* newMenuItem = new MenuItem(menuitemContent);
            menuItems[pointerCount] = newMenuItem;
            pointerCount++;
        }

        return *this;
    }

    const char* Menu::operator[](unsigned int index) const {
        if (index > pointerCount)
        {
            return menuItems[index %= pointerCount]->menuContent;
        }
        else
        {
            return menuItems[index]->menuContent;
        }
    }
};