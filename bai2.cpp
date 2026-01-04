#include <iostream>
#include <string>
using namespace std;

struct NutNhiPhan {
    int chiSo;
    string tenMuc;
    NutNhiPhan* trai;
    NutNhiPhan* phai;

    NutNhiPhan(int cs, string ten)
        : chiSo(cs), tenMuc(ten), trai(nullptr), phai(nullptr) {}
};

bool laCayGiongNhau(NutNhiPhan* cay1, NutNhiPhan* cay2) {
    if (!cay1 && !cay2) return true;
    if (!cay1 || !cay2) return false;

    if (cay1->chiSo != cay2->chiSo ||
        cay1->tenMuc != cay2->tenMuc)
        return false;

    return laCayGiongNhau(cay1->trai, cay2->trai) &&
           laCayGiongNhau(cay1->phai, cay2->phai);
}

int main() {
    NutNhiPhan* sach1 = new NutNhiPhan(1, "Chuong 1");
    sach1->trai = new NutNhiPhan(2, "Muc 1.1");
    sach1->phai = new NutNhiPhan(3, "Muc 1.2");

    NutNhiPhan* sach2 = new NutNhiPhan(1, "Chuong 1");
    sach2->trai = new NutNhiPhan(2, "Muc 1.1");
    sach2->phai = new NutNhiPhan(3, "Muc 1.2");

    if (laCayGiongNhau(sach1, sach2))
        cout << "Hai cuon sach la ban copy cua nhau\n";
    else
        cout << "Hai cuon sach khong giong nhau\n";

    return 0;
}
