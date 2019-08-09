#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

map<int, int> b;

int count(int i) {
    if(i == 1) {
        return 0;
    }
    if(b[i] == 0){
        if(i%6 == 0) {
            b[i] = 1 + min(count(i/3), min(count(i/2), count(i-1)));
        }
        else if(i%3 == 0){
            b[i] = 1 + min(count(i/3), count(i-1));
        }
        else if(i%2 == 0) {
            b[i] = 1 + min(count(i/2), count(i-1));
        }
        else
            b[i] = 1 + count(i-1);
    }
    return b[i];
}
int main() {
    int a;
    cin >> a;
    cout << count(a) << endl;
    return 0;
}