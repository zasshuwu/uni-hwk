#include <iostream>
#include <string>
#include "department.h"
#include <cstring>

using namespace std;

Department::Department() {
    string new_name;
    string new_id;
    string new_history;
    
    cout << "\n------------\n> Creating new department..." << endl;

    cout << "Enter department name: ";
    cin >> new_name;
    cin.ignore(256, '\n');
    Department::EditName(new_name);

    cout << "Enter department ID: ";
    cin >> new_id;
    cin.ignore(256, '\n');
    Department::EditId(new_id);
    
    cout << "Enter department history: ";
    cin >> new_history;
    cin.ignore(256, '\n');
    Department::EditHistory(new_history);

    cout << "Department has been created." << endl;
    cout << "----------------------------" << endl;
    cout << "Department Name    : " << Department::GetName() << endl;
    cout << "Department ID      : " << Department::GetId() << endl;
    cout << "Department History : " << Department::GetHistory() << endl;
}

string Department::GetId() {
    return this->id;
}

void Department::EditId(string new_id) {
    this->id = new_id;
}

string Department::GetName() {
    return this->name;
}

void Department::EditName(string new_name) {
    this->name = new_name;
}

string Department::GetHistory() {
    return this->history;
}

void Department::EditHistory(string new_history) {
    this->history = new_history;
}

void Department::AddMember(Employee emp) {
    for (size_t i = 0; i <= sizeof(this->emps); i++) {
        if (this->emps[i].GetFirstName().empty() == true) {
            this->emps[i] = emp;
            break;
        }
    }
}

Employee Department::GetMember(int i) {
    return this->emps[i];
}

void Department::RemoveMember(int ex_emp_id) {
    Employee emp_blank;
    emp_blank.EditAddress("");
    emp_blank.EditFirstName("");
    emp_blank.EditLastName("");
    emp_blank.EditSalary(0);
    emp_blank.EditDOB("");
    for (size_t i = 0; i <= sizeof(this->emps); i++) {
        if (this->emps[i].GetId() == ex_emp_id) {
            this->emps[i] = emp_blank;
            break;
        }
    }
}

bool Department::SearchEmployee(int id) {
    bool flag;
    for (Employee emp : this->emps) {
        if (emp.GetId() == id) {
            flag = 1;
            break;
        } else flag = 0;
    }
    return flag;
}

void Department::PrintEmployeeList() {
    cout << "List of employees: " << endl;
    cout << "ID" << "\t\t\t" << "Full name" << endl; 
    for (Employee emp : this->emps) {
        if (emp.GetFirstName().empty() == false) {
            cout << emp.GetId() << "\t\t\t" << emp.GetFirstName() << endl;
        }
    };
}

void Department::PrintEmployeeCount() {
    int num_of_emps = 0;
    for (Employee emp : this->emps) {
        if (emp.GetFirstName().empty() == false) {
            num_of_emps++;
        }
    };
    cout << "Number of employees in the department: " << num_of_emps << endl;
}

void Department::Debugger() {
    cout << "IO Stream checked" << endl;
    cout << this->emps[0].GetFirstName().empty() << endl;
    cout << this->emps[0].GetFirstName() << endl;
    cout << "GetFirstName().empty() -> " << this->emps[0].GetFirstName().empty() << endl;
    for (Employee emp : this-> emps) {
        cout << emp.GetFirstName() << endl;
        cout << emp.GetFirstName().empty() << endl;
        cout << (emp.GetFirstName().empty() == false) << endl;
    }
}