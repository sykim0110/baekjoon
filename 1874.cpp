#include <iostream>
#include <stack>
#include <queue>

using namespace std;

int main() {
    int num;
    cin >> num;
    int input;
    stack<int> s;
    queue<char> s2;
    int top = -1;
    int current = 1;
    bool failed = true;

    for(int i = 0; i < num ; ++i) {
        cin >> input;
        if(top < input) {
            for(int j = current ; j <= input ; ++j) {
                s.push(j);
                s2.push('+');
            }
            current = input + 1;

            s.pop();
            s2.push('-');
        }
        // top >= input 
        else {
            if(top != input) {
                //invalid
                break;
            }
            else if(top == input) {
                s.pop();
                s2.push('-');
            }
        }

        if(!s.empty())
            top = s.top();
        else
            top = -1;
    }
}