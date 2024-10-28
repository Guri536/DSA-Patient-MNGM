#include<bits/stdc++.h>
#include"patient_info.hpp"
#include"linked_list.hpp"
#include"queue.hpp"
#include"UI.hpp"
using namespace std;

class PMS {
public:
    m_queue<patient> OPD_CheckIn;
    m_queue<patient> OPD_CheckOut;
    linked_list<patient> Admitted_Patients;

    PMS() {
        Admitted_Patients.appends(
            patient("Arun Kumar", 34, 1),
            patient("Manish Thakur", 48, 1)
        );
        OPD_CheckIn.enque(
            patient("Shreya Kumari", 29)
        );
    }
};

class PMS_UI : public ANSI_UI {
public:
    string warning_text() {
        return "\e[1;91m";
    }
    string success_text() {
        return "\e[1;32m";
    }
    string error_text() {
        return "\e[1;38;2;243;156;17m";
    }
    string interactive_text() {
        return "\e[1;4;38;2;80;70;200m";
    }
    string interactive_input_text() {
        return "\e[0;38;2;110;100;230m";
    }
    string normal_text() {
        return "\e[0;30m";
    }
    string menu_text() {
        return "\e[1;4;38;2;30;30;90m\e[20G";
    }
    void pause() {
        cout << "\nPress Enter to Contiue...";
        pause_nt();
    }
};

bool bool_option() {
    PMS_UI text_UI(NILL_OBJ);
    string opt{};
    print("\n{}Are you sure about this Action (Y or N):{} ",
        text_UI.error_text(), text_UI.normal_text());
    cin >> opt;
    if (opt == "Y" || opt == "Yes" || opt == "y") { return true; }
    return false;
}

template<typename LIST>
bool is_obj_empty(LIST obj, string message) {
    PMS_UI text_UI(NILL_OBJ);
    if (!obj.is_empty()) { return false; }
    print("\n{}ERROR: {}{}",
        text_UI.error_text(), message, text_UI.normal_text());
    return true;
}
