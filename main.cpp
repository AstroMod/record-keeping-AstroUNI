#include <iostream>
#include "astroUNI_f.hpp"

int main() {

    st_DB();
    sj_DB ();
    marks_DB();

main_menu: //label for the goto as a "return to main menu"

    intro ();
    menu ();

    int choice = 10;
    std::cin >> choice;

    switch(choice) {
        case 1 : { //search for a student
            std::string a = "s";
            while (a != "m") {
                std::cout << "Name to search: ";
                std::string keyword;
                std::cin >> keyword;
                st_search(keyword);
                std::cout << "[m] to go back to main menu [any key] for a new search" << std::endl;
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
                std::cout << "[m] to go back to main menu [any key] to add another student" << std::endl;
                std::cin >> a;
            }
        }
            goto main_menu;
        case 3 : { //remove a student
            std::string a = "s";
            while (a != "m") {
                std::string name {};
                std::string surname {};
                int id = 0;
                std::cout << "[case sensitive] Name: ";
                std::cin >> name;
                std::cout << "[case sensitive] Surname: ";
                std::cin >> surname;
                std::cout << "Id: ";
                std::cin >> id;
                Student st {name, surname, id};
                remove_st(st);
                std::cout << "[m] to go back to main menu [any key] to remove another student" << std::endl;
                std::cin >> a;
            }
        }
            goto main_menu;
        case 6 : { //add a new subject
            std::string a = "s";
            while (a != "m") {
                std::string title;
                std::cout << "Subject: ";
                std::cin >> title;
                add_sj(title);
                std::cout << "[m] to go back to main menu [any key] to add another subject" << std::endl;
                std::cin >> a;
            }
        }
            goto main_menu;
        case 7 : { //add new results
            std::string a = "s";
            while (a != "m") {
                int st_id {}, sj_id {}, mark {};
                std::cout << "Student id: ";
                std::cin >> st_id;
                std::cout << "Subject id: ";
                std::cin >> sj_id;
                std::cout << "Mark: ";
                std::cin >> mark;
                add_mark(st_id, sj_id, mark);
                std::cout << "[m] to go back to main menu [any key] to add another subject" << std::endl;
                std::cin >> a;
            }
        }
            goto main_menu;
        case 4 : { //view list of students enrolled
            std::string a = "s";
            while (a != "m") {
                print_st_list();
                std::cout << "[m] to go back to main menu [any key] for another print" << std::endl;
                std::cin >> a;
            }
        }
            goto main_menu;
        case 5 : { //view list of subjects offered
            std::string a = "s";
            while (a != "m") {
                print_sj_list();
                std::cout << "[m] to go back to main menu [any key] for another print" << std::endl;
                std::cin >> a;
            }
        }
            goto main_menu;
        case 9 : { //view all marks of a student
            std::string a = "s";
            while (a != "m") {
                std::cout << "Student id: ";
                int id;
                std::cin >> id;
                print_my_marks(id);
                std::cout << "[m] to go back to main menu [any key] for a new search" << std::endl;
                std::cin >> a;
            }
        }
            goto main_menu;
        case 8 : { //view all results for a subject
            std::string a = "s";
            while (a != "m") {
                std::cout << "Subject id: ";
                int id;
                std::cin >> id;
                print_my_alumni(id);
                std::cout << "[m] to go back to main menu [any key] for a new search" << std::endl;
                std::cin >> a;
            }
        }
            goto main_menu;
        case 0 : { //exit
            break;
        }
    }
    std::cout << "Exiting...";

    return 0;
}