#include <iostream>
using namespace std;

struct Nut {
    int giaTri;
    Nut* trai;
    Nut* phai;

    Nut(int x) : giaTri(x), trai(nullptr), phai(nullptr) {}
};

Nut* taoCayMau() {
    Nut* n1 = new Nut(1);
    Nut* n2 = new Nut(2);
    Nut* n3 = new Nut(3);

    n1->trai = n2;
    n1->phai = n3;

    return n1;
}

bool laCayGiongNhau(Nut* cay1, Nut* cay2) {
    if (!cay1 && !cay2) return true;
    if (!cay1 || !cay2) return false;

    if (cay1->giaTri != cay2->giaTri)
        return false;

    return laCayGiongNhau(cay1->trai, cay2->trai) &&
           laCayGiongNhau(cay1->phai, cay2->phai);
}

int main() {
    Nut* cay1 = taoCayMau();
    Nut* cay2 = taoCayMau();

    if (laCayGiongNhau(cay1, cay2))
        cout << "Hai cay nhi phan giong nhau\n";
    else
        cout << "Hai cay nhi phan khong giong nhau\n";

    return 0;
}
