#include <iostream>
#include <cmath>

using namespace std;

// Hàm tìm Ước chung lớn nhất (UCLN) bằng thuật toán Euclid
int timUCLN(int a, int b) {
    a = abs(a);
    b = abs(b);
    while (b != 0) {
        int tam = b;
        b = a % b;
        a = tam;
    }
    return a;
}

struct PhanSo {
    int tu;  // Tử số
    int mau; // Mẫu số
};

int main() {
    PhanSo ps;

    // 1. Nhập phân số
    cout << "Nhap tu so: ";
    cin >> ps.tu;
    
    do {
        cout << "Nhap mau so (khac 0): ";
        cin >> ps.mau;
        if (ps.mau == 0) {
            cout << "Mau so khong the bang 0. Vui long nhap lai!\n";
        }
    } while (ps.mau == 0);

    // 2. Rút gọn phân số
    int ucln = timUCLN(ps.tu, ps.mau);
    ps.tu /= ucln;
    ps.mau /= ucln;

    // 3. Chuẩn hóa dấu (nếu mẫu âm thì chuyển dấu lên tử)
    if (ps.mau < 0) {
        ps.tu = -ps.tu;
        ps.mau = -ps.mau;
    }

    // 4. Xuất kết quả
    cout << "Phan so sau khi rut gon: ";
    if (ps.mau == 1) {
        cout << ps.tu << endl; // Nếu mẫu là 1 thì in số nguyên
    } else {
        cout << ps.tu << "/" << ps.mau << endl;
    }

    return 0;
}