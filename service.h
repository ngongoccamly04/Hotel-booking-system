#ifndef SERVICE_H
#define SERVICE_H
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <string>
#include <map>
using namespace std;


class Service {
    private:
        map<int, string> service_menu = {
            {1, "Transportation service (50$/day)"},
            {2, "Laundry service (30$/day)"},
            {3, "Buffet meal service (70$/day)"}
        };

    public:
        // Hàm cho phép khách hàng chọn các dịch vụ bổ sung
        vector<int> select_services();

        // Hàm tính tổng chi phí các dịch vụ đã chọn
        double calculate_service_cost(vector<int>, int);
};
#endif