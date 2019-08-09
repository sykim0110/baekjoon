#include <iostream>

using namespace std;

int main() {
    int a;
    cin >> a;
    //ios_base::sync_with_stdio(false);
    for(int i = 0 ; i < a ; ++i) {
        cout << i+1 << '\n';
    }
    return 0;
}