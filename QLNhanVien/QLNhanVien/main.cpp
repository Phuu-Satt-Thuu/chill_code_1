#include "Congty.h"
#include <windows.h>

// Hàm thay đổi màu sắc chữ
void setColor(int color) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

// Hàm di chuyển con trỏ đến tọa độ (x, y)
void gotoXY(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

// Hàm hiển thị menu
void displayMenu() {
    system("cls"); // Xóa màn hình
    setColor(14);  // Màu vàng
    gotoXY(30, 6);
    cout << "================ MENU ================\n";
    gotoXY(30, 7);
    cout << "1. Them nhan vien \n";
    gotoXY(30, 8);
    cout << "2. Tinh tong luong cua cong ty\n";
    gotoXY(30, 9);
    cout << "3. Xoa nhan vien\n";
    gotoXY(30, 10);
    cout << "4. Xuat thong tin nhan vien\n";
    gotoXY(30, 11);
    cout << "0. Thoat chuong trinh\n";
    gotoXY(30, 12);
    cout << "=====================================\n";
    setColor(7); // Reset lại màu trắng
    gotoXY(30, 13);
    cout << "Nhap lua chon: ";
}

int main() {
    Congty congty;

    // Đọc dữ liệu từ file khi bắt đầu
    congty.docTuFile();

    int choice;
    do {
        displayMenu(); // Hiển thị menu
        cin >> choice;

        system("cls"); // Xóa màn hình trước khi thực hiện chức năng
        switch (choice) {
        case 1:
            setColor(10); // Màu xanh lá
            cout << "Nhap thong tin nhan vien:\n";
            congty.Nhap();
            break;
        case 2:
            setColor(13); // Màu hồng
            cout << "\nTong luong cua cong ty: " << congty.tinhluongcongty() << "\n";
            break;
        case 3:
            setColor(12); // Màu đỏ
            {
                string tenNhanVien;
                cout << "Nhap ma nhan vien can xoa: ";
                cin.ignore();
                getline(cin, tenNhanVien);
                bool isTamThoi;
                cout << "Nhan vien tam thoi (1) hay chinh thuc (0)? ";
                cin >> isTamThoi;
                congty.xoaNhanVien(tenNhanVien, isTamThoi);
                cout << "Nhan vien da duoc xoa.\n";
            }
            break;
        case 4:
            setColor(11); // Màu xanh dương nhạt
            cout << "\nDanh sach nhan vien:\n";
            cout << endl;
            congty.Xuat();
            break;
        case 0:
            setColor(14); // Màu vàng
            cout << "Thoat chuong trinh.\n";
            break;
        default:
            setColor(12); // Màu đỏ
            cout << "Lua chon khong hop le! Vui long chon lai.\n";
        }
        system("pause"); // Đợi người dùng nhấn phím để tiếp tục
    } while (choice != 0);

    return 0;
}
