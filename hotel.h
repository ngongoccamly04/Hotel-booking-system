#ifndef HOTEL_H
#define HOTEL_H
using namespace std;
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <string>
#include <map>

class Hotel {
    private:
        // Các hằng số giá tiền phòng
        const int ROOM_COST_NORMAL = 100;
        const int ROOM_COST_SEA_VIEW = 200;
        const int ROOM_COST_LUXURY = 300;

    public:
        // Khởi tạo lớp Hotel và các đối tượng liên quan
        void init() ;

        // Tạo ID đặt phòng ngẫu nhiên cho khách hàng
        int generate_random_booking_id();

        // Tính tổng chi phí đặt phòng dựa trên loại phòng, số lượng phòng và thời gian lưu trú
        int calculate_room_cost(int, int, int);

        // Tạo danh sách số phòng đặt cho khách hàng
        vector<int> generate_room_numbers(int, int);

        // Tạo thông tin xác nhận đặt phòng cho khách hàng
        string generate_booking_confirmation(string, vector<int>, string , int);
};
#endif