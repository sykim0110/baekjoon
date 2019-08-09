#include <iostream>
#include <map>
#include <algorithm>

using namespace std;
map<int, int> b;

int count(int i) {
    if(i == 0 || i == 1){
        return 1;
    }
    if(i == 2) {
        return 2;
    }
    if(b[i] == 0){
        b[i] = count(i-1) + count(i-2) + count(i-3);
    }

    return b[i];
}

int main() {
    int t, n;
    cin >> t;
    for(int i = 0 ; i < t ; ++i){
        cin >> n;
        cout << count(n) << '\n';
    }
    
    return 0;
}