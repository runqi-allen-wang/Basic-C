#include <iostream>
using namespace std;

const int MAXN = 200000;

int a[MAXN];

int main() {
    int n, q;
    cin >> n >> q;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for (int i = 0; i < q; i++) {
        int x;
        cin >> x;

        int l = 0, r = n;  

        while (l < r) {
            int mid = l + (r - l) / 2;

            if (a[mid] >= x) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }

        if (l == n) {
            cout << 0 << endl;
        } else {
            cout << l + 1 << endl;
        }
    }

    return 0;
}