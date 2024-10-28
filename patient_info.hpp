#include<bits/stdc++.h>
#include"linked_list.hpp"
using namespace std;

struct patient : public hasId {
    unsigned int pid{};
    string name{};
    unsigned int age{};
    bool admitted{ false };
    unsigned int file_id{};
    static int gen_id, gen_file_id;

    patient() {
        print("\nEnter Patient Details:\nName: \e[1;38;2;110;100;230m");
        cin >> name;
        print("\e[0;30mAge: \e[1;38;2;110;100;230m");
        cin >> age;
        print("\e[0;30m");
        pid = ++gen_id;
    }
    patient(string p_name, int p_age) :name(p_name), age(p_age) {
        pid = ++gen_id;
    }
    patient(string p_name, int p_age, int check) :
        name(p_name), age(p_age) {
        admitted = true;
        pid = ++gen_id;
        file_id = ++gen_file_id;
    }

    void set_admitted() { admitted = true; file_id = ++gen_file_id; }
    void discharge() { admitted = false; }

    void print_info_short() { std::print("ID: {}  Name: {}", pid, name); }

    int getId() const override { return pid; }
};
int patient::gen_id = 0;
int patient::gen_file_id = 1000;

ostream& operator<<(ostream& out, patient obj) {
    println("\n\nPatient Details:\n\e[1;3;38;2;70;90;170m\
    \tID:           {}\n\
    \tName:         {}\n\
    \tAge:          {}\n\
    \tIs Admitted:  {}\n\
    \tFile ID:      {}\e[0;30m",
        obj.pid, obj.name, obj.age, obj.admitted, obj.file_id);
    return out;
}

