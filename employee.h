#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <string>
#include <map>
using namespace std;

class Employee {
    private:
        map<int, string> employees;

    public:
        void add_employee(string, int);
        void remove_employee(int);
        void edit_employee_info(int, string, int);
    };
#endif

