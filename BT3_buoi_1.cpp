#include <iostream>
#include <cmath>

using namespace std;

struct PhanSo {
    int tu, mau;
};

// Hàm tìm UCLN để rút gọn
int timUCLN(int a, int b) {
    a = abs(a); b = abs(b);
    while (b != 0) {
        int tam = b;
        b = a % b;
        a = tam;
    }
    return a;
}

// Hàm rút gọn phân số
void rutGon(PhanSo &ps) {
    int ucln = timUCLN(ps.tu, ps.mau);
    ps.tu /= ucln;
    ps.mau /= ucln;
    if (ps.mau < 0) { ps.tu = -ps.tu; ps.mau = -ps.mau; }
}

// Hàm xuất phân số
void xuat(PhanSo ps) {
    rutGon(ps);
    if (ps.mau == 1) cout << ps.tu;
    else cout << ps.tu << "/" << ps.mau;
}

int main() {
    PhanSo ps1, ps2, kq;

    // Nhập phân số 1
    cout << "Nhap PS1 (tu mau): ";
    cin >> ps1.tu >> ps1.mau;
    // Nhập phân số 2
    cout << "Nhap PS2 (tu mau): ";
    cin >> ps2.tu >> ps2.mau;

    if (ps1.mau == 0 || ps2.mau == 0) {
        cout << "Mau so phai khac 0!";
        return 0;
    }

    // TỔNG
    kq.tu = ps1.tu * ps2.mau + ps2.tu * ps1.mau;
    kq.mau = ps1.mau * ps2.mau;
    cout << "\nTong: "; xuat(kq);

    // HIỆU
    kq.tu = ps1.tu * ps2.mau - ps2.tu * ps1.mau;
    kq.mau = ps1.mau * ps2.mau;
    cout << "\nHieu: "; xuat(kq);

    // TÍCH
    kq.tu = ps1.tu * ps2.tu;
    kq.mau = ps1.mau * ps2.mau;
    cout << "\nTich: "; xuat(kq);

    // THƯƠNG
    if (ps2.tu == 0) {
        cout << "\nThuong: Khong the chia cho 0";
    } else {
        kq.tu = ps1.tu * ps2.mau;
        kq.mau = ps1.mau * ps2.tu;
        cout << "\nThuong: "; xuat(kq);
    }

    cout << endl;
    return 0;
}