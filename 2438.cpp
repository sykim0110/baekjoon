#include <iostream>
#include <string>
using namespace std;

int main() {
    int n;
    string star;
    cin >> n;
    for(int i = 0 ; i < n ; ++i) {
        star.append("*");
        cout << star << '\n';
    }

    return 0;
}