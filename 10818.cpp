#include <iostream>
#include <utility>
#include <limits.h>

using namespace std;

int main() {
    int n;
    int in;
    pair<int, int> a;
    a.first = INT_MAX;
    a.second = INT_MIN;
    cin >> n;

    for(int i = 0 ; i < n ; ++i) {
        cin >> in;
        if(in < a.first)
            a.first = in;
        if(in > a.second)
            a.second = in;
    }


    cout << a.first << ' ' << a.second << endl;

    return 0;
}

