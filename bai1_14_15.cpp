#include <iostream>
#include <vector>
using namespace std;

struct Nut {
    int giaTri;
    Nut* trai;
    Nut* phai;

    Nut(int x) {
        giaTri = x;
        trai = nullptr;
        phai = nullptr;
    }
};

void duyetTruoc(Nut* goc) {
    if (goc == nullptr) return;
    cout << goc->giaTri << " ";
    duyetTruoc(goc->trai);
    duyetTruoc(goc->phai);
}

void duyetGiua(Nut* goc) {
    if (goc == nullptr) return;
    duyetGiua(goc->trai);
    cout << goc->giaTri << " ";
    duyetGiua(goc->phai);
}

void duyetSau(Nut* goc) {
    if (goc == nullptr) return;
    duyetSau(goc->trai);
    duyetSau(goc->phai);
    cout << goc->giaTri << " ";
}

void duaVaoMang(Nut* goc, vector<Nut*>& danhSach) {
    if (goc == nullptr) return;
    danhSach.push_back(goc);
    duaVaoMang(goc->trai, danhSach);
    duaVaoMang(goc->phai, danhSach);
}

void vunXuong(vector<Nut*>& danhSach, int n, int i) {
    int lonNhat = i;
    int trai = 2 * i + 1;
    int phai = 2 * i + 2;

    if (trai < n && danhSach[trai]->giaTri > danhSach[lonNhat]->giaTri)
        lonNhat = trai;

    if (phai < n && danhSach[phai]->giaTri > danhSach[lonNhat]->giaTri)
        lonNhat = phai;

    if (lonNhat != i) {
        swap(danhSach[i]->giaTri, danhSach[lonNhat]->giaTri);
        vunXuong(danhSach, n, lonNhat);
    }
}

void vunDong(vector<Nut*>& danhSach) {
    int n = danhSach.size();
    for (int i = n / 2 - 1; i >= 0; i--)
        vunXuong(danhSach, n, i);
}

Nut* taoCayTheoDe() {
    Nut* n4  = new Nut(4);
    Nut* n1  = new Nut(1);
    Nut* n3  = new Nut(3);
    Nut* n2  = new Nut(2);
    Nut* n16 = new Nut(16);
    Nut* n9  = new Nut(9);
    Nut* n10 = new Nut(10);
    Nut* n14 = new Nut(14);
    Nut* n8  = new Nut(8);
    Nut* n7  = new Nut(7);

    n4->trai = n1;      n4->phai = n3;
    n1->trai = n2;      n1->phai = n16;
    n2->trai = n14;     n2->phai = n8;
    n16->trai = n7;
    n3->trai = n9;      n3->phai = n10;

    return n4;
}

int main() {
    Nut* goc = taoCayTheoDe();

    cout << "Duyet truoc: ";
    duyetTruoc(goc);

    cout << "\nDuyet giua: ";
    duyetGiua(goc);

    cout << "\nDuyet sau: ";
    duyetSau(goc);

    vector<Nut*> danhSach;
    duaVaoMang(goc, danhSach);

    vunDong(danhSach);

    cout << "\n\nSau khi vun dong (duyet truoc): ";
    duyetTruoc(goc);

    return 0;
}
