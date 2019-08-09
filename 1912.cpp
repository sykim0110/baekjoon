#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;

int main() {
    int n, temp;
    cin >> n;
    vector<int> input;
    for(int i = 0 ; i < n ; ++i) {
        cin >> temp;
        input.push_back(temp);
    }
    int max = INT_MIN;
    int result = 0;
    int index = 0;
    for(int i = 0; i < n ; ++i) {
        result += input[i];
        if(max < result)
            max = result;
        if(result < 0)
            result = 0;
        
    }

    cout << max << endl;
    return 0;
}