#include <iostream>
#include <string>
using namespace std;

struct Nut {
    int chiSo;
    string tenMuc;
    int trangBatDau, trangKetThuc;
    Nut* conDau;
    Nut* anhEmKe;

    Nut(int cs, string ten, int bd, int kt)
        : chiSo(cs), tenMuc(ten),
          trangBatDau(bd), trangKetThuc(kt),
          conDau(nullptr), anhEmKe(nullptr) {}
};

/* Them muc con */
void themCon(Nut* cha, Nut* con) {
    if (!cha->conDau)
        cha->conDau = con;
    else {
        Nut* p = cha->conDau;
        while (p->anhEmKe)
            p = p->anhEmKe;
        p->anhEmKe = con;
    }
}

/* In muc luc */
void inCay(Nut* goc, int muc = 0) {
    if (!goc) return;

    for (int i = 0; i < muc; i++) cout << "  ";
    cout << goc->chiSo << ". " << goc->tenMuc
         << " (" << goc->trangBatDau
         << "-" << goc->trangKetThuc << ")\n";

    inCay(goc->conDau, muc + 1);
    inCay(goc->anhEmKe, muc);
}

/* Dem so chuong */
int demSoChuong(Nut* sach) {
    int dem = 0;
    Nut* p = sach->conDau;
    while (p) {
        dem++;
        p = p->anhEmKe;
    }
    return dem;
}

/* Tim chuong dai nhat */
Nut* timChuongDaiNhat(Nut* sach) {
    Nut* p = sach->conDau;
    Nut* chuongMax = nullptr;
    int doDaiMax = -1;

    while (p) {
        int doDai = p->trangKetThuc - p->trangBatDau + 1;
        if (doDai > doDaiMax) {
            doDaiMax = doDai;
            chuongMax = p;
        }
        p = p->anhEmKe;
    }
    return chuongMax;
}

/* Xoa muc theo chi so */
bool xoaMuc(Nut* cha, int chiSo) {
    if (!cha) return false;

    Nut* truoc = nullptr;
    Nut* hienTai = cha->conDau;

    while (hienTai) {
        if (hienTai->chiSo == chiSo) {
            if (!truoc)
                cha->conDau = hienTai->anhEmKe;
            else
                truoc->anhEmKe = hienTai->anhEmKe;
            delete hienTai;
            return true;
        }
        truoc = hienTai;
        hienTai = hienTai->anhEmKe;
    }
    return xoaMuc(cha->conDau, chiSo);
}


int main() {
    Nut* sach = new Nut(0, "CUON SACH", 1, 200);

    Nut* chuong1 = new Nut(1, "Chuong 1", 1, 50);
    Nut* chuong2 = new Nut(2, "Chuong 2", 51, 120);
    Nut* chuong3 = new Nut(3, "Chuong 3", 121, 200);

    themCon(sach, chuong1);
    themCon(sach, chuong2);
    themCon(sach, chuong3);

    themCon(chuong1, new Nut(11, "Muc 1.1", 1, 20));
    themCon(chuong1, new Nut(12, "Muc 1.2", 21, 50));

    themCon(chuong2, new Nut(21, "Muc 2.1", 51, 80));
    themCon(chuong2, new Nut(22, "Muc 2.2", 81, 120));

    cout << " MUC LUC SACH \n";
    inCay(sach);

    cout << "\nSo chuong: " << demSoChuong(sach) << endl;

    Nut* chuongDaiNhat = timChuongDaiNhat(sach);
    cout << "Chuong dai nhat: " << chuongDaiNhat->tenMuc << endl;

    cout << "\nXoa muc co chi so = 22\n";
    xoaMuc(sach, 22);
    inCay(sach);

    cout << "\nMuc luc Chuong 1:\n";
    inCay(chuong1, 1);

    return 0;
}
