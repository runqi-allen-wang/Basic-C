#include<iostream>
using namespace std;

int main(){
    int n;
    std::cin >> n;

    int* in = new int[n];
    int* out = new int[n];
    int* st = new int[n];   

    for (int i = 0; i < n; i++) {
        cin >> in[i];
    }

    for (int i = 0; i < n; i++) {
        cin >> out[i];
    }
    
    
    int top = -1;
    int j = 0;  

    for (int i = 0; i < n; i++) {
        st[++top] = in[i]; 

        while (top >= 0 && st[top] == out[j]) {
            top--; 
            j++;   
        }
    }

    if (j == n) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    delete[] in;
    delete[] out;
    delete[] st;

    return 0;
}