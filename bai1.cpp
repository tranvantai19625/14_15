#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Node {
    string title;
    int pages;
    int index;
    vector<Node*> children;
    Node(string t, int p, int idx) : title(t), pages(p), index(idx) {}
};

int countChapters(Node* root) {
    return root ? root->children.size() : 0;
}

void findLongest(Node* root) {
    if (!root || root->children.empty()) return;
    Node* res = root->children[0];
    for (auto c : root->children) if (c->pages > res->pages) res = c;
    cout << "Chuong dai nhat: " << res->title << " (" << res->pages << " trang)\n";
}

bool deleteAndUpdate(Node* parent, string target) {
    for (auto it = parent->children.begin(); it != parent->children.end(); ++it) {
        if ((*it)->title == target) {
            parent->pages -= (*it)->pages;
            parent->children.erase(it);
            return true;
        }
        if (deleteAndUpdate(*it, target)) return true;
    }
    return false;
}

int main() {
    Node* book = new Node("Giao trinh", 100, 0);
    book->children.push_back(new Node("Chuong 1", 30, 1));
    book->children.push_back(new Node("Chuong 2", 70, 2));
    
    cout << "So chuong: " << countChapters(book) << endl;
    findLongest(book);
    return 0;
}