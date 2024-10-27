#include<bits/stdc++.h>
using namespace std;

struct patient {
    unsigned int pid{};
    string name{};
    unsigned int age{};
    bool admitted{ false };
    unsigned int file_id{};
    static int gen_id, gen_file_id;

    patient() {
        print("Enter Patient Details:\nName: ");
        cin >> name;
        print("Age: ");
        cin >> age;
        pid = ++gen_id;
    }
    patient(string p_name, int p_age) :name(p_name), age(p_age) {
        pid = ++gen_id;
    }
    patient(string p_name, int p_age, int check) :
        name(p_name), age(p_age){
        admitted = true;
        pid = ++gen_id;
        file_id = ++gen_file_id;
    }

    void set_admitted() { admitted = true; file_id = ++gen_file_id; }
    void discharge() { admitted = false; }
};
int patient::gen_id = 0;
int patient::gen_file_id = 1000;

ostream& operator<<(ostream& out, patient obj) {
    println("\nPatient Details:\n\e[1;3;36m\
    \tID:           {}\n\
    \tName:         {}\n\
    \tAge:          {}\n\
    \tIs Admitted:  {}\n\
    \tFile ID:      {}\e[0;37m",
        obj.pid, obj.name, obj.age, obj.admitted, obj.file_id);
    return out;
}
