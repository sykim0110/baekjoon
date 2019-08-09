// 숫자의 합
#include <iostream>
#include <string>

using namespace std;

int main() {
    int t;
    string input;
    int result = 0;
    cin >> t;
    cin >> input;
    for(const int i : input) {
        result += i-'0';
    }
    cout << result << endl;
    return 0;
}