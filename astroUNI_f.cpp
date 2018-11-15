#include "astroUNI_f.hpp"

int st_counter = 0;
int sj_counter = 0;
std::vector<Student> st_list {};
std::vector<Subject> sj_list {};
std::vector<ModuleRecord> st_X_sj {};

std::string tolower(std::string s) {
    std::transform(s.begin(), s.end(), s.begin(),
                   [](unsigned char c){ return std::tolower(c); } // correct
    );
    return s;
}

bool Student::operator<(const Student& other) const {
    return tolower(surname) < tolower(other.surname); // order by name
}

bool Student::operator== (const Student& other) const {
    return this->name == other.name && this->surname == other.surname && this->id == other.id;
}

void st_search (const std::string& keyword) {
    std::cout << "Searching...\n";
    for (Student st : st_list){
        if (tolower(st.name).find(tolower(keyword)) != std::string::npos || tolower(st.surname).find(tolower(keyword)) != std::string::npos) {
            st.print();
        } else continue;
    }
    std::cout << "Finished\n";
}

void sj_search (const std::string& keyword) {
    std::cout << "Searching...\n";
    for (Subject sj : sj_list){
        if (tolower(sj.title).find(tolower(keyword)) != std::string::npos) {
            sj.print();
        } else continue;
    }
    std::cout << "Finished\n";
}

void add_st (const std::string& name, const std::string& surname) {
    Student st {name, surname};
    st_list.push_back(st);
}

void add_sj (const std::string& title) {
    Subject sj {title};
    sj_list.push_back(sj);
}

void add_mark (const int& st_id, const int& sj_id, const int& mark) {
    ModuleRecord mr {st_id, sj_id, mark};
    st_X_sj.push_back(mr);
}

void remove_st (const Student& ex) {
    for (std::vector<Student>::iterator it = st_list.begin(), end = st_list.end(); it != end; ++it) {
        if (ex == *it) {
            std::string del = "0";
            ex.print();
            std::cout << "\n Record found, (yes) to confirm delete";
            std::cin >> del;
            if (del == "yes") {
                st_list.erase(it);
            } else return;
            break;
        } else continue;
    }
}

void Student::print () const {
    std::cout << this->id << ".\t" << this->name << "\t\t" << this->surname << std::endl;
}

void Subject::print () const {
    std::cout << this->id << ".\t" << this->title << std::endl;
}

void ModuleRecord::print () const {
    std::cout << "Student: " << this->st_id << "\t" << "Subject: " << this->sj_id << "\t" << "Mark: " << this->mark << std::endl;
}

bool sortBySurname(const Student &lhs, const Student &rhs) {
    return lhs < rhs;
}

void print_st_list () {
    std::sort(st_list.begin(), st_list.end(), sortBySurname);
    for (Student& st : st_list){
        st.print();
    }
}

void print_sj_list () {
    for (Subject& sj : sj_list) {
        sj.print();
    }
}

//print st x sj
void print_my_marks(const int& st_id) {
    std::cout << "Student: " << st_id << "\t" << " Exams:" << std::endl;
    for (ModuleRecord mr : st_X_sj) {
        if (mr.st_id == st_id) {
            std::cout << "\t Subject: " << mr.sj_id << "\t Mark: " << mr.mark << std::endl;
        } else continue;
    }
}

//print sj x st
void print_my_alumni(const int& sj_id) {
    std::cout << "Subject: " << sj_id << "\t" << "Students:" << std::endl;
    for (ModuleRecord mr : st_X_sj) {
        if (mr.sj_id == sj_id) {
            std::cout << "\t Student: " << mr.st_id << "\t Mark: " << mr.mark << std::endl;
        } else continue;
    }

}

