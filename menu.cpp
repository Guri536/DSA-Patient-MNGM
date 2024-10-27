#include<iostream>
#include"patient_MS.hpp"
using namespace std;

int main() {
    PMS Patient_Man_Sys;
    m_queue<patient>& OPD = Patient_Man_Sys.OPD_CheckIn;
    linked_list<patient>& Adm_P = Patient_Man_Sys.Admitted_Patients;
    m_queue<patient>& Waiting = Patient_Man_Sys.OPD_CheckOut;

    while (true) {
        int opt{};
        print(
            "\e[1;4;97m\n\n\e[20G::MENU::\n\e[0;37m\
        1. Register New Check-In\n\
        2. Send next In Check-In Queue\n\
        3. Admit from Check-Out Queue\n\
        4. In Queue Patients\n\
        5. Admitted Patients\n\
        0. Exit\n\
        \e[1;4;36mEnter:\e[0;36m "
        );

        cin >> opt;
        while (opt > 5 || opt < 0) {
            print("\e[91m\
        Please Enter A Valid Input:\e[0;36m ");
            cin >> opt;
        }
        print("\e[0;37m");
        if (opt == 0) { break; }

        switch (opt)
        {
        case 1: {
            patient temp;
            cout << "Is this Correct? " << temp;
            if (bool_option()) {
                OPD.enque(temp);
            }
            break;
        }

        case 2: {
            if (OPD.is_empty()) {
                print("\nCheck-In Queue is Empty");
                break;
            }
            print("\nSending next Patient:\n");
            patient temp = *OPD.deque();
            temp.print_info_short();
            Waiting.enque(temp);
            break;
        }

        case 3: {
            while (!Waiting.is_empty()) {
                print("\nAdmit this patient?\n");
                patient temp = *Waiting.deque();
                temp.print_info_short();
                if (bool_option()) {
                    Adm_P.append(temp);
                    print("\n\nPatient Admitted.");
                }
            }
            break;
        }

        case 4: {
            print(
                "\e[1;4;97m\n\n\e[20G::OPD Queue::\n\e[0;37m\
        1. Next in Line\n\
        2. Show Enitre Queue\n\
        3. Clear Queue\n\
        0. Back\n\
        \e[1;4;36mEnter:\e[0;36m "
            );
            int OPD_opt{};
            cin >> OPD_opt;
            while (OPD_opt > 3 || OPD_opt < 0) {
                print("\e[91m\
        Please Enter A Valid Input:\e[0;36m ");
                cin >> OPD_opt;
            }
            print("\e[0;37m\n");
            if (OPD_opt == 0) { break; }

            switch (OPD_opt)
            {
            case 1: {
                cout << *OPD.seek();
                break;
            }
            case 2: {
                OPD.println();
                break;
            }
            case 3: {
                OPD.clear();
            }
            }
            break;
        }

        case 5: {
            print(
                "\e[1;4;97m\n\n\e[20G::Admitted Patients::\n\e[0;37m\
        1. Show Admitted Patients\n\
        2. Find Patient\n\
        3. Discharge Patient\n\
        0. Back\n\
        \e[1;4;36mEnter:\e[0;36m "
            );
            int A_opt{};
            cin >> A_opt;
            while (A_opt > 3 || A_opt < 0) {
                print("\e[91m\
        Please Enter A Valid Input:\e[0;36m ");
                cin >> A_opt;
            }
            print("\e[0;37m\n");
            if (A_opt == 0) { break; }

            switch (A_opt)
            {
            case 1: {
                Adm_P.println();
                break;
            }
            case 2: {
                print("\nEnter Patient ID: ");
                int id;
                cin >> id;
                int find = Adm_P.searchById(id);
                if (find == -1) {
                    print("Patient is not in the Admitted list.");
                    break;
                }
                print("Patient found, at position: {}\n", find + 1);
                cout << *Adm_P[find];
                break;
            }
            case 3: {
                print("\nEnter Patient ID to discharge: ");
                int id;
                cin >> id;
                int find = Adm_P.searchById(id);
                if (find == -1) {
                    print("Patient is not in the Admitted list.");
                    break;
                }
                print("Patient found, at position: {}\n", find + 1);
                cout << *Adm_P[find] << "\n";
                print("Discharge, {}, ID: {}?", Adm_P[find]->name, Adm_P[find]->pid);
                if (bool_option()) {
                    Adm_P.delin(find);
                    print("\n\nPatient Discharged");
                }
                break;
            }
            }
        }
        }
    }
    println("\nExiting Application");
    return 0;
}