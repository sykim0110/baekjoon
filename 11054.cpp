#include <iostream>
#include <map>
#include <algorithm>
#include <utility>
#include <algorithm>

using namespace std;
int n;
int* v;
map<pair<int, int>,int> dp;
map<pair<int, int>, int> dpi;
map<pair<int, int>, int> dpd;

int find_decrease(int before, int index);

int find_increase(int before, int index) {
    pair<int, int> a = make_pair(before, index);
    if(index >= n)
        return 0;

    if(dp[a] == 0) {
        for(int i = index; i < n; ++i) {
            if(v[i] > before) {
                if(dpi[a] == 0) {
                    int temp = 1 + find_increase(v[i], i+1);
                    if(temp > dpi[a])
                        dpi[a] =temp;
                }
                
            }
            else if(v[i] < before) {
                if(dpd[a] == 0) {
                    int temp = 1 + find_decrease(v[i], i+1);
                    if(temp > dpd[a])
                        dpd[a] =temp;

                }
            }
        }
        dp[a] = max(dpi[a], dpd[a]);
        
    }
    return dp[a];
}

int find_decrease(int before, int index) {
    pair<int, int> a = make_pair(before, index);
    if(index >= n)
        return 0;
    if(dpd[a] == 0) {
        for(int i = index; i < n; ++i) {
            if(v[i] < before) {
                int temp = 1 + find_decrease(v[i], i+1);
                if(temp > dpd[a])
                    dpd[a] =temp;
            }
        }
    }
    return dpd[a];
}

int main() {
    cin >> n;
    v = new int[n];
    for(int i = 0 ; i < n ; ++i) {
        cin >> v[i];
    }

    cout << find_increase(-1, 0) << endl;

    return 0;
}