void intro () {
    std::cout
            << "d8888          888                    888     888 888b    888 8888888" << std::endl
            << "d88888          888                    888     888 8888b   888   888" << std::endl
            << "d88P888          888                    888     888 88888b  888   888" << std::endl
            << "d88P 888 .d8888b  888888 888d888 .d88b.  888     888 888Y88b 888   888" << std::endl
            << "d88P  888 88K      888    888P'  d88''88b 888     888 888 Y88b888   888" << std::endl
            << "d88P   888 'Y8888b. 888    888    888  888 888     888 888  Y88888   888" << std::endl
            << "d8888888888      X88 Y88b.  888    Y88..88P Y88b. .d88P 888   Y8888   888" << std::endl
            << "d88P     888  88888P'  'Y888 888     'Y88P'   'Y88888P'  888    Y888 8888888" << std::endl
            << std::endl;
}

void menu () {
    std::cout << "Menu" << std::endl;
    std::cout << "1. Search for a student" << std::endl;
    std::cout << "2. Add a new student" << std::endl;
    std::cout << "3. Remove a student" << std::endl;
    std::cout << "4. View list of student enrolled" << std::endl;
    std::cout << "5. View list of subjects offered" << std::endl;
    std::cout << "6. Add a new subject" << std::endl;
    std::cout << "7. Add new results" << std::endl;
    std::cout << "8. View all results for a subject" << std::endl;
    std::cout << "9. view all marks of a student" << std::endl;
    std::cout << "0. Exit" << std::endl;
}

void st_DB() {
    add_st("Aarya","Ace");
    add_st("Addison","ChaKu");
    add_st("Alby","Eddie");
    add_st("Alex","jewulo");
    add_st("Alexis","Lee");
    add_st("Ali","Mohammed Obad");
    add_st("Angel","Orlando Brown");
    add_st("Archer","sangulele");
    add_st("Arya","varriola");
    add_st("Ashley","adamnemecek");
    add_st("Atom","AstroBot");
    add_st("Aubrey","asmcoder110");
    add_st("Austin","Bhaskar");
    add_st("Avery","bhavik");
    add_st("Bailey","bluefrog");
    add_st("Billy","Bojan Komazec");
    add_st("Blair","bot2.0");
    add_st("Bobby","BroVic");
    add_st("Brady","Bubberzz");
    add_st("Brook","Carlo");
    add_st("Carmen","charley");
    add_st("Casey","claudio");
    add_st("Cassidy","Colin Newell");
    add_st("Celyn","coudrew");
    add_st("Charlie","daniel_sys");
    add_st("Cody","davidps");
    add_st("Corey","Dean Moon");
    add_st("Dakota","Deveroux");
    add_st("Dannie","drastorguev");
    add_st("Darryl","duliqiang");
    add_st("Devon","Elena Lestini");
    add_st("Drew","eoin");
    add_st("Dylan","G");
    add_st("Eden","g33kyaditya");
    add_st("Eli","Gerry McGarry");
    add_st("Ellery","goeddek");
    add_st("Emery","herrwarum");
    add_st("Erin","Horace");
    add_st("Fabian","hosilva");
    add_st("Finley","Ivor");
    add_st("Florian","jonkalb");
    add_st("Flynn","JonnyCplusplus");
    add_st("Francis","JunBau");
    add_st("Frankie","junjchen");
    add_st("Glen","Karwoo");
    add_st("Gray","Kash");
    add_st("Hadley","krvajal");
    add_st("Harley","Kupad");
    add_st("Harper","Laura Enria");
    add_st("Hayden","lbtech");
    add_st("Hero","Lewis Cowles");
    add_st("Hunter","luisnuxx");
    add_st("Indiana","LukaP");
    add_st("Jade","lukmdo");
    add_st("Jamie","Mabel");
    add_st("Jesse","malar1510");
    add_st("Jordan","marco");
    add_st("Jules","Matt Spear");
    add_st("Justice","Matt_Alexander");
    add_st("Kadin","Maverick");
    add_st("Keegan","MikeH");
    add_st("Kelly","milkomeda73");
    add_st("Kendall","moondt");
    add_st("Kennedy","Narayan");
    add_st("Kerry","nevin");
    add_st("Lane","Nick White");
    add_st("Lee","NK");
    add_st("Linden","Nori");
    add_st("Logan","Oceane");
    add_st("London","Olipro");
    add_st("Lonnie","OneManArmy");
    add_st("Lucian","phil");
    add_st("Lumi","Patrick Pilgrim");
    add_st("River","philsquared");
    add_st("Madison","Phil-ZXX");
    add_st("Marley","pkc-Harry");
    add_st("Micah","prokbird");
    add_st("Montana","Rakete1111");
    add_st("Morgan","Richard Thorell");
    add_st("Moriah","Saad Rathore");
    add_st("Nevada","salvatorepreviti");
    add_st("Nico","Scott");
    add_st("Noel","Sen");
    add_st("Oakley","simon");
    add_st("Ode","Sinead Nic Fheorais");
    add_st("Ore","Some Guy");
    add_st("Paris","Steve");
    add_st("Parker","StewMH");
    add_st("Perrie","tcynth");
    add_st("Peyton","tcbrindle");
    add_st("Phoenix","VectorAlpha");
    add_st("Piper","tuxfede");
    add_st("Quinn","vialactea73");
    add_st("Raphael","vicky");
    add_st("Reagan","xxvms");
    add_st("Reese","Yjt");
    add_st("Riley","Zam");
    add_st("Rowan","Adele");
    add_st("Sage","Adrian.K");
    add_st("Sam","AK");
    add_st("Samar","Akrem");
    add_st("Scout","akshit-sharma");
    add_st("Skye","alex_a");
    add_st("Sunny","alex_brown");
    add_st("Sydney","alexn");
    add_st("Taylor","Andy");
    add_st("Teri","Antonio Coppola");
    std::cout << "st_DB initislised" << "\n";
}

