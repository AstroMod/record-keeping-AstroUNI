#include <iostream>
#include "astroUNI_f.hpp"

int main() {

    st_DB();
    sj_DB ();
    marks_DB();

main_menu: //label for the goto as a "return to main menu"

    intro ();
    menu ();

    int choice = 0;
    std::cin >> choice;

    switch(choice) {
        case 1 : { //search for a student
            std::string a = "s";
            while (a != "m") {
                std::cout << "Name to search: ";
                std::string keyword;
                std::cin >> keyword;
                st_search(keyword);
                std::cout << "(m) to go back to main menu (any key) for a new search" << std::endl;
                std::cin >> a;
            }
        }
            goto main_menu;
        case 2 : { //add a new student
            std::string a = "s";
            while (a != "m") {
                std::string name;
                std::string surname;
                std::cout << "Name: ";
                std::cin >> name;
                std::cout << "Surname: ";
                std::cin >> surname;
                add_st(name, surname);
                std::cout << "(m) to go back to main menu (any key) to add another student" << std::endl;
                std::cin >> a;
            }
        }
            goto main_menu;
        case 3 : { //search for a subject
            std::string a = "s";
            while (a != "m") {
                std::cout << "Subject to search: ";
                std::string keyword;
                std::cin >> keyword;
                sj_search(keyword);
                std::cout << "(m) to go back to main menu (any key) for a new search" << std::endl;
                std::cin >> a;
            }
        }
            goto main_menu;
        case 4 : { //add a new subject
            std::string a = "s";
            while (a != "m") {
                std::string title;
                std::cout << "Subject: ";
                std::cin >> title;
                add_sj(title);
                std::cout << "(m) to go back to main menu (any key) to add another subject" << std::endl;
                std::cin >> a;
            }
        }
            goto main_menu;
        case 5 : { //print list of students enrolled
            std::string a = "s";
            while (a != "m") {
                print_st_list();
                std::cout << "(m) to go back to main menu (any key) for another print" << std::endl;
                std::cin >> a;
            }
        }
            goto main_menu;
        case 6 : { //print list of subjects offered
            std::string a = "s";
            while (a != "m") {
                print_sj_list();
                std::cout << "(m) to go back to main menu (any key) for another print" << std::endl;
                std::cin >> a;
            }
        }
            goto main_menu;
        case 7 : { //print all result of a student
            std::string a = "s";
            while (a != "m") {
                std::cout << "Student id: ";
                int id;
                std::cin >> id;
                print_my_marks(id);
                std::cout << "(m) to go back to main menu (any key) for a new search" << std::endl;
                std::cin >> a;
            }
        }
            goto main_menu;
        case 8 : { //print all results for a subject
            std::string a = "s";
            while (a != "m") {
                std::cout << "Subject id: ";
                int id;
                std::cin >> id;
                print_my_alumni(id);
                std::cout << "(m) to go back to main menu (any key) for a new search" << std::endl;
                std::cin >> a;
            }
        }
            goto main_menu;
         case 9 : { //exit
            break;
        }
    }
    std::cout << "Exiting...";

    return 0;
}