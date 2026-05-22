#include <iostream>
using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

long long dfs(TreeNode* node, long long sum) {
    if (node == NULL) return 0;
    sum = sum * 10 + node->val;
    if (node->left == NULL && node->right == NULL) return sum;
    return dfs(node->left, sum) + dfs(node->right, sum);
}

int main(){
    int n;
    cin >> n;

    TreeNode** nodes = new TreeNode*[n+1];
    int* leftId = new int[n+1];
    int* rightId = new int[n+1];
    for (int i = 1; i <= n; i++) {
        int val, left, right;
        cin >> val >> left >> right;
        nodes[i] = new TreeNode(val);
        leftId[i] = left;
        rightId[i] = right;
    }
    for (int i = 1; i <= n; i++) {
        if (leftId[i] != 0) {
            nodes[i] -> left = nodes[leftId[i]];
        }
        if (rightId[i] != 0) {
            nodes[i] -> right = nodes[rightId[i]];
        }
    }

    TreeNode* root = nodes[1];
    long long result = dfs(root, 0);
    cout << result << endl;

    delete[] nodes;
    delete[] leftId;
    delete[] rightId;

    return 0;
}