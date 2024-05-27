#ifndef USERINTERFACE_H
#define USERINTERFACE_H
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <string>
#include <map>
#include "customer.h"
#include "hotel.h"
#include "room.h"
#include "employee.h"
using namespace std;


class UserInterface {
private:
    Customer customer;
    Room room; // Thêm biến room vào lớp UserInterface
     Hotel* hotel; // Thêm con trỏ tới đối tượng Hotel
public:
    // Constructor
    UserInterface() : customer("Default Customer", 0) {} // Tạo một đối tượng Customer mặc định
        UserInterface(Hotel* _hotel) : customer("Default Customer", 0), hotel(_hotel) {} 
    void display_login_screen();
    void display_main_menu();
};
#endif