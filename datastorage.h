#ifndef DATASTORAGE_H
#define DATASTORAGE_H
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <string>
#include <map>
using namespace std;


class DataStorage {
    private:
        map<int, string> data;

    public:
        // Thêm dữ liệu mới vào cơ sở dữ liệu
        void add_data(string, int);
        // Xóa dữ liệu dựa trên ID
        void delete_data(int);

        // Cập nhật thông tin của dữ liệu
        void update_data(int, string);

        // Truy xuất thông tin dữ liệu dựa trên ID
        void retrieve_data(int);
};
#endif
