#include "Nhanvienchinhthuc.h"

Nhanvienchinhthuc::Nhanvienchinhthuc() {
    id = 1;
}

void Nhanvienchinhthuc::nhap() {
    Nhanvien::nhap();
    cout << "\nNhap luong can ban: "; cin >> luongcanban;
    cout << "\nNhap he so luong: "; cin >> hesoluong;
}

void Nhanvienchinhthuc::xuat() {
    Nhanvien::xuat();
    cout << "\nLuong can ban: " << size_t(luongcanban);
    cout << "\nHe so luong: " << size_t(hesoluong);
}

double Nhanvienchinhthuc::Tinhluong() {
    return luongcanban * hesoluong;
}

Nhanvienchinhthuc::~Nhanvienchinhthuc() {}
