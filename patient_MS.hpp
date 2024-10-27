#include<bits/stdc++.h>
#include"patient_info.hpp"
#include"linked_list.hpp"
#include"queue.hpp"
using namespace std;

class PMS {
public:
    m_queue<patient> OPD_CheckIn;
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