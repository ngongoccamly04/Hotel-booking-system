#ifndef ROOM_H
#define ROOM_H
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <string>
#include <map>
using namespace std;

class Room {
    private:
        map<string, bool> room_availability;

    public:
        // Constructor
        Room();
        // Kiểm tra sự sẵn có của các phòng vào ngày cụ thể
        void check_room_availability(string);

        // Đặt phòng mới dựa trên loại phòng và số lượng phòng
        void book_room(string, int) ;

        // Hủy đặt phòng dựa trên ID phòng
        void cancel_room_booking(string);
};
#endif