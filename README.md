# Patient Management System
GitHub Repository: https://github.com/Guri536/DSA-Patient-MNGM.git 

This is a C++ application that simulates a Patient Management System (PMS) for a healthcare facility. The system is designed to manage the influx of new patients, process them through clinic visits, and manage a list of admitted patients in a ward.

The application is built with a modular structure, focusing on abstraction and reusability. It uses custom-built data structures (a linked list and a queue) and features a color-coordinated, menu-driven user interface for the terminal.

## Core Workflow
The system manages patients through three main stages:
* OPD Check-In: New patients are registered with their name and age. They are then added to the OPD_CheckIn queue.
* Clinic Visit: When a clinic is available, the first patient from the OPD_CheckIn queue is sent for a visit. This moves them from the check-in queue to the OPD_CheckOut queue.
* Admission/Discharge: A user reviews the patients in the OPD_CheckOut queue. Based on a manual decision, the patient is either admitted (added to the Admitted_Patients linked list) or discharged (removed from the flow).

## Features
The application provides a main menu to navigate between different management tasks.

### Main Menu
1. Register New Patient: Prompts for patient details (Name, Age) and adds them to the OPD_CheckIn queue.

2. Send next Patient to Clinic: Takes the first patient from the OPD_CheckIn queue and moves them to the OPD_CheckOut queue.

3. Admit from Check-Out Queue: Iterates through the OPD_CheckOut queue, allowing the user to admit each patient to the ward.

4. In Queue Patients (OPD Menu): Opens a sub-menu to manage the OPD_CheckIn queue.

5. Admitted Patients (Ward Menu): Opens a sub-menu to manage the Admitted_Patients list.

6. Exit: Exits the application.

### OPD Queue Menu
1. Next in Line: Shows the details of the first patient in the check-in queue.

2. Show Entire Queue: Prints all patients currently in the check-in queue.

3. Clear Queue: Clears all patients from the check-in queue.

### Admitted Patients Menu
1. Show Admitted Patients: Prints the details of every patient currently admitted to the ward.

2. Find Patient: Searches for an admitted patient by their unique Patient ID and displays their info if found.

3. Discharge Patient: Searches for a patient by ID and removes them from the Admitted_Patients list.

## Code Structure
The project is broken into several header files, each with a distinct responsibility.



* menu.cpp 
  * The main entry point of the application.
  * Contains the primary application loop, user input handling, and menu logic.


* patient_MS.hpp 
  * Defines the core PMS class, which initializes and holds the patient queues and the admitted patient list.
  * Defines the PMS_UI class, which inherits from ANSI_UI to provide specific color themes for the application.

* patient_info.hpp 
  * Defines the patient struct.
  * It stores all patient data (ID, name, age, admission status) and inherits from hasId to be compatible with the linked list's searchById function.

* queue.hpp 
  * Defines a template-based queue class m_queue.
  * It is implemented by privately inheriting from the linked_list class, limiting access to queue-specific operations (enqueue, dequeue, seek).


* linked_list.hpp 
  * Defines a template-based singly linked_list and _node struct.
  * Includes an abstract base class hasId , which provides an interface for items that can be searched by an ID.
 
* UI.hpp 
  * Defines the ANSI_UI class for managing the terminal user interface.
  * Provides functions for setting text/background colors, clearing the screen, managing themes (Light/Dark/Red), and pausing for user input using ANSI escape codes.


## Building and Running
This project is written in C++23 and requires a compatible compiler.

> Compiler: GCC / G++ (MinGW MSYS2 was used in development).

> C++ Standard: C++23.

Build Command: To compile the project, run the following command, ensuring you include the experimental modules flag:
``` bash
g++ -std=c++23 -fmodules-ts -g menu.cpp -o patient_ms.exe -Istdc++exp
```