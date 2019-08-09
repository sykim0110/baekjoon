#include <iostream>

using namespace std;

int main() {
    int a;
    cin >> a;
    //ios_base::sync_with_stdio(false);
    for(int i = a ; i >= 1 ; --i) {
        cout << i << '\n';
    }
    return 0;
}