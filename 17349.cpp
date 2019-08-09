#include <iostream>
#include <map>
#include <vector>

using namespace std;
vector<int> lie;
vector<int> player;
map<int, int> a;

int find1b(int lier) {
    a.clear();
    for(int i = 0 ; i < 9 ; ++i) {
        if(i != lier) {
            if(lie[i] == 0) {
                if(a[i] == 2) {
                    return -1;
                }
                else {
                    a[i] = 1;
                }
            }
            else {
                if(a[i] == 1) {
                    return -1;
                }
                else {
                    a[i] = 2;
                }
            }
        }
        else {
            if(lie[i] == 0) {
                if(a[i] == 1) {
                    return -1;
                }
                else {
                    a[i] = 2;
                }
            }
            else {
                if(a[i] == 2) {
                    return -1;
                }
                else {
                    a[i] = 1;
                }
            }
        }
    }
    int index = -1;
    for(int i = 0 ; i < 9 ; ++i) {
        if(a[i] == 2)
            if(index != -1) {
                return -1;
            }
            else {
                index = i;
            }
    }

    return index;

}

int main() {
    int l, p;
    for(int i = 0 ; i < 9 ; ++i) {
        cin >> l >> p;
        lie.push_back(l);
        player.push_back(p);
    }

    for(int i = 0 ; i < 9 ; ++i) {
        if(find1b(i) != -1) {
            cout << find1b(i) << endl;
            return 0;
        }
    }
    cout << "-1" << endl;
    return 0;


}