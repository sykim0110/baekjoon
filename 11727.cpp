#include <iostream>
#include <map>
#include <algorithm>

using namespace std;
map<int, int> b;

int count(int i) {
    if(i == 1){
        return 1;
    }
    if(i == 2) {
        return 3;
    }
    if(b[i] == 0){
        b[i] = (count(i-1)+2*count(i-2))%10007;
    }
    
    return b[i];
}

int main() {
    int n;
    cin >> n;
    
    cout << count(n) << '\n';
    return 0;
}