void sj_DB () {
    add_sj("C++");
    add_sj("Python");
    add_sj("C#");
    add_sj("Java");
    add_sj("JavaScript");
    add_sj("Pearl");
    add_sj("Pascal");
    add_sj("PHP");
    add_sj("HTML");
    add_sj("CSS");
    add_sj("Ruby");
    std::cout << "sj_DB initislised" << "\n";
}

void marks_DB () {
    add_mark (17,1,10);
    add_mark (39,1,10);
    add_mark (46,1,10);
    add_mark (50,1,10);
    add_mark (76,1,10);
    add_mark (99,1,10);
    add_mark (6,1,9);
    add_mark (7,1,9);
    add_mark (33,1,9);
    add_mark (34,1,9);
    add_mark (36,1,9);
    add_mark (45,1,9);
    add_mark (57,1,9);
    add_mark (89,1,9);
    add_mark (92,1,9);
    add_mark (97,1,9);
    add_mark (102,1,9);
    add_mark (8,1,8);
    add_mark (10,1,8);
    add_mark (15,1,8);
    add_mark (21,1,8);
    add_mark (25,1,8);
    add_mark (51,1,8);
    add_mark (58,1,8);
    add_mark (63,1,8);
    add_mark (67,1,8);
    add_mark (68,1,8);
    add_mark (70,1,8);
    add_mark (72,1,8);
    add_mark (98,1,8);
    add_mark (5,1,7);
    add_mark (12,1,7);
    add_mark (18,1,7);
    add_mark (37,1,7);
    add_mark (47,1,7);
    add_mark (56,1,7);
    add_mark (61,1,7);
    add_mark (65,1,7);
    add_mark (71,1,7);
    add_mark (77,1,7);
    add_mark (83,1,7);
    add_mark (85,1,7);
    add_mark (86,1,7);
    add_mark (91,1,7);
    add_mark (94,1,7);

    add_mark (10,2,10);
    add_mark (5,2,10);
    add_mark (18,2,10);
    add_mark (1,2,10);
    add_mark (2,2,10);
    add_mark (11,2,10);
    add_mark (22,2,10);
    add_mark (53,2,10);
    add_mark (64,2,10);
    add_mark (79,2,10);
    add_mark (93,2,10);
    add_mark (96,2,10);
    add_mark (101,2,10);
    add_mark (104,2,10);
    add_mark (97,2,9);
    add_mark (15,2,9);
    add_mark (70,2,9);
    add_mark (47,2,9);
    add_mark (9,2,9);
    add_mark (42,2,9);
    add_mark (106,2,9);
    add_mark (39,2,8);
    add_mark (46,2,8);
    add_mark (33,2,8);
    add_mark (12,2,8);
    add_mark (27,2,8);
    add_mark (38,2,8);
    add_mark (48,2,8);
    add_mark (60,2,8);
    add_mark (107,2,8);
    add_mark (45,2,7);
    add_mark (67,2,7);
    add_mark (98,2,7);
    add_mark (61,2,7);
    add_mark (16,2,7);
    add_mark (19,2,7);
    add_mark (40,2,7);
    add_mark (55,2,7);
    add_mark (95,2,7);

    add_mark (93,3,10);
    add_mark (16,3,10);
    add_mark (86,3,10);
    add_mark (31,3,10);
    add_mark (53,3,9);
    add_mark (48,3,9);
    add_mark (45,3,9);
    add_mark (95,3,9);
    add_mark (37,3,9);
    add_mark (35,3,9);
    add_mark (43,3,9);
    add_mark (75,3,9);
    add_mark (80,3,9);
    add_mark (103,3,9);
    add_mark (22,3,8);
    add_mark (64,3,8);
    add_mark (101,3,8);
    add_mark (15,3,8);
    add_mark (47,3,8);
    add_mark (107,3,8);
    add_mark (92,3,8);
    add_mark (51,3,8);
    add_mark (68,3,8);
    add_mark (77,3,8);
    add_mark (91,3,8);
    add_mark (28,3,8);
    add_mark (29,3,8);
    add_mark (82,3,8);
    add_mark (105,3,8);
    add_mark (96,3,7);
    add_mark (9,3,7);
    add_mark (38,3,7);
    add_mark (67,3,7);
    add_mark (98,3,7);
    add_mark (40,3,7);
    add_mark (55,3,7);
    add_mark (76,3,7);
    add_mark (36,3,7);
    add_mark (57,3,7);
    add_mark (20,3,7);
    add_mark (30,3,7);
    add_mark (41,3,7);
    add_mark (54,3,7);
    add_mark (59,3,7);
    add_mark (81,3,7);

    add_mark (31,4,10);
    add_mark (64,4,10);
    add_mark (51,4,10);
    add_mark (77,4,10);
    add_mark (91,4,10);
    add_mark (28,4,10);
    add_mark (76,4,10);
    add_mark (27,4,10);
    add_mark (58,4,10);
    add_mark (65,4,10);
    add_mark (3,4,10);
    add_mark (23,4,10);
    add_mark (47,4,9);
    add_mark (107,4,9);
    add_mark (105,4,9);
    add_mark (34,4,9);
    add_mark (56,4,9);
    add_mark (14,4,9);
    add_mark (100,4,9);
    add_mark (15,4,8);
    add_mark (96,4,8);
    add_mark (9,4,8);
    add_mark (55,4,8);
    add_mark (1,4,8);
    add_mark (17,4,8);
    add_mark (72,4,8);
    add_mark (86,4,7);
    add_mark (75,4,7);
    add_mark (92,4,7);
    add_mark (68,4,7);
    add_mark (67,4,7);
    add_mark (57,4,7);
    add_mark (12,4,7);
    add_mark (83,4,7);
    add_mark (85,4,7);
    add_mark (26,4,7);
    add_mark (32,4,7);

    add_mark (76,5,10);
    add_mark (58,5,10);
    add_mark (105,5,10);
    add_mark (83,5,10);
    add_mark (95,5,10);
    add_mark (20,5,10);
    add_mark (8,5,10);
    add_mark (66,5,10);
    add_mark (47,5,9);
    add_mark (100,5,9);
    add_mark (55,5,9);
    add_mark (67,5,9);
    add_mark (26,5,9);
    add_mark (37,5,9);
    add_mark (70,5,9);
    add_mark (106,5,9);
    add_mark (28,5,8);
    add_mark (3,5,8);
    add_mark (23,5,8);
    add_mark (15,5,8);
    add_mark (9,5,8);
    add_mark (29,5,8);
    add_mark (82,5,8);
    add_mark (5,5,8);
    add_mark (42,5,8);
    add_mark (69,5,8);
    add_mark (84,5,8);
    add_mark (14,5,7);
    add_mark (72,5,7);
    add_mark (68,5,7);
    add_mark (12,5,7);
    add_mark (101,5,7);
    add_mark (11,5,7);
    add_mark (79,5,7);
    add_mark (97,5,7);
    add_mark (46,5,7);
    add_mark (60,5,7);
    add_mark (99,5,7);
    add_mark (7,5,7);
    add_mark (24,5,7);
    add_mark (49,5,7);

    add_mark (95,6,10);
    add_mark (5,6,10);
    add_mark (12,6,10);
    add_mark (56,6,10);
    add_mark (57,6,10);
    add_mark (35,6,10);
    add_mark (80,6,10);
    add_mark (40,6,10);
    add_mark (10,6,10);
    add_mark (71,6,10);
    add_mark (90,6,10);
    add_mark (97,6,9);
    add_mark (96,6,9);
    add_mark (17,6,9);
    add_mark (30,6,9);
    add_mark (81,6,9);
    add_mark (87,6,9);
    add_mark (58,6,8);
    add_mark (100,6,8);
    add_mark (67,6,8);
    add_mark (42,6,8);
    add_mark (72,6,8);
    add_mark (46,6,8);
    add_mark (60,6,8);
    add_mark (1,6,8);
    add_mark (75,6,8);
    add_mark (32,6,8);
    add_mark (98,6,8);
    add_mark (54,6,8);
    add_mark (50,6,8);
    add_mark (94,6,8);
    add_mark (88,6,8);
    add_mark (83,6,7);
    add_mark (31,6,7);
    add_mark (64,6,7);
    add_mark (91,6,7);
    add_mark (85,6,7);
    add_mark (16,6,7);
    add_mark (48,6,7);
    add_mark (103,6,7);
    add_mark (19,6,7);
    add_mark (89,6,7);
    add_mark (62,6,7);
    add_mark (73,6,7);

    add_mark (11,7,10);
    add_mark (22,7,10);
    add_mark (23,7,10);
    add_mark (25,7,10);
    add_mark (27,7,10);
    add_mark (30,7,10);
    add_mark (37,7,10);
    add_mark (50,7,10);
    add_mark (78,7,10);
    add_mark (82,7,10);
    add_mark (98,7,10);
    add_mark (5,7,9);
    add_mark (14,7,9);
    add_mark (24,7,9);
    add_mark (44,7,9);
    add_mark (58,7,9);
    add_mark (63,7,9);
    add_mark (84,7,9);
    add_mark (88,7,9);
    add_mark (102,7,9);
    add_mark (17,7,8);
    add_mark (35,7,8);
    add_mark (56,7,8);
    add_mark (59,7,8);
    add_mark (60,7,8);
    add_mark (85,7,8);
    add_mark (97,7,8);
    add_mark (101,7,8);
    add_mark (3,7,7);
    add_mark (28,7,7);
    add_mark (66,7,7);
    add_mark (87,7,7);
    add_mark (90,7,7);
    add_mark (95,7,7);
    add_mark (106,7,7);

    add_mark (29,8,10);
    add_mark (31,8,10);
    add_mark (32,8,10);
    add_mark (33,8,10);
    add_mark (50,8,10);
    add_mark (61,8,10);
    add_mark (63,8,10);
    add_mark (67,8,10);
    add_mark (69,8,10);
    add_mark (75,8,10);
    add_mark (77,8,10);
    add_mark (87,8,10);
    add_mark (89,8,10);
    add_mark (92,8,10);
    add_mark (102,8,10);
    add_mark (104,8,10);
    add_mark (15,8,9);
    add_mark (21,8,9);
    add_mark (24,8,9);
    add_mark (48,8,9);
    add_mark (65,8,9);
    add_mark (66,8,9);
    add_mark (83,8,9);
    add_mark (103,8,9);
    add_mark (106,8,9);
    add_mark (2,8,8);
    add_mark (17,8,8);
    add_mark (34,8,8);
    add_mark (55,8,8);
    add_mark (86,8,8);
    add_mark (91,8,8);
    add_mark (100,8,8);
    add_mark (1,8,7);
    add_mark (7,8,7);
    add_mark (14,8,7);
    add_mark (39,8,7);
    add_mark (41,8,7);
    add_mark (56,8,7);
    add_mark (62,8,7);
    add_mark (68,8,7);
    add_mark (73,8,7);
    add_mark (78,8,7);
    add_mark (94,8,7);

    add_mark (1,9,10);
    add_mark (6,9,10);
    add_mark (7,9,10);
    add_mark (14,9,10);
    add_mark (24,9,10);
    add_mark (27,9,10);
    add_mark (45,9,10);
    add_mark (59,9,10);
    add_mark (74,9,10);
    add_mark (84,9,10);
    add_mark (95,9,10);
    add_mark (100,9,10);
    add_mark (25,9,9);
    add_mark (28,9,9);
    add_mark (37,9,9);
    add_mark (38,9,9);
    add_mark (40,9,9);
    add_mark (42,9,9);
    add_mark (80,9,9);
    add_mark (90,9,9);
    add_mark (93,9,9);
    add_mark (96,9,9);
    add_mark (9,9,8);
    add_mark (16,9,8);
    add_mark (22,9,8);
    add_mark (32,9,8);
    add_mark (36,9,8);
    add_mark (47,9,8);
    add_mark (51,9,8);
    add_mark (94,9,8);
    add_mark (104,9,8);
    add_mark (105,9,8);
    add_mark (10,9,7);
    add_mark (29,9,7);
    add_mark (79,9,7);
    add_mark (101,9,7);

    add_mark (12,10,10);
    add_mark (37,10,10);
    add_mark (38,10,10);
    add_mark (41,10,10);
    add_mark (48,10,10);
    add_mark (52,10,10);
    add_mark (60,10,10);
    add_mark (71,10,10);
    add_mark (78,10,10);
    add_mark (98,10,10);
    add_mark (107,10,10);
    add_mark (5,10,9);
    add_mark (16,10,9);
    add_mark (43,10,9);
    add_mark (68,10,9);
    add_mark (73,10,9);
    add_mark (74,10,9);
    add_mark (79,10,9);
    add_mark (82,10,9);
    add_mark (85,10,9);
    add_mark (9,10,8);
    add_mark (15,10,8);
    add_mark (28,10,8);
    add_mark (32,10,8);
    add_mark (45,10,8);
    add_mark (56,10,8);
    add_mark (57,10,8);
    add_mark (84,10,8);
    add_mark (99,10,8);
    add_mark (103,10,8);
    add_mark (10,10,7);
    add_mark (22,10,7);
    add_mark (51,10,7);
    add_mark (65,10,7);
    add_mark (72,10,7);
    add_mark (94,10,7);

    add_mark (1,11,10);
    add_mark (5,11,10);
    add_mark (24,11,10);
    add_mark (36,11,10);
    add_mark (38,11,10);
    add_mark (44,11,10);
    add_mark (72,11,10);
    add_mark (78,11,10);
    add_mark (84,11,10);
    add_mark (86,11,10);
    add_mark (88,11,10);
    add_mark (90,11,10);
    add_mark (93,11,10);
    add_mark (102,11,10);
    add_mark (42,11,9);
    add_mark (45,11,9);
    add_mark (52,11,9);
    add_mark (57,11,9);
    add_mark (66,11,9);
    add_mark (106,11,9);
    add_mark (14,11,8);
    add_mark (15,11,8);
    add_mark (28,11,8);
    add_mark (35,11,8);
    add_mark (62,11,8);
    add_mark (65,11,8);
    add_mark (95,11,8);
    add_mark (103,11,8);
    add_mark (43,11,7);
    add_mark (67,11,7);
    add_mark (82,11,7);
    add_mark (83,11,7);

    std::cout << "marks_DB initislised" << "\n\n";
}


