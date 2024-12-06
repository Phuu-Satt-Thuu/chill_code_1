#include "Nhanvientamthoi.h"

Nhanvientamthoi::Nhanvientamthoi() {
    id = 2;
}

void Nhanvientamthoi::nhap() {
    Nhanvien::nhap();
    cout << "\nNhap so luong san pham: "; cin >> soLuongSanPham;
    cout << "\nNhap gia san pham: "; cin >> giaSanPham;
    cout << "\nNhap tien thuong: "; cin >> tienThuong;
}

void Nhanvientamthoi::xuat() {
    Nhanvien::xuat();
    cout << "\nSo luong san pham: "; cin >> soLuongSanPham;
    cout << "\nGia san pham: "; cin >> giaSanPham;
    cout << "\nTien thuong: "; cin >> tienThuong;
}

double Nhanvientamthoi::Tinhluong() {
    return ((soLuongSanPham * giaSanPham) + tienThuong);
}

Nhanvientamthoi::~Nhanvientamthoi() {}
