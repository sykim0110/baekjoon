#include <iostream>
#include <map>
#include <utility>
#include <algorithm>

using namespace std;

//map< pair<int, int>, int> dp;
int** c;

int find_max(int* a, int* b, int n, int before, int index) {
    if(n == index) {
        if(c[before][index] == -1){
            if(before == 0)
                c[before][index] = max(a[index-1], b[index-1]);
            else if(before == 1)
                c[before][index] =  b[index-1];
            else
                c[before][index] = a[index-1];
            }
    }
    else {
        if(c[before][index] == -1) {
            if(before == 0) {
                int temp1 = a[index-1] + find_max(a,b,n,1,index+1);
                int temp2 = b[index-1] + find_max(a,b,n,2,index+1);
                int temp3 = find_max(a,b,n,0,index+1); 
                c[before][index] = max(temp1, max(temp2, temp3));
            }
            else if(before == 1){
                int temp1 = b[index-1] + find_max(a,b,n,2,index+1);
                int temp2 = find_max(a,b,n,0,index+1); 
                c[before][index] = max(temp1, temp2);
            }
            else {
                int temp1 = a[index-1] + find_max(a,b,n,1,index+1);
                int temp2 = find_max(a,b,n,0,index+1); 
                c[before][index] = max(temp1, temp2);
            }
        }  
    }
    return c[before][index];
}

int main() {
    int t, n;
    cin >> t;
    for(int i = 0 ; i < t ; ++i) {
        cin >> n;
        int* a = new int[n];
        int* b = new int[n];
        c = new int*[3];
        for(int  j = 0; j < 3; ++j) {
            c[j] = new int[n+1];
        }

        for(int j = 0; j < 3 ; ++j) {
            for(int k = 0 ; k < n+1 ; ++k) {
                c[j][k] = -1;
            }
        }
        for(int j = 0 ; j < n ; ++j)
            cin >> a[j];
        for(int j = 0 ; j < n ; ++j)
            cin >> b[j];

        cout << find_max(a, b, n, 0, 1) << endl;

    }
}