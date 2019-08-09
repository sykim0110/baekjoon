#include <iostream>
#include <algorithm>

using namespace std;
int n;
int* v;
int* dp;

int find_max(int index) {
    if(index >= n)
        return 0;
    if(dp[index] == -1) {
        if(index == n-1)
            dp[index] = v[index];
        else if(index == n-2)
            dp[index] = v[index] + v[index +1];
        else
            dp[index] = max(find_max(index+1), max(v[index]+find_max(index+2), v[index]+v[index+1]+find_max(index+3)));
    }
    return dp[index];
}

int main() {
    cin >> n;
    v = new int[n];
    dp = new int[n];
    for(int i = 0 ; i < n ; ++i) {
        cin >> v[i];
    }
    for(int i = 0 ; i < n ; ++i) {
        dp[i] = -1;
    }
    cout << find_max(0) << endl;

    delete v;
    delete dp;

    return 0;
}