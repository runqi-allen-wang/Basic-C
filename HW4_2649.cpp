#include <iostream>
using namespace std;

int main() {
    int N, X, Y;
    cin >> N >> X >> Y;

    int* leftChild = new int[N + 1];
    int* rightChild = new int[N + 1];
    int* parent = new int[N + 1];
    int* visited = new int[N + 1];

    for (int i = 1; i <= N; i++) {
        parent[i] = 0;
        visited[i] = 0;
    }

    for (int i = 1; i <= N; i++) {
        int A, B;
        cin >> A >> B;

        leftChild[i] = A;
        rightChild[i] = B;

        if (A != 0) {
            parent[A] = i;
        }

        if (B != 0) {
            parent[B] = i;
        }
    }

    // 标记 X 到根路径上的所有祖先
    int cur = X;
    while (cur != 0) {
        visited[cur] = 1;
        cur = parent[cur];
    }

    // 从 Y 往上找，第一个被标记过的点就是 LCA
    cur = Y;
    while (cur != 0) {
        if (visited[cur] == 1) {
            cout << cur << endl;
            break;
        }
        cur = parent[cur];
    }

    delete[] leftChild;
    delete[] rightChild;
    delete[] parent;
    delete[] visited;

    return 0;
}