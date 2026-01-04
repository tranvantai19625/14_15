#include <iostream>
#include <string>

using namespace std;

struct BinaryNode {
    int index;
    string title;
    BinaryNode *left, *right;

    BinaryNode(int idx, string t) : index(idx), title(t), left(nullptr), right(nullptr) {}
};


bool isCopy(BinaryNode* r1, BinaryNode* r2) {
    if (!r1 && !r2) return true;
    if (!r1 || !r2) return false;
    return (r1->index == r2->index && r1->title == r2->title) &&
           isCopy(r1->left, r2->left) &&
           isCopy(r1->right, r2->right);
}

int main() {
    // Tao cay 1
    BinaryNode* tree1 = new BinaryNode(1, "Muc luc A");
    tree1->left = new BinaryNode(2, "Chuong 1");

    // Tao cay 2 (Copy cua cay 1)
    BinaryNode* tree2 = new BinaryNode(1, "Muc luc A");
    tree2->left = new BinaryNode(2, "Chuong 1");

    if (isCopy(tree1, tree2)) {
        cout << "Hai cuon sach la ban copy cua nhau" << endl;
    } else {
        cout << "Hai cuon sach khong giong nhau" << endl;
    }
    return 0;
}