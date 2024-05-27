#include "datastorage.h"

// Thêm dữ liệu mới vào cơ sở dữ liệu
void DataStorage::add_data(string data_info, int data_id) {
    data[data_id] = data_info;
    cout << "Data added successfully!" << endl;
}

// Xóa dữ liệu dựa trên ID
void DataStorage::delete_data(int data_id) {
    auto it = data.find(data_id);
    if (it != data.end()) {
        data.erase(it);
        cout << "Data with ID " << data_id << " deleted successfully!" << endl;
    } else {
        cout << "Data with ID " << data_id << " not found!" << endl;
    }
}

// Cập nhật thông tin của dữ liệu
void DataStorage::update_data(int data_id, string new_data) {
    auto it = data.find(data_id);
    if (it != data.end()) {
        it->second = new_data;
        cout << "Data with ID " << data_id << " updated successfully!" << endl;
    } else {
        cout << "Data with ID " << data_id << " not found!" << endl;
    }
}

// Truy xuất thông tin dữ liệu dựa trên ID
void DataStorage::retrieve_data(int data_id) {
    auto it = data.find(data_id);
    if (it != data.end()) {
        cout << "Data with ID " << data_id << ": " << it->second << endl;
    } else {
        cout << "Data with ID " << data_id << " not found!" << endl;
    }
}
