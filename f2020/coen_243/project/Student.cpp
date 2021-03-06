#include "Headers/Student.h"

#include <iostream>
#include <string>
#include <array>

using namespace std;

int Student::id_count = 0;

Student::Student() {
    
}

Student::Student(string f_name, string l_name, string dob, double gpa, double credit, char program, int start_year) {
    ++id_count;
    this->SetId(id_count);
    this->f_name = f_name;
    this->l_name = l_name;
    this->dob = dob;
    this->gpa_latest = gpa;
    this->completed_credit = credit;
    this->program = program;
    this->start_year = start_year;
}

// Getter implementations
string Student::GetLastName() {
    return this->l_name;
}

string Student::GetFirstName() {
    return this->f_name;
}

int Student::GetId() {
    return this->id;
}

string Student::GetDOB() {
    return this->dob;
}

double Student::GetGPA() {
    return this->gpa_latest;
}

double Student::GetCredit() {
    return this->completed_credit;
}

char Student::GetProgram() {
    return this->program;
}

int Student::GetStartYear() {
    return this->start_year;
}

// Setter Implementations

void Student::SetLastName(string new_l_name) {
    this->l_name = new_l_name;
}

void Student::SetFirstName(string new_f_name) {
    this->f_name = new_f_name;
}

void Student::SetId(int new_id) {
    this->id = new_id;
}

void Student::SetDOB(string new_dob) {
    this->dob = new_dob;
}

void Student::SetGPA(double new_gpa) {
    this->gpa_latest = new_gpa;
}

void Student::SetCredit(double new_credit) {
    this->completed_credit = new_credit;
}

void Student::SetProgram(char new_prog) {
    this->program = new_prog;
}

void Student::SetStartYear(int new_start_year) {
    this->start_year = new_start_year;
}

// Additional features

bool Student::CompleteProgram() {
    bool bComplete = false;
    if (this->program == 'B') bComplete = (this->completed_credit == 140);
    else if (this->program == 'M') bComplete = (this->completed_credit == 16);
    else if (this->program == 'P') bComplete = (this->completed_credit == 12);
    else cout << "Invalid program code" << endl;
    return bComplete;
}

string Student::StudentStatus() {
    /*
        A+  :   >= 3.5
        A   :   >= 3 < 3.5
        B   :   >= 2.5 < 3
        C   :   >= 2.0 < 2.5
        D   :   < 2.0
    */
    if (this->gpa_latest >= 3.5) {
        return "A+";
    } else if (this->gpa_latest >= 3.0 && this->gpa_latest < 3.5) {
        return "A";
    } else if (this->gpa_latest >= 2.5 && this->gpa_latest < 3.0) {
        return "B";
    } else if (this->gpa_latest >= 2.0 && this->gpa_latest < 2.5) {
        return "C";
    } else if (this->gpa_latest < 2.0) {
        return "D";
    } else {
        return "0";
    }
}

void Student::PrintStudentInfo() {
    cout << "Student ID       : " << this->GetId() << endl;
    cout << "First name       : " << this->GetFirstName() << endl;
    cout << "Last name        : " << this->GetLastName() << endl;
    cout << "DOB              : " << this->GetDOB() << endl;
    cout << "GPA              : " << this->GetGPA() << endl;
    cout << "Completed credits: " << this->GetCredit() << endl;
    cout << "Program          : " << this->GetProgram() << endl;
    cout << "Start year       : " << this->GetStartYear() << endl;
    cout << "-------------------------------\n";
}

int Student::CompareGPA(Student student_to_compare) {
    if (student_to_compare.GetGPA() > this->GetGPA()) {
        return student_to_compare.GetId();
    } else if (student_to_compare.GetGPA() < this->GetGPA()) {
        return this->GetId();
    } else {
        return 0;
    }
}

void Student::InternalDebugger() {
    cout << "ID count: " << this->id_count << endl;
    cout << "Get ID: " << this->GetId() << endl;
}