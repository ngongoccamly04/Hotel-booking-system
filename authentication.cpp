#include"authentication.h"

bool Authentication::authenticate(string username, string id) {
    // Xác minh tên đăng nhập và ID
    if (username == "abc" && id == "123") {
        return true; // Xác thực thành công
    } else {
        return false; // Xác thực thất bại
    }
}