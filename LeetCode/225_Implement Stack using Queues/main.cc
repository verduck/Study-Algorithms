#include <iostream>
#include <queue>

using namespace std;

class MyStack {
    queue<int> q;
public:
    MyStack() {
        
    }
    
    void push(int x) {
        int n = q.size();
        q.push(x);

        for (int i = 0; i < n; i++) {
            x = q.front();
            q.pop();
            q.push(x);
        }
    }
    
    int pop() {
        int x = q.front();
        q.pop();
        return x;
    }
    
    int top() {
        return q.front();
    }
    
    bool empty() {
        return q.empty();
    }
};


void init();

int main() {
    init();

    MyStack myStack;
    myStack.push(1);
    myStack.push(2);
    cout << myStack.top() << '\n'; // return 2
    cout << myStack.pop() << '\n'; // return 2
    cout << boolalpha << myStack.empty() << '\n';
}

void init() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}