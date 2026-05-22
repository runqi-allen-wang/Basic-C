#include <iostream>
using namespace std;

int main() {
    int targetID, n, upp;
    char c;

    cin >> targetID;
    cin >> c;
    cin >> n;

    if (c == 'a') upp = 3;
    else if (c == 'b') upp = 6;
    else upp = 9;

    int* arr = new int[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int* q = new int[n];
    int head = 0, tail = 0;  

    for (int i = 0; i < n; i++) {
        while (head < tail && q[head] < i - 9) {
            head++;
        }

        if (arr[i] != targetID) {
            cout << 0;
        } else {
            int successCount = tail - head;  

            if (successCount < upp) {
                cout << 1;
                q[tail++] = i;   
            } else {
                cout << -1;      
            }
        }

        if (i < n - 1) cout << ' ';
    }


    delete[] arr;
    delete[] q;
    return 0;
}