#include "Nhanvien.h"

Nhanvien::Nhanvien() : id(0) {}

void Nhanvien::nhap() {
    fflush(stdin);
    cin.ignore();
    cout << "\nNhap ten: "; getline(cin, ten);
    cout << "\nNhap ngay sinh: "; getline(cin, ngaysinh);
}

void Nhanvien::xuat() {
    cout << "\nMa: " << ma;
    cout << "\nTen: " << ten;
    cout << "\nNgay sinh: " << ngaysinh;
}

double Nhanvien::Tinhluong() {
    return 0;
}

int Nhanvien::getterid() {
    return id;
}

string Nhanvien::getterma() {
    return ma;
}

void Nhanvien::setterma(string xma) {
    ma = xma;
}

Nhanvien::~Nhanvien() {}
