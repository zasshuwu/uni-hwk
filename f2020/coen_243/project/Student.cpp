#include "Headers/Student.h"

#include <iostream>
#include <string>
#include <array>

using namespace std;

static int id_count;

Student::Student() {
    this->SetId(id_count);
    id_count++;
}

Student::Student(string f_name, string l_name, string dob, double gpa, double credit, char program) {
    this->f_name = f_name;
    this->l_name = l_name;
    this->dob = dob;
    this->gpa = gpa;
    this->credit = credit;
    this->program = program;
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

// Additional features

bool Student::CompleteProgram(char cur_prog, int id) {

}

string Student::StudentStatus(double cur_gpa) {

}

void PrintStudentInfo() {

}

int CompareGPA(int id_a, int id_b) {
    
}