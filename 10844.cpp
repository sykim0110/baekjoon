// 10844번
// 쉬운 계단 수

#include <iostream>
#include <map>
#include <algorithm>

using namespace std;
map<pair<int, int>, int> b;

int count_digit(int start, int left) {
    if(start != 9) {
        return count_digit(start-1, left-1) + count_digit(start+1, left-1); 
    }
    else {

    }
}

int count(int n) {
    int result = 0;
    for(int i = 1; i < 10 ; ++i) {
        result += count_digit(i, n-1);
    }
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