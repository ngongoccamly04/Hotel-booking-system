#include "hotel.h"


// Khởi tạo lớp Hotel và các đối tượng liên quan
void Hotel::init() {
    // Khởi tạo seed cho hàm random
    srand(time(0));
}

// Tạo ID đặt phòng ngẫu nhiên cho khách hàng
int Hotel::generate_random_booking_id() {
    return rand() % 1000000;
}

// Tính tổng chi phí đặt phòng dựa trên loại phòng, số lượng phòng và thời gian lưu trú
int Hotel::calculate_room_cost(int room_type, int number_of_rooms, int duration) {
    int room_cost;
    switch (room_type) {
        case 1:
            room_cost = ROOM_COST_NORMAL;
            break;
        case 2:
            room_cost = ROOM_COST_SEA_VIEW;
            break;
        case 3:
            room_cost = ROOM_COST_LUXURY;
            break;
        default:
            room_cost = 0;
            break;
    }
    return room_cost * number_of_rooms * duration;
}

// Tạo danh sách số phòng đặt cho khách hàng
vector<int> Hotel::generate_room_numbers(int room_type, int number_of_rooms) {
    vector<int> room_numbers;
    // Giả sử số phòng bắt đầu từ 1 cho mỗi loại phòng
    int start_room_number = 1;
    for (int i = 0; i < number_of_rooms; ++i) {
        room_numbers.push_back(start_room_number++);
    }
    return room_numbers;
}

// Tạo thông tin xác nhận đặt phòng cho khách hàng
string Hotel::generate_booking_confirmation(string customer_info, vector<int> room_info, string service_info, int total_cost) {
    string confirmation = "Customer Info: " + customer_info + "\n";
    confirmation += "Room Info: ";
    for (int i = 0; i < room_info.size(); ++i) {
        confirmation += to_string(room_info[i]);
        if (i < room_info.size() - 1) {
            confirmation += ", ";
        }
    }
    confirmation += "\n";
    confirmation += "Service Info: " + service_info + "\n";
    confirmation += "Total Cost: $" + to_string(total_cost);
    return confirmation;
}
