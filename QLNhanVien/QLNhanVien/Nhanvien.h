#pragma once
#include <iostream>
#include <string>
using namespace std;

class Nhanvien {
protected:
    string ten, ngaysinh, ma;
    int id; // Phân biệt loại nhân viên
public:
    int getterid();
    string getterma();
    void setterma(string);
    virtual void nhap();
    virtual void xuat();
    virtual double Tinhluong();
    Nhanvien();
    virtual ~Nhanvien();
};
