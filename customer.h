#ifndef CUSTOMER_H
#define CUSTOMER_H
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <string>
#include <map>
#include "hotel.h"
using namespace std;

// Cấu trúc lưu trữ thông tin chi tiết của mỗi đặt phòng

struct BookingDetail {
    int booking_id; // ID đặt phòng
    int room_number;
    string room_type;
    vector<string> services;
    string check_in_date;
    string check_out_date;
};

class Customer {
    private:
        string name;
        int customer_id;
        vector<string> booked_rooms;
        vector<string> booked_services;
        string check_in_date;
        string check_out_date;
        int total_cost;
        vector<BookingDetail> bookings;
        vector<Customer> customer_list; // Định nghĩa customer_list là một vector chứa các đối tượng Customer
        vector<int> room_numbers;
        string phone_number;
        // Các thuộc tính khác của khách hàng có thể thêm vào sau nếu có nhu cầu 
    public:
        // Constructor
        Customer(string, int);
        // Hủy đặt phòng
        void cancel_booking(int);
        // Đặt phòng mới cho khách hàng 
        void book_room();

    // Xem thông tin của khách hàng dựa trên ID
        void view_customer_info_id(int);


    // Phương thức để chỉnh sửa thông tin khách hàng
        void edit_customer_info(string , vector<int>);

        // Phương thức để thêm phòng cho khách hàng
        void add_room(int);

        // Phương thức để bớt phòng của khách hàng
        void remove_room(int);


};
#endif