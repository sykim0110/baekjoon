#include <iostream>
#include <map>
#include <algorithm>
#include <utility>

using namespace std;
int n;
int* v;
map<pair<int, int>, int> dp;

int find_max(int before, int index) {
    pair<int, int> a = make_pair(before, index);
    if(index >= n)
        return 0;
    if(dp[a] == 0) {
        for(int i = index; i < n; ++i) {
            if(v[i] > before) {
                int temp = v[i] + find_max(v[i], i+1);
                if(temp > dp[a])
                    dp[a] =temp;
            }
        }
    }
    return dp[a];
}

int main() {
    cin >> n;
    v = new int[n];
    for(int i = 0 ; i < n ; ++i) {
        cin >> v[i];
    }

    cout << find_max(-1, 0) << endl;

    return 0;
}