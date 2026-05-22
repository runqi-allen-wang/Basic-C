#include <iostream>
using namespace std;

void mySwap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

class MinHeap {
private:
    int* heap;
    int size;

public:
    MinHeap(int n) {
        heap = new int[n + 5];
        size = 0;
    }

    ~MinHeap() {
        delete[] heap;
    }

    void push(int value) {
        heap[++size] = value;

        int idx = size;

        while (idx > 1) {
            int parent = idx / 2;

            if (heap[parent] > heap[idx]) {
                mySwap(heap[parent], heap[idx]);
                idx = parent;
            } else {
                break;
            }
        }
    }

    int pop() {
        if (size == 0) {
            return -1;
        }

        int minValue = heap[1];

        heap[1] = heap[size];
        size--;

        int idx = 1;

        while (true) {
            int leftChild = idx * 2;
            int rightChild = idx * 2 + 1;
            int smallestChild = idx;

            if (leftChild <= size && heap[leftChild] < heap[smallestChild]) {
                smallestChild = leftChild;
            }

            if (rightChild <= size && heap[rightChild] < heap[smallestChild]) {
                smallestChild = rightChild;
            }

            if (smallestChild == idx) {
                break;
            }

            mySwap(heap[idx], heap[smallestChild]);
            idx = smallestChild;
        }

        return minValue;
    }
};

int main() {
    int n;
    cin >> n;

    MinHeap heap(n);

    for (int i = 0; i < n; i++) {
        int op;
        cin >> op;

        if (op == 1) {
            int x;
            cin >> x;
            heap.push(x);
        } else if (op == 2) {
            cout << heap.pop() << endl;
        }
    }

    return 0;
}