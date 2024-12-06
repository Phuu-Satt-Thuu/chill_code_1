#pragma once
#include "Nhanvien.h"

class Nhanvientamthoi : public Nhanvien {
private:
    unsigned long long soLuongSanPham;
    unsigned long long giaSanPham;
    unsigned long long tienThuong;
public:
    void nhap() override;
    void xuat() override;
    double Tinhluong() override;
    Nhanvientamthoi();
    ~Nhanvientamthoi();
};
