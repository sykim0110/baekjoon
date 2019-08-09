#include <iostream>
#include <string>
using namespace std;

int main() {
    int n;
    string star;
    cin >> n;
    for(int i = 0 ; i < n ; ++i) {
        star.append("*");
    }
    for(int i = 0 ; i < n ; ++i) {
        cout << star.substr(0, n-i) << endl;
    }

    return 0;
}