#include <iostream>
#include <stack>

using namespace std;

class MyQueue {
private:
    stack<int> s1;
    stack<int> s2;

    void reverse() {
        if (s2.empty()) {
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }
    }
public:
    MyQueue() {
        
    }
    
    void push(int x) {
        s1.push(x);
    }
    
    int pop() {
        reverse();
        int x = s2.top();
        s2.pop();
        return x;
    }
    
    int peek() {
        reverse();
        return s2.top();
    }
    
    bool empty() {
        return s1.empty() && s2.empty();
    }
};

void init();

int main() {
    init();

    MyQueue q;
    q.push(1);
    q.push(2);
    cout << q.peek() << '\n';
    cout << q.pop() << '\n';
    cout << boolalpha << q.empty() << '\n';
}

void init() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}