#include <iostream>
using namespace std;

struct Node{
    int left;
    long long weight;
    int right;
};

Node* tree;
long long ans = 0;

void dfs(int root, int depth){
    if (root == 0){return;}
    int l = tree[root].left;
    int r = tree[root].right;

    if(l == 0 && r == 0){
        ans += tree[root].weight * depth;
        return;
    }

    dfs(l, depth + 1);
    dfs(r, depth + 1);
}

int main(){
    int n;
    cin >> n;

    tree = new Node[n+1];
    int* isLeaf = new int[n+1];

    for (int i = 1; i <= n; i++){
        isLeaf[i] = 0;
    }

    for (int i = 1; i <= n; i++){
        int l, w, r;
        cin >> l >> w >> r;

        tree[i].left = l;
        tree[i].weight = w;
        tree[i].right = r;

        if (l != 0){
            isLeaf[l] = 1;
        }
        if (r != 0){
            isLeaf[r] = 1;
        }
    }

    int root = 1;
    for (int i = 1; i <= n; i++) {
        if (isLeaf[i] == 0) {
            root = i;
            break;
        }
    }

    dfs(root, 0);

    cout << ans << endl;

    delete[] tree;
    delete[] isLeaf;

    return 0;
}