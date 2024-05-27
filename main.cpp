#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <string>
#include <map>
#include "hotel.h"
#include "authentication.h"
#include "customer.h"
#include "datastorage.h"
#include "employee.h"
#include "room.h"
#include "service.h"
#include "userinterface.h"

using namespace std;

enum MainMenuOption {
    BOOK_ROOM = 1,
    DELETE_BOOKED_ROOM,
    VIEW_CUSTOMER_INFO_BY_ID,
    VIEW_ALL_CUSTOMER_INFO,
    EDIT_CUSTOMER_INFO,
    CHECK_OCCUPIED_ROOMS,
    CHANGE_EMPLOYEE_INFO,
    MANAGE_EMPLOYEES,
    EXIT_PROGRAM
};




int main() {
    system("cls");
    Authentication auth;
    Hotel hotel;
    UserInterface ui(&hotel); // Truyền con trỏ tới đối tượng Hotel
    string username;
    string id;
    bool authenticated = false;
    
    do {
        ui.display_login_screen();
        cout << "Username: ";
        cin >> username;
        cout << "ID: ";
        cin >> id;
        authenticated = auth.authenticate(username, id);

        if (!authenticated) {
            cout << "Authentication failed. Please try again." << endl;
        }
    } while (!authenticated);
    system("cls");

    ui.display_main_menu();

    return 0;
}
