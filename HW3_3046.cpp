#include <iostream>
using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
void flatten(TreeNode* root) {
    TreeNode* cur = root;
    while (cur != NULL) {
        if (cur -> left != NULL) {
            TreeNode* pre = cur -> left;
            while (pre -> right != NULL) {
                pre = pre -> right;
            }
            pre -> right = cur -> right;
            cur -> right = cur -> left;
            cur -> left = NULL;
        }
        cur = cur -> right;
    }
};
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
    flatten(root);

    TreeNode* cur = root;
    while (cur != NULL) {
        cout << cur->val;
        if (cur->right != nullptr) cout << " ";
        cur = cur->right;
    }

    cout << endl;

    delete[] nodes;
    delete[] leftId;
    delete[] rightId;

    return 0;
}