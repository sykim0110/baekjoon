#include <iostream>
#include <string>
using namespace std;

int main() {
    int n;
    char* star;
    cin >> n;
    
    for(int i = 1 ; i <= n; ++i) {
        for(int j = 0 ; j < n-i ; ++j ) {
            cout << ' ';
        }
        for(int j = 0 ; j < i ; ++j ) {
            cout << '*';
        }
        cout << endl;
    }

    return 0;
}