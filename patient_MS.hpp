#include<bits/stdc++.h>
#include"patient_info.hpp"
#include"linked_list.hpp"
#include"queue.hpp"
using namespace std;

class PMS {
public:
    m_queue<patient> OPD_CheckIn;
    m_queue<patient> OPD_CheckOut;
    linked_list<patient> Admitted_Patients;

    PMS(){
        Admitted_Patients.appends(
            patient("Arun Kumar", 34, 1), 
            patient("Manish Thakur", 48, 1)
        );
        OPD_CheckIn.enque(
            patient("Shreya Kumari", 29)
        );
    }
};

bool bool_option(){
    string opt{};
    print("\n\e[1;33mAre you sure about this Action (Y or N):\e[0m ");
    cin >> opt;
    if(opt == "Y" || opt == "Yes" || opt == "y"){ return true;}
    return false;
}