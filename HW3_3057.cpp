#include <iostream>
using namespace std;

struct Node {
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node(int x = 0) {
        val = x;
        left = NULL;
        right = NULL;
        next = NULL;
    }
};

int main(){
    int n;
    cin >> n;

    Node** nodes = new Node*[n+1];
    int* leftId = new int[n+1];
    int* rightId = new int[n+1];
    int* nextId = new int[n+1];

    for (int i=1; i<=n; i++) {
        int val, left, right;
        cin >> val >> left >> right;
        nodes[i] = new Node(val);
        leftId[i] = left;
        rightId[i] = right;
        nextId[i] = 0;
    }

    for (int i=1; i<=n; i++){
        if (leftId[i] != 0) {
            nodes[i]->left = nodes[leftId[i]];
        }
        if (rightId[i] != 0) {
            nodes[i]->right = nodes[rightId[i]];
        }
    }

    int levelstart = 1;

    while(leftId[levelstart] != 0){
        int cur = levelstart;
        while(cur != 0){
            nodes[leftId[cur]]->next = nodes[rightId[cur]];
            nextId[leftId[cur]] = rightId[cur];
            if (nextId[cur] != 0) {
                nodes[rightId[cur]]->next = nodes[leftId[nextId[cur]]];
                nextId[rightId[cur]] = leftId[nextId[cur]];
            }
            cur = nextId[cur];
        }
        levelstart = leftId[levelstart];
    }
     for (int i = 1; i <= n; i++) {
        cout << nextId[i] << endl;
    }

    delete[] nodes;
    delete[] leftId;
    delete[] rightId;
    delete[] nextId;
    return 0;
}