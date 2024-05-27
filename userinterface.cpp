#include "userinterface.h"


void UserInterface::display_login_screen() {
    cout <<"                                      "<< "  ABC HOTEL" << endl;
    cout <<"                                      "<< "EMPOLYEE LOGIN: " << endl;
    string username;
    string id;
    bool authenticated = false; // Biến kiểm tra xác thực
    string new_name;
    vector<int> new_room_numbers;
    string new_phone_number;
    while (!authenticated) { // Sử dụng while để lặp lại khi chưa xác thực thành công
        cout << "Username: ";
        cin >> username;
        cout << "ID: ";
        cin >> id;
        if (username == "abc" && id == "123") {
                break;//authenticated = true; // Nếu xác thực thành công, thoát khỏi vòng lặp
        } else {
            cout << "Invalid, try again!!" << endl;
            continue;
        }
    }
}
void UserInterface::display_main_menu() {
    int choice;
    do {
        cout <<"                                      "<<"            ABC HOTEL         " << endl;
        cout <<"                                      "<< "============ MENU ============" << endl;
        cout <<"                                      "<< "1. Book new room" << endl;
        cout <<"                                      "<< "2. Cancel room" << endl;
        cout <<"                                      "<< "3. Display customer information base on ID" << endl;
        cout <<"                                      "<< "4. Change customer information" << endl;
        cout <<"                                      "<< "5. Check room" << endl;
        cout <<"                                      "<< "6. Add, delete employee" << endl;
        cout <<"                                      "<< "7. Change employee infor" << endl;        
        cout <<"                                      "<< "0. Thoat chuong trinh" << endl;
        cout <<"                                      "<< "Nhap lua chon cua ban: ";
        cin >> choice;
        cout <<"\n                                     "<< "===================================" << endl;
        
        int customer_id;
        int booking_id;
        switch (choice) {
            case 1:
                customer.book_room(); // Gọi hàm book_room từ đối tượng customer
                system("cls");
                break;
            case 2:
                cout<<"Enter booking ID need to cancel: "<<endl;
                cin>>booking_id;
                customer.cancel_booking(booking_id);
                system("cls");
                break;
            case 3:
                cout << "Enter customer ID need to see information: ";
                cin >> customer_id;
                customer.view_customer_info_id(customer_id);
                system("cls");
                break;
            case 4:
                {
                    int edit_choice;
                    cout << "1. Change name, room" << endl;
                    cout << "2. Add room" << endl;
                    cout << "3. Decrease room" << endl;
                    cout << "Enter your choice: ";
                    cin >> edit_choice;

                    switch (edit_choice) {
                        case 1: {
                            string new_name;
                            vector<int> new_room_numbers;
                            cout << "New name: ";
                            cin.ignore();
                            getline(cin, new_name);

                            // Thu thập danh sách số phòng mới
                            int num_new_rooms;
                            cout << "Number room: ";
                            cin >> num_new_rooms;
                            for (int i = 0; i < num_new_rooms; ++i) {
                                int room_number;
                                cout << "Enter number of the room" << i + 1 << ": ";
                                cin >> room_number;
                                new_room_numbers.push_back(room_number);
                            }

                            // Gọi phương thức edit_customer_info từ đối tượng customer và chuyển thông tin mới nhận được làm đối số
                            customer.edit_customer_info(new_name, new_room_numbers);
                            break;
                        }
                        case 2: {
                            int room_number;
                            cout << "Enter number the room need to add: ";
                            cin >> room_number;
                            customer.add_room(room_number);
                            break;
                        }
                        case 3: {
                            int room_number;
                            cout << "Enter number of the room need to delete: ";
                            cin >> room_number;
                            customer.remove_room(room_number);
                            break;
                        }
                        default:
                            cout << "Invalid , try again!! " << endl;
                            break;
                    }
                    system("cls");
                    break;
                }
            case 5:
                {
                    string date;
                    cout << "Enter day need to check (dd-mm-yyyy): ";
                    cin >> date;
                    room.check_room_availability(date);
                    system("cls");
                    break;
                }
               
            case 6:
                {
                    Employee employee; // Khởi tạo đối tượng Employee
                    int employee_id, new_id;
                    string employee_name, new_name;

                    cout << "Enter employee ID: ";
                    cin >> employee_id;

                    int choice;
                    cout << "Choose an action: " << endl;
                    cout << "1. Add Employee" << endl;
                    cout << "2. Remove Employee" << endl;
                    cin >> choice;

                    switch (choice) {
                        case 1:
                            cout << "Enter new employee name: ";
                            cin >> employee_name;
                            employee.add_employee(employee_name, employee_id); // Gọi phương thức add_employee từ lớp Employee
                            break;
                        case 2:
                            employee.remove_employee(employee_id); // Gọi phương thức remove_employee từ lớp Employee
                            break;
                        default:
                            cout << "Invalid choice!" << endl;
                            break;
                    }
                    system("cls");
                    break;
                }
            case 7:
                {
                    Employee employee; // Khởi tạo đối tượng Employee
                    int employee_id;
                    string new_name;
                    int new_id;

                    cout << "Enter employee ID: ";
                    cin >> employee_id;

                    cout << "Enter new name: ";
                    cin >> new_name;

                    cout << "Enter new ID: ";
                    cin >> new_id;

                    employee.edit_employee_info(employee_id, new_name, new_id); // Gọi phương thức edit_employee_info từ lớp Employee
                    system("cls");
                    
                    break;
                }
                case 0:
                    cout << "Tam biet! Hen gap lai." << endl;
                    exit(0);
                    break;
                default:
                    cout << "Lua chon khong hop le. Vui long chon lai." << endl;
                    break;
            }
        } while (true);
    }