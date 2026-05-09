#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

struct SinhVien {
    int maSV;
    string hoTen;
    int namSinh;
    int gioiTinh;
    float diemTB;
};

void nhap1SV(SinhVien& sv) {
    cin >> sv.maSV;
    cin.ignore();
    getline(cin, sv.hoTen);
    cin >> sv.namSinh;
    cin >> sv.gioiTinh;
    cin >> sv.diemTB;
}

void NhapSV(SinhVien a[], int& n) {
    cin >> n;
    cin.ignore();
    for (int i = 0; i < n; i++) {
        nhap1SV(a[i]);
    }
}

void sortByMaSV(SinhVien a[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < n; j++) {
            if (a[j].maSV < a[min_idx].maSV)
                min_idx = j;
        }
        swap(a[i], a[min_idx]);
    }
}

void sortByDiemTB(SinhVien a[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int max_idx = i;
        for (int j = i + 1; j < n; j++) {
            if (a[j].diemTB > a[max_idx].diemTB ||
                (a[j].diemTB == a[max_idx].diemTB && a[j].maSV < a[max_idx].maSV)) {
                max_idx = j;
            }
        }
        swap(a[i], a[max_idx]);
    }
}

void Xuat1SV(SinhVien sv) {
    cout << sv.maSV << " | "
        << sv.hoTen << " | "
        << sv.namSinh << " | "
        << (sv.gioiTinh == 0 ? "Nu" : "Nam") << " | "
        << fixed << setprecision(1) << sv.diemTB << "\n";
}

void XuatSV(SinhVien a[], int n) {
    for (int i = 0; i < n; i++) {
        Xuat1SV(a[i]);
    }
}

int main() {
    SinhVien a[1000], b[1000], c[1000];
    int n;

    NhapSV(a, n);

    for (int i = 0; i < n; i++) {
        b[i] = a[i];
        c[i] = a[i];
    }

    sortByMaSV(b, n);
    sortByDiemTB(c, n);

    cout << "Danh sach sap xep theo ma sinh vien tang dan:\n";
    XuatSV(b, n);

    cout << "Danh sach sap xep theo diem trung binh giam dan:\n";
    XuatSV(c, n);

    return 0;
}