#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

extern int st_counter;
extern int sj_counter;

struct ModuleRecord;

std::string tolower(std::string s);

struct Student {
    std::string name {};
    std::string surname {};
    int id = ++st_counter;

    void print () const;
    bool operator<(const Student& other) const;
    bool operator== (const Student& other) const;
};

void st_search (const std::string& keyword);
void add_st (const std::string& name, const std::string& surname);
void remove_st (const Student& ex);
bool sortBySurname(const Student &lhs, const Student &rhs);
void print_st_list ();

struct Subject {
    std::string title{};
    int id = ++sj_counter;

    void print () const;
};

void sj_search(const std::string& keyword);
void add_sj(const std::string& title);
void print_sj_list ();

struct ModuleRecord {
    int st_id = 0;
    int sj_id = 0;
    int mark = 0;

    void print () const;
};

void add_mark (const int& st_id, const int& sj_id, const int& mark);
void print_my_marks (const int& st_id);
void print_my_alumni(const int& sj_id);

void intro ();
void menu ();
void st_DB();
void sj_DB ();
void marks_DB ();




