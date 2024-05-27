#include "customer.h"

Customer::Customer(string _name, int _customer_id) {
    name = _name;
    customer_id = _customer_id;
}
Hotel* hotel; // Thêm con trỏ tới đối tượng Hotel

//Tên và ID khách
void Customer::book_room() {
cin.ignore();
cout<<"Enter customer name: "<<endl;
getline(cin,name);
cout<<"Enter customer ID: "<<endl;
cin>>customer_id;
// Đặt phòng mới cho khách hàng 
cout << "1. Standard Room\n2. Beachfront Room\n3. Luxury Room\n";
cout << "Choose room type: ";
int room_type;
cin >> room_type;

int quantity;
cout << "Enter quantity of rooms: ";
cin >> quantity;

int num_beds;
cout << "Enter number of beds: ";
cin >> num_beds;

int num_days;
cout << "Enter number of days staying: ";
cin >> num_days;

vector<int> room_numbers = hotel->generate_room_numbers(room_type, quantity);

int room_price;
if (room_type == 1) {
    room_price = 100;
} else if (room_type == 2) {
    room_price = 200;
} else if (room_type == 3) {
    room_price = 250;
}

// Tính giá phòng dựa trên số giường
room_price *= num_beds;

int total_room_cost = quantity * room_price * num_days;

cout << "Do you want to use additional services? (1: Yes, 2: No): ";
int service_choice;
cin >> service_choice;

int total_service_cost = 0;
if (service_choice == 1) {
    cout << "1. Transportation Service (50$/day)\n";
    cout << "2. Laundry Service (30$/day)\n";
    cout << "3. Buffet Meal (70$/day)\n";
    cout << "Choose services you want to use (enter numbers separated by space): ";
    
    vector<int> chosen_services;
    int option;
    while (cin >> option) {
        chosen_services.push_back(option);
        if (cin.peek() == '\n') break;
    }

    for (int service : chosen_services) {
        if (service == 1) {
            total_service_cost += 50 * num_days;
        } else if (service == 2) {
            total_service_cost += 30 * num_days;
        } else if (service == 3) {
            total_service_cost += 70 * num_days;
        }
    }
}


string check_in_date, check_out_date;
cout << "Enter check-in date (dd-mm-yyyy): ";
cin >> check_in_date;
cout << "Enter check-out date (dd-mm-yyyy): ";
cin >> check_out_date;

cout << "Booked room numbers: ";
for (int i = 0; i < room_numbers.size(); ++i) {
    cout << room_numbers[i];
    if (i != room_numbers.size() - 1) cout << ", ";
}
cout << endl;

// Tạo ID đặt phòng ngẫu nhiên từ đối tượng Hotel
int booking_id = hotel->generate_random_booking_id();

// Tạo một đối tượng BookingDetail để lưu thông tin đặt phòng
BookingDetail booking;
booking.booking_id = booking_id;
booking.room_number = room_numbers[0]; 
booking.check_out_date = check_out_date;
booking.check_in_date = check_in_date;
booking.room_type = room_type;

// Thêm booking vào vector bookings của khách hàng
bookings.push_back(booking);
//tổng tiền thanh toán
int total_cost = total_room_cost + total_service_cost;

//IN RA THÔNG TIN ĐÃ NHẬP
cout <<" =========================================== "<<endl;
cout << "Customer name: "<<name<<endl;
cout << "Customer ID: "<<customer_id<<endl;
cout << "Check in date:  "<<check_in_date<<endl;
cout << "Check out date: "<<check_out_date<<endl;
cout << "Total room cost: " << total_room_cost << "$\n";
cout << "Total service cost: " << total_service_cost << "$\n";
cout << "Total cost: " << total_cost << "$\n";
// In booking ID ra màn hình
cout << "Booking ID: " << booking_id << endl;
cout <<" =========================================== "<<endl;

cout << "Press Enter to return to the main menu...";
cin.ignore();
cin.get();
}




void Customer::cancel_booking(int _booking_id){
    BookingDetail booking;
    if(_booking_id != booking.booking_id){
        cout<<"Invalid, try again"<<endl;
        cin.ignore();
    }
    else{
        
        cout<<"Cancel booking sucesfull"<<endl;
        cin.ignore();
    }
}


// Xem thông tin của khách hàng dựa trên ID
void Customer::view_customer_info_id(int _customer_id) {
    if (_customer_id != customer_id) {
        cout << "Invalid customer ID. Cannot view customer info." << endl;
        cout << "Press Enter to return to the main menu...";
        return;
    }
    else{
    cout << "Customer Name: " << name << endl;
    cout << "Customer ID: " << customer_id << endl;
    cout << "    Booking" << endl;
    for (const auto& booking : bookings) {
        for (const auto& service : booking.services) {
        cout << "Room Number: " << booking.room_number << endl;
        cout << "Room Type: " << booking.room_type << endl;
        cout << "Services:" << endl;
            cout << "- " << service << endl;
        }
        cout << "Check-in Date: " <<booking.check_in_date << endl;
        cout << "Check-out Date: " <<booking.check_out_date << endl;
    }
    }
    cout << "Press Enter to return to the main menu...";
    cin.ignore();
    cin.get();
}


// Phương thức để chỉnh sửa thông tin khách hàng
void Customer::edit_customer_info(string _name,vector<int> _room_numbers) {
    name = _name;
    room_numbers = _room_numbers;
}

// Phương thức để thêm phòng cho khách hàng
void Customer::add_room(int room_number) {
    room_numbers.push_back(room_number);
}

// Phương thức để bớt phòng của khách hàng
void Customer::remove_room(int room_number) {
    for (auto it = room_numbers.begin(); it != room_numbers.end(); ++it) {
        if (*it == room_number) {
            room_numbers.erase(it);
            break;
        }
    }
}


// void Customer::view_all_customer_info() {
// // Kiểm tra nếu không có khách hàng nào trong danh sách
// if (customer_list.empty()) {
//     cout << "Empty data,try again!" << endl;
//     cin.ignore();
//     return;
// }
// else {
//     for (const auto& customer : customer_list) {
//     cout << "===== Customer information =====" << endl;
//     cout << "Customer ID: " << customer.customer_id << endl;
//     cout << "Customer name: " << customer.name << endl;
//     cout << "Number of booked room: " << customer.booked_rooms.size() << endl;
//     cout << "List of room: ";
//     for (const auto& room : customer.booked_rooms) {
//         cout << room << ", ";
//     }
//     cout << endl;
//     cout << "Service added: ";
//     for (const auto& service : customer.booked_services) {
//         cout << service << ", ";
//     }
//     cout << endl;
//     cout << "Check in: " << customer.check_in_date << endl;
//     cout << "Check out: " << customer.check_out_date << endl;
//     cout << "Total cost: $" << customer.total_cost << endl;
//     cout << "===============================" << endl;
//     cin.ignore();
//     cin.get();
//     }
//     }
// }



