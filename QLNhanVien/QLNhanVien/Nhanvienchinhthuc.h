#pragma once
#include "Nhanvien.h"

class Nhanvienchinhthuc : public Nhanvien {
private:
    unsigned long long luongcanban;
    double hesoluong;
public:
    void nhap() override;
    void xuat() override;
    double Tinhluong() override;
    Nhanvienchinhthuc();
    ~Nhanvienchinhthuc();
};
