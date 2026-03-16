#include <iostream>
using namespace std;

// Hàm kiểm tra năm nhuận
bool laNamNhuan(int y) {
    return (y % 400 == 0) || (y % 4 == 0 && y % 100 != 0);
}

// Hàm trả về số ngày trong tháng
int timSoNgayTrongThang(int m, int y) {
    switch (m) {
        case 1: case 3: case 5: case 7: case 8: case 10: case 12:
            return 31;
        case 4: case 6: case 9: case 11:
            return 30;
        case 2:
            return laNamNhuan(y) ? 29 : 28;
        default:
            return 0;
    }
}

int main() {
    int d, m, y;
    cout << "Nhap ngay, thang, nam: ";
    cin >> d >> m >> y;

    int maxDay = timSoNgayTrongThang(m, y);

    // Kiểm tra tính hợp lệ cơ bản của ngày nhập vào
    if (m < 1 || m > 12 || d < 1 || d > maxDay) {
        cout << "Ngay khong hop le!" << endl;
    } else {
        if (d < maxDay) {
            d++; // Tăng ngày bình thường
        } else {
            d = 1; // Reset về ngày 1
            if (m < 12) {
                m++; // Tăng tháng
            } else {
                m = 1; // Reset về tháng 1
                y++;   // Tăng năm
            }
        }
        cout << "Ngay ke tiep la: " << d << "/" << m << "/" << y << endl;
    }

    return 0;
}