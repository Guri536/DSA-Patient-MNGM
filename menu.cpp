#include<iostream>
#include"patient_MS.hpp"
using namespace std;

int main() {
    PMS Patient_Man_Sys;
    m_queue<patient>& OPD = Patient_Man_Sys.OPD_CheckIn;
    linked_list<patient>& Adm_P = Patient_Man_Sys.Admitted_Patients;
    m_queue<patient>& Waiting = Patient_Man_Sys.OPD_CheckOut;
    PMS_UI window(LIGHT_THEME);

    while (true) {
        int opt{};
        window.clear();
        print(
            "\n\n{}::MENU::\n{}\
        1. Register New Check-In\n\
        2. Send next In Check-In Queue\n\
        3. Admit from Check-Out Queue\n\
        4. In Queue Patients\n\
        5. Admitted Patients\n\
        0. Exit\n\
        {}Enter:{} ",
            window.menu_text(),
            window.normal_text(),
            window.interactive_text(),
            window.interactive_input_text()
        );

        cin >> opt;
        while (opt > 5 || opt < 0) {
            print("{}\
        Please Enter A Valid Input:{} ",
                window.warning_text(),
                window.interactive_input_text()
            );
            cin >> opt;
        }
        print("{}", window.normal_text());
        if (opt == 0) { break; }

        switch (opt)
        {
        case 1: {
            patient temp;
            cout << "Is this Correct? " << temp;
            if (bool_option()) {
                OPD.enque(temp);
                print("{}{} registered in OPD Queue{}",
                    window.success_text(),
                    temp.name,
                    window.normal_text());
            }
            break;
        }

        case 2: {
            if (is_obj_empty(OPD, "Check-In Queue is Empty")) { break; }
            print("\nSending next Patient:\n");
            OPD.seek()->print_info_short();
            if (bool_option()) {
                patient temp = *OPD.deque();
                Waiting.enque(temp);
                print("{}{} sent to OPD{}",
                    window.success_text(),
                    temp.name,
                    window.normal_text());
            }
            break;
        }

        case 3: {
            if (is_obj_empty(Waiting, "Check-Out Queue is Empty")) { break; }
            print("\n{}Patients Awaiting: {}{}",
                window.error_text(), Waiting.size(), window.normal_text());
            while (!Waiting.is_empty()) {
                print("\n\nAdmit this patient?\n");
                patient temp = *Waiting.deque();
                temp.print_info_short();
                if (bool_option()) {
                    temp.set_admitted();
                    Adm_P.append(temp);
                    print("{}{} Admitted in Ward{}",
                        window.success_text(),
                        temp.name,
                        window.normal_text());
                }
            }
            break;
        }

        case 4: {
            print(
                "\n\n{}::OPD Queue::{}\n\
        1. Next in Line\n\
        2. Show Enitre Queue\n\
        3. Clear Queue\n\
        0. Back\n\
        {}Enter:{} ",
                window.menu_text(),
                window.normal_text(),
                window.interactive_text(),
                window.interactive_input_text()
            );
            int OPD_opt{};
            cin >> OPD_opt;
            while (OPD_opt > 3 || OPD_opt < 0) {
                print("{}\
        Please Enter A Valid Input:{} ",
                    window.warning_text(), window.interactive_input_text());
                cin >> OPD_opt;
            }
            print("{}\n", window.normal_text());
            if (OPD_opt == 0) { break; }

            if (is_obj_empty(OPD, "Check-In Queue is Empty")) { break; }
            print("{}Patients in OPD Queue: {}{}\n",
                window.error_text(), OPD.size(), window.normal_text());

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
                print("\nQueue is cleared");
            }
            }
            break;
        }

        case 5: {
            print(
                "\n\n{}::Admitted Patients::\n{}\
        1. Show Admitted Patients\n\
        2. Find Patient\n\
        3. Discharge Patient\n\
        0. Back\n\
        {}Enter:{} ",
                window.menu_text(),
                window.normal_text(),
                window.interactive_text(),
                window.interactive_input_text()
            );
            int A_opt{};
            cin >> A_opt;
            while (A_opt > 3 || A_opt < 0) {
                print("{}\
        Please Enter A Valid Input:{} ",
                    window.warning_text(), window.interactive_input_text());
                cin >> A_opt;
            }
            print("{}\n", window.normal_text());
            if (A_opt == 0) { break; }
            if (is_obj_empty(Adm_P, "No patients are admitted")) { break; }
            switch (A_opt)
            {
            case 1: {
                print("{}Patients Admitted: {}{}\n",
                    window.error_text(), Adm_P.size(), window.normal_text());
                Adm_P.println();
                break;
            }
            case 2: {
                print("\nEnter Patient ID: ");
                int id;
                cin >> id;
                int find = Adm_P.searchById(id);
                if (find == -1) {
                    print("\n{}Patient is not in Ward{}",
                        window.error_text(), window.normal_text());
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
                    print("\n{}Patient is not in Ward{}",
                        window.error_text(), window.normal_text());
                    break;
                }
                print("Patient found, at position: {}\n", find + 1);
                cout << *Adm_P[find] << "\n";
                print("Discharge, {}, ID: {}?", Adm_P[find]->name, Adm_P[find]->pid);
                if (bool_option()) {
                    Adm_P.delin(find);
                    print("{}Patient  Discharged{}",
                        window.success_text(), window.normal_text());
                }
                break;
            }
            }
        }
        }
        window.pause();
    }
    print("\n{}Exiting Application", window.warning_text());
    window.pause();
    return 0;
}