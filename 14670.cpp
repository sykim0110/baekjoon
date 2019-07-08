/*
*
*   Baekjoon online judge Problem #14670
*   Problem Name : 병약한 병정
*
*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    int pillNum;
    int testcase;
    int deseaseNum;
    int desease;
    bool die = false;
    int pill[101];
    vector<int> ans;

    cin >> pillNum;

    for(int i = 0 ; i < 101 ; ++i) {
        pill[i] = -1;
    }
    for(int i = 0 ; i < pillNum ; ++i) {
        int pilleffect, pillName;
        cin >> pilleffect >> pillName;

        pill[pilleffect] = pillName;
    }

    cin >> testcase;

    for(int i = 0 ; i < testcase ; ++i) {
        die = false;
        cin >> deseaseNum;
        for(int j = 0 ; j < deseaseNum; ++j) {
            cin >> desease;

            if(desease < 0 || desease > 100) {
                die = true;
                continue;
            }

            if(pill[desease] == -1) {
                die = true;
                continue;
            }
            ans.push_back(pill[desease]);
        }

        if(die)
            cout << "YOU DIED" << endl;
        else {
            for(int k = 0 ; k < deseaseNum ; ++k) {
                cout << ans[k] << ' ';
            }
            cout << endl;
        }

        ans.clear();

    }

    return 0;
}