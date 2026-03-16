#include <iostream>
#include <string>
#include <iomanip> // Thư viện để định dạng số thập phân

using namespace std;

int main() {
    string hoTen;
    float diemToan, diemVan, diemTB;

    // Bước 1: Nhập dữ liệu
    cout << "Nhap ho ten hoc sinh: ";
    getline(cin, hoTen); // Sử dụng getline để nhập được chuỗi có khoảng trắng

    cout << "Nhap diem mon Toan: ";
    cin >> diemToan;

    cout << "Nhap diem mon Van: ";
    cin >> diemVan;

    // Bước 2: Tính điểm trung bình
    diemTB = (diemToan + diemVan) / 2;

    // Bước 3: Xuất kết quả
    cout << "-------------------" << endl;
    cout << "Hoc sinh: " << hoTen << endl;
    // Setprecision(2) để lấy 2 chữ số thập phân cho đẹp
    cout << "Diem trung binh: " << fixed << setprecision(2) << diemTB << endl;

    return 0;
}