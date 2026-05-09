#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

struct SinhVien {
    int maSV;
    string ten;
    string lop;
    float diem;
    string hanhKiem;
};

struct Node {
    SinhVien data;
    Node* next;
};

SinhVien NhapSV() {
    SinhVien sv;

    cout << "Ma SV: "; 
    cin >> sv.maSV;

    cin.ignore();
    cout << "Ten: "; 
    getline(cin, sv.ten);

    cout << "Lop: "; 
    getline(cin, sv.lop);

    cout << "Diem: "; 
    cin >> sv.diem;

    cin.ignore();
    cout << "Hanh kiem: "; 
    getline(cin, sv.hanhKiem);
    return sv;
}

Node* CreateNode(SinhVien sv) {
    Node* p = new Node;
    p->data = sv;
    p->next = NULL;
    return p;
}

Node* AddHead(Node* L, SinhVien sv) {
    Node* p = CreateNode(sv);
    p->next = L;
    return p;
}

Node* AddTail(Node* L, SinhVien sv) {
    Node* p = CreateNode(sv);
    if (L == NULL) {
        return p;
    }

    Node* temp = L;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = p;
    return L;
}

void XuatSV(SinhVien sv) {
    cout << sv.maSV << " | " << sv.ten << " | "
        << sv.lop << " | " << sv.diem << " | "
        << sv.hanhKiem << endl;
}

void Traverse(Node* L) {
    Node* p = L;
    while (p != NULL) {
        XuatSV(p->data);
        p = p->next;
    }
}

void DeleteTail(Node*& L) {
    if (L == NULL) return;

    if (L->next == NULL) {
        delete L;
        L = NULL;
        return;
    }

    Node* p = L;
    while (p->next->next != NULL)
        p = p->next;

    delete p->next;
    p->next = NULL;
}

void LocTheoLop(Node* L, string lopCanTim) {
    Node* p = L;
    while (p != NULL) {
        if (p->data.lop == lopCanTim)
            XuatSV(p->data);
        p = p->next;
    }
}

void Sort(Node*& L) {
    for (Node* i = L; i != NULL; i = i->next) {
        Node* min = i;
        for (Node* j = i->next; j != NULL; j = j->next) {
            if (j->data.maSV < min->data.maSV)
                min = j;
        }
        swap(i->data, min->data);
    }
}

int main() {
    Node* L;
    L = nullptr;

    int n;
    cout << "Nhap so sinh vien: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cout << "\nNhap sinh vien thu " << i + 1 << ":\n";
        SinhVien sv = NhapSV();
        L = AddTail(L, sv);
    }
    cout << "\n";

    cout << "Danh sach sinh vien:\n";
    Traverse(L);

    cout << "Sinh vien lop IT003.Q29:\n";
    LocTheoLop(L, "IT003.Q29");

    Sort(L);
    cout << "Danh sach sau khi sap xep:\n";
    Traverse(L);

    DeleteTail(L);
    cout << "Danh sach sau khi xoa cuoi:\n";
    Traverse(L);

    return 0;
}