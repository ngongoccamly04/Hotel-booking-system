#include "service.h"


// Hàm cho phép khách hàng chọn các dịch vụ bổ sung
vector<int> Service::select_services() {
    vector<int> selected_services;
    int choice;
    cout << "Do you want to use additional services? (1 for yes, 2 for no): ";
    cin >> choice;
    if (choice == 1) {
        cout << "Select services by entering the corresponding numbers separated by spaces: ";
        cout << endl;
        cout << "Service Menu: " << endl;
        for (auto it = service_menu.begin(); it != service_menu.end(); ++it) {
            cout << it->first << ". " << it->second << endl;
        }
        cout << "Enter your choices: ";
        int service;
        while (cin >> service) {
            selected_services.push_back(service);
        }
    }
    return selected_services;
}
// Hàm tính tổng chi phí các dịch vụ đã chọn
double  Service::calculate_service_cost(vector<int> selected_services, int number_of_days) {
    double total_cost = 0;
    for (int service : selected_services) {
        total_cost += service * number_of_days;
    }
    return total_cost;
}
