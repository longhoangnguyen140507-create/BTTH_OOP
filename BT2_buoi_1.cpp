#include <iostream>

using namespace std;

struct PhanSo {
    int tu;
    int mau;
};

// Hàm nhập phân số
void nhapPhanSo(PhanSo &ps, string ten) {
    cout << "Nhap " << ten << ":" << endl;
    cout << " - Tu so: ";
    cin >> ps.tu;
    do {
        cout << " - Mau so (khac 0): ";
        cin >> ps.mau;
        if (ps.mau == 0) cout << "Mau phai khac 0! Nhap lai.\n";
    } while (ps.mau == 0);
}

// Hàm so sánh và trả về phân số lớn nhất
PhanSo timMax(PhanSo ps1, PhanSo ps2) {
    // So sánh bằng cách nhân chéo: a/b và c/d => so sánh a*d và c*b
    // Quy chuẩn mẫu số dương để so sánh chính xác
    long long mauChung1 = (long long)ps1.tu * ps2.mau;
    long long mauChung2 = (long long)ps2.tu * ps1.mau;

    // Nếu mẫu âm, ta đảo ngược logic so sánh hoặc chuẩn hóa mẫu dương
    if ((ps1.mau * ps2.mau) > 0) {
        return (mauChung1 >= mauChung2) ? ps1 : ps2;
    } else {
        return (mauChung1 <= mauChung2) ? ps1 : ps2;
    }
}

int main() {
    PhanSo ps1, ps2;

    nhapPhanSo(ps1, "phan so thu nhat");
    nhapPhanSo(ps2, "phan so thu hai");

    PhanSo max = timMax(ps1, ps2);

    cout << "\nPhan so lon nhat la: " << max.tu << "/" << max.mau << endl;

    return 0;
}
