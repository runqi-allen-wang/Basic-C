#include <iostream>
using namespace std;
int getKthsmall (int n, int m, int* a, int* b, int k){
    if (n < m) {return getKthsmall(m,n,b,a, k);}
    if (m == 0) {return a[k-1];}
    if (k == 1) {return a[0] < b[0] ? a[0] : b[0];}
    int i;
    if (m < k / 2) i = m;
    else i = k / 2;
    int j = k - i;
    if (a[j-1] < b[i-1]) {
        return getKthsmall(n-j, m, a+j, b, k-j);
    } else if (a[j-1] > b[i-1]) {
        return getKthsmall(n, m-i, a, b+i, k-i);
    } else {
        return a[j-1];
    }
}
int main(){
    int n, m, q;
    cin >> n >> m >> q;
    int a[n], b[m];
    for (int i=0; i<n; i++){
        cin >> a[i];
    }
    for (int i=0; i<m; i++){
        cin >> b[i];
    }
    for (int i=0; i<q; i++){
        int k;
        cin >> k;
        cout << getKthsmall(n, m, a, b, k) << endl;
    }
    return 0;
}