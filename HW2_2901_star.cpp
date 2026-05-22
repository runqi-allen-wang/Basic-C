#include<iostream>
using namespace std;

int main(){
    int n;
    cin>>n;
    int* h = new int[n + 1];
    int* ans = new int[n + 1];
    int* st = new int[n + 1];   

    for (int i = 1; i <= n; i++) {
        cin >> h[i];
    }

    int top = 0; 

    for (int i=n; i>0; i--){
        while( top > 0 && h[st[top]] <= h[i]){
            top--;
        }
        if (top ==0) {ans[i] = 0;}
        else {ans[i] = st[top];}
        st[++top] = i;
    }

    for (int i = 1; i <= n; i++) {
        cout << ans[i] << " ";
    }

    delete[] h;
    delete[] ans;
    delete[] st;
    return 0;
}