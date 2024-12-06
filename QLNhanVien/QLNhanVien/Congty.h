#ifndef CONGTY_H
#define CONGTY_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class NhanVien {
public:
    string maNV, ten, ngaysinh, chucVu;
    bool isChinhThuc;
    unsigned long long luongcanban, soLuongSanPham, giaSanPham, tienThuong;
    double heSoLuong;
    int thangVaoLam, namVaoLam;

    void Nhap();
    void Xuat() const;
    void ghiVaoFile(ofstream& file) const;
    void docTuFile(ifstream& file);
};

class Congty {
private:
    vector<NhanVien> dsNhanVienChinhThuc;
    vector<NhanVien> dsNhanVienTamThoi;

public:
    void Nhap();
    void Xuat() const;
    unsigned long long tinhluongcongty() const;
    void docTuFile();
    void ghiToFile(const string& filename, const vector<NhanVien>& dsNhanVien) const;
    void docDauVaoFile(const string& filename, vector<NhanVien>& dsNhanVien);
    void xoaNhanVien(const string& maNV, bool isTamThoi);
    void themNhanVienTamThoi();
};

#endif
