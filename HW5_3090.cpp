#include <iostream>
using namespace std;

struct Node {
    int val;
    Node* left;
    Node* right;

    Node(int x) {
        val = x;
        left = NULL;
        right = NULL;
    }
};

void insertNode(Node*& root, int x) {
    if (root == NULL) {
        root = new Node(x);
        return;
    }

    Node* cur = root;

    while (true) {
        if (x < cur->val) {
            if (cur->left == NULL) {
                cur->left = new Node(x);
                return;
            } else {
                cur = cur->left;
            }
        } else {
            if (cur->right == NULL) {
                cur->right = new Node(x);
                return;
            } else {
                cur = cur->right;
            }
        }
    }
}

void searchPath(Node* root, int k) {
    Node* cur = root;
    bool first = true;

    while (cur != NULL) {
        if (!first) {
            cout << " ";
        }
        cout << cur->val;
        first = false;

        if (cur->val == k) {
            return;
        } else if (k < cur->val) {
            cur = cur->left;
        } else {
            cur = cur->right;
        }
    }

    if (!first) {
        cout << " ";
    }
    cout << -1;
}
int main() {
    int n, k;
    cin >> n >> k;

    Node* root = NULL;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        insertNode(root, x);
    }

    searchPath(root, k);

    return 0;
}