#include "employee.h"



void Employee::add_employee(string employee_name, int employee_id) {
    employees[employee_id] = employee_name;
    cout << "Employee added successfully!" << endl;
}

void Employee::remove_employee(int employee_id) {
    auto it = employees.find(employee_id);
    if (it != employees.end()) {
        employees.erase(it);
        cout << "Employee removed successfully!" << endl;
    } else {
        cout << "Employee with ID " << employee_id << " not found!" << endl;
    }
}

void Employee::edit_employee_info(int employee_id, string new_name, int new_id) {
    auto it = employees.find(employee_id);
    if (it != employees.end()) {
        it->second = new_name;
        employees[new_id] = new_name;
        cout << "Employee information updated successfully!" << endl;
    } else {
        cout << "Employee with ID " << employee_id << " not found!" << endl;
    }
}