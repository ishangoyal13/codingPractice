#include <iostream>
#include <vector>
#include <algorithm>
#define MIN_HEAP 0;
#define MAX_HEAP 1;

using std::vector;
using std::cin;
using std::cout;

// Make Your Choice Here
// choose between MIN_HEAP & MAX_HEAP
int CHOICE = MIN_HEAP;

class Heap {
private:
    vector<int> data;
    int size;

    void ScanInput() {
        int n;
        cin >> n;
        size = n + 1;
        data.resize(size);
        for (int i = 1; i < size; ++i)
            cin >> data[i];
    }
    int parent(const int& index) {
        return index / 2;
    }
    int lchild(const int& i) {
        return 2 * i;
    }
    int rchild(const int& i) {
        return 2 * i + 1;
    }
    bool comp(int a, int b) {
        if (CHOICE)
            return a > b;
        return a < b;
    }
    void SiftDown(int i) {
        int l, r, m_ind = i;
        do
        {
            l = 2 * i;
            r = 2 * i + 1;
            if (l < size&& comp(data[l], data[m_ind]))
                m_ind = l;
            if (r < size && comp(data[r], data[m_ind]))
                m_ind = r;
            if (m_ind != i) {
                std::swap(data[m_ind], data[i]);
                i = m_ind;
                SiftDown(m_ind);
            }
        } while (m_ind != i);
    }

    void SiftUp(int i) {
        while (i > 1 && comp(data[i], data[i / 2])) {
            std::swap(data[i], data[i / 2]);
            i /= 2;
        }
    }

    void CreateHeap() {
        for (int i = (size - 1) / 2; i > 0; --i) {
            SiftDown(i);
        }
    }
    void PrintHeap() {
        for (int i = 1; i < size; ++i)
            cout << data[i] << ' ';
    }
    void Heapify() {
        int s = size;
        int lastind = size - 1;
        for (int i = 1; i < s; ++i) {
            std::swap(data[1], data[lastind]);
            lastind--;
            size--;
            SiftDown(1);
        }
        size = s;
    }
public:
    void Solve() {
        ScanInput();
        CreateHeap();
        Heapify();
        PrintHeap();
    }
};

int main() {
    Heap h;
    h.Solve();
    return 0;
}