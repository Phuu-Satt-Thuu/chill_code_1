#include "Congty.h"

void NhanVien::Nhap() {
    cout << "Nhap ma nhan vien: ";
    cin >> maNV;
    cout << "Nhap ten nhan vien: ";
    cin.ignore(); // Để tránh vấn đề với getline sau khi nhập số
    getline(cin, ten);
    cout << "Nhap ngay sinh (dd/mm/yyyy): ";
    cin >> ngaysinh;
    cout << "Nhap chuc vu: ";
    cin.ignore();
    getline(cin, chucVu);

    cout << "La nhan vien chinh thuc (1) hay tam thoi (0): ";
    int isChinhThucInput;
    cin >> isChinhThucInput;  // Đọc giá trị từ người dùng
    isChinhThuc = (isChinhThucInput == 1);  // Gán true hoặc false cho isChinhThuc

    if (isChinhThuc) {
        cout << "Nhap luong co ban: ";
        cin >> luongcanban;
        cout << "Nhap thang vao lam: ";
        cin >> thangVaoLam;
        cout << "Nhap nam vao lam: ";
        cin >> namVaoLam;
        cout << "Nhap he so luong: ";
        cin >> heSoLuong;
    }
    else {
        cout << "Nhap so luong san pham: ";
        cin >> soLuongSanPham;
        cout << "Nhap gia san pham: ";
        cin >> giaSanPham;
        cout << "Nhap tien thuong (neu co): ";
        cin >> tienThuong;
    }
}

void NhanVien::Xuat() const {
    cout << "Ma NV: " << maNV << ", Ten: " << ten << ", Ngay sinh: " << ngaysinh << ", Chuc vu: " << chucVu;
    if (isChinhThuc) {
        cout << ", Luong co ban: " << luongcanban << ", Thang vao lam: " << thangVaoLam << ", Nam vao lam: " << namVaoLam << ", He so luong: " << heSoLuong << endl;
    }
    else {
        cout << ", So luong san pham: " << soLuongSanPham << ", Gia san pham: " << giaSanPham << ", Tien thuong: " << tienThuong << endl;
    }
}

void NhanVien::ghiVaoFile(ofstream& file) const {
    file << maNV << "\n" << ten << "\n" << ngaysinh << "\n" << chucVu << "\n" << isChinhThuc << "\n";
    if (isChinhThuc) {
        file << luongcanban << "\n" << thangVaoLam << "\n" << namVaoLam << "\n" << heSoLuong << "\n";
    }
    else {
        file << soLuongSanPham << "\n" << giaSanPham << "\n" << tienThuong << "\n";
    }
}

void NhanVien::docTuFile(ifstream& file) {
    getline(file, maNV);
    getline(file, ten);
    getline(file, ngaysinh);
    getline(file, chucVu);
    file >> isChinhThuc;
    file.ignore(); // Để tránh vấn đề với getline sau khi đọc số

    if (isChinhThuc) {
        file >> luongcanban;
        file >> thangVaoLam;
        file >> namVaoLam;
        file >> heSoLuong;
    }
    else {
        file >> soLuongSanPham;
        file >> giaSanPham;
        file >> tienThuong;
    }
    file.ignore();
}

void Congty::Nhap() {
    NhanVien nv;
    nv.Nhap();
    if (nv.isChinhThuc) {
        dsNhanVienChinhThuc.push_back(nv);
        ghiToFile("chinhthuc.txt", dsNhanVienChinhThuc);
    }
    else {
        dsNhanVienTamThoi.push_back(nv);
        ghiToFile("tamthoi.txt", dsNhanVienTamThoi);
    }
}

void Congty::Xuat() const {
    cout << "Danh sach nhan vien chinh thuc:\n";
    for (const auto& nv : dsNhanVienChinhThuc) {
        nv.Xuat();
    }
    cout << endl;
    cout << "Danh sach nhan vien tam thoi:\n";
    for (const auto& nv : dsNhanVienTamThoi) {
        nv.Xuat();
    }
    cout << endl;
}

unsigned long long Congty::tinhluongcongty() const {
    long long tongLuong = 0;  // Thay đổi kiểu về long long
    for (const auto& nv : dsNhanVienChinhThuc) {
        tongLuong += nv.luongcanban * nv.heSoLuong;  // Tính lương với hệ số
    }
    for (const auto& nv : dsNhanVienTamThoi) {
        tongLuong += (nv.soLuongSanPham * nv.giaSanPham) + nv.tienThuong;  // Lương tạm thời cộng thêm tiền thưởng
    }
    return tongLuong;
}

void Congty::docTuFile() {
    docDauVaoFile("chinhthuc.txt", dsNhanVienChinhThuc);
    docDauVaoFile("tamthoi.txt", dsNhanVienTamThoi);
}

void Congty::ghiToFile(const string& filename, const vector<NhanVien>& dsNhanVien) const {
    ofstream file(filename, ios::trunc); // Mở file và ghi lại toàn bộ dữ liệu
    if (!file) {
        cout << "Khong the mo file " << filename << endl;
        return;
    }
    for (const auto& nv : dsNhanVien) {
        nv.ghiVaoFile(file);
    }
    file.close();
}

void Congty::docDauVaoFile(const string& filename, vector<NhanVien>& dsNhanVien) {
    ifstream file(filename);
    if (!file) {
        cout << "Khong the mo file " << filename << "\n";
        return;
    }

    NhanVien nv;
    while (file.peek() != EOF) {
        nv.docTuFile(file);
        dsNhanVien.push_back(nv);
    }
    file.close();
}

void Congty::xoaNhanVien(const string& maNV, bool isTamThoi) {
    vector<NhanVien>& ds = isTamThoi ? dsNhanVienTamThoi : dsNhanVienChinhThuc;

    // Tìm và xóa nhân viên theo mã NV
    auto it = remove_if(ds.begin(), ds.end(), [&maNV](const NhanVien& nv) {
        return nv.maNV == maNV;
        });
    ds.erase(it, ds.end());

    // Ghi lại file sau khi xóa nhân viên
    ghiToFile(isTamThoi ? "tamthoi.txt" : "chinhthuc.txt", ds);
}

void Congty::themNhanVienTamThoi() {
    NhanVien nv;
    nv.Nhap();
    dsNhanVienTamThoi.push_back(nv);
    ghiToFile("tamthoi.txt", dsNhanVienTamThoi);
}
