#include<iostream>
#include"patient_MS.hpp"
// #include"link
using namespace std;

int main() {
    PMS Patient_Man_Sys;
    m_queue<patient>& OPD = Patient_Man_Sys.OPD_CheckIn;
    linked_list<patient>& Adm_P = Patient_Man_Sys.Admitted_Patients;
    Adm_P.println();
    return 0;
}