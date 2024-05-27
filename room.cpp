#include "room.h"

Room::Room() {
    // Initialize room availability map
    room_availability["Standard"] = true;
    room_availability["Beachfront"] = true;
    room_availability["Luxury"] = true;
}

// Kiểm tra sự sẵn có của các phòng vào ngày cụ thể
void Room::check_room_availability(string date) {
    cout << "Room availability on " << date << ":" << endl;
    for (auto &room : room_availability) {
        cout << room.first << ": ";
        if (room.second) {
            cout << "Available" << endl;
        } else {
            cout << "Booked" << endl;
        }
        cin.ignore();
        cin.get();
    }
}

// Đặt phòng mới dựa trên loại phòng và số lượng phòng
void Room::book_room(string room_type, int number_of_rooms) {
    // Implement booking functionality
    // Mark rooms as booked in room_availability map
    if (room_availability.find(room_type) != room_availability.end()) {
        room_availability[room_type] = false;
        cout << "Successfully booked " << number_of_rooms << " " << room_type << " room(s)." << endl;

    } else {
        cout << "Invalid room type." << endl;
    }
}

// Hủy đặt phòng dựa trên ID phòng
void Room::cancel_room_booking(string room_id) {
    // Implement cancel booking functionality
    // Mark room as available in room_availability map
    for (auto &room : room_availability) {
        if (room.first == room_id) {
            room.second = true;
            cout << "Successfully cancelled booking for room " << room_id << "." << endl;
            return;
        }
    }
    cout << "Room with ID " << room_id << " not found." << endl;
}