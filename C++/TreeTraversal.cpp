#include <iostream>
#include<queue>
#include<stack>
#include <vector>
#include <algorithm>
#if defined(__unix__) || defined(__APPLE__)
#include <sys/resource.h>
#endif

using std::stack;
using std::vector;
using std::ios_base;
using std::cin;
using std::cout;
using std::deque;

/*
    Input/Output :
    Input:
    5 // number of nodes
    4 1 2 // node 4 has children 1 and 2
    2 3 4 // 2 has children 3 & 4
    5 -1 -1 // -1 indicates no child. so 5 is a leaf
    1 -1 -1
    3 -1 -1

    Output:
    1 2 3 4 5 // (inorder traversal)
    4 2 1 3 5 // (pre-order)
    1 3 2 5 4 // (post-order)

*/
class TreeOrders {
    int n;
    vector <int> key;
    vector <int> left;
    vector <int> right;

public:
    void read() {
        cin >> n;
        key.resize(n);
        left.resize(n);
        right.resize(n);
        for (int i = 0; i < n; i++) {
            cin >> key[i] >> left[i] >> right[i];
        }
    }


    vector <int> pre_order(int pos) {
        vector<int> result(n);
        int i = 0;
        stack<int> stk;
        if (key[pos] > -1)
            stk.push(pos);
        while (!stk.empty()) {
            int tm = stk.top();
            result[i++] = key[tm];
            stk.pop();
            if (right[tm] > -1)
                stk.push(right[tm]);
            if (left[tm] > -1)
                stk.push(left[tm]);
        }
        return result;
    }

    vector <int> in_order(int pos) {
        vector<int> result(n);
        int i = 0;
        stack<int> stk;
        while (pos > -1) {
            stk.push(pos);
            pos = left[pos];
        }
        while (!stk.empty()) {
            int tm = stk.top();
            stk.pop();
            result[i++] = key[tm];
            tm = right[tm];
            while (tm > -1) {
                stk.push(tm);
                tm = left[tm];
            }
        }
        return result;
    }

    vector <int> post_order(int pos) {
        vector<int> result(n);
        int i = 0;
        stack<int> s1;
        stack<int> s2;
        s1.push(pos);
        while (!s1.empty()) {
            int tm = s1.top();
            s2.push(tm);
            s1.pop();

            if (left[tm] > -1)
                s1.push(left[tm]);
            if (right[tm] > -1)
                s1.push(right[tm]);
        }
        while (!s2.empty()) {
            result[i++] = key[s2.top()];
            s2.pop();
        }
        return result;
    }
};

void print(vector <int> a) {
    for (size_t i = 0; i < a.size(); i++) {
        if (i > 0) {
            cout << ' ';
        }
        cout << a[i];
    }
    cout << '\n';
}

int main_with_large_stack_space() {
    ios_base::sync_with_stdio(0);
    TreeOrders t;
    t.read();
    print(t.in_order(0));
    print(t.pre_order(0));
    print(t.post_order(0));
    return 0;
}

int main(int argc, char** argv)
{
#if defined(__unix__) || defined(__APPLE__)
    // Allow larger stack space
    const rlim_t kStackSize = 16 * 1024 * 1024;   // min stack size = 16 MB
    struct rlimit rl;
    int result;

    result = getrlimit(RLIMIT_STACK, &rl);
    if (result == 0)
    {
        if (rl.rlim_cur < kStackSize)
        {
            rl.rlim_cur = kStackSize;
            result = setrlimit(RLIMIT_STACK, &rl);
            if (result != 0)
            {
                std::cerr << "setrlimit returned result = " << result << std::endl;
            }
        }
    }
#endif

    return main_with_large_stack_space();
}

