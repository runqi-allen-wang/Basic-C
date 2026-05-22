#include<iostream>


int main(){
    int n, m;
    std::cin >> n >> m;

    int A[n], B[m];
    for (int i = 0; i < n; ++i) std::cin >> A[i];
    for (int i = 0; i < m; ++i) std::cin >> B[i];

    int C[n+m];
    int lenC = 0;

    int i = 0, j = 0;
    while (i < n && j < m) {
        if (A[i] < B[j]) {
           if (lenC == 0 || C[lenC - 1] != A[i]) {
                C[lenC++] = A[i];
            }
            i++;
        } else if (A[i] > B[j]) {
            if (lenC == 0 || C[lenC - 1] != B[j]) {
                C[lenC++] = B[j];
            }
            j++;
        } else {
            int common = A[i];
            while (i < n && A[i] == common) i++;
            while (j < m && B[j] == common) j++;
        }
    }


    while (i < n) {
        if (lenC == 0 || C[lenC - 1] != A[i]) {
            C[lenC++] = A[i];
        }
        i++;
    }

    while (j < m) {
        if (lenC == 0 || C[lenC - 1] != B[j]) {
            C[lenC++] = B[j];
        }
        j++;
    }




    if (lenC == 0) {
        std::cout << "Empty" << std::endl;
    } else {
        for (int k = 0; k < lenC; ++k) {
            if (k > 0) std::cout << " ";
            std::cout << C[k];
        }
        std::cout << std::endl;
    }

    return 0;


}
