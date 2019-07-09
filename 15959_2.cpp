#include <iostream>
#include <vector>
#include <utility>

#define EQUAL 0
#define NOTEQ 1
using namespace std;

vector<pair< pair<string, string>, int> > parsed;
vector< pair< vector<string>, vector<string> > > set;

void parsing(string& input) {
    int flag;
    string word1, word2;

    string::iterator it = input.begin();

    while(it != input.end()) {
        pair< pair<string, string>, int> elem;
        while(*it != '=' && *it != '!') {
            word1.push_back(*it);
            it++;
        }

        if(*it == '=')
            flag = EQUAL;
        else
            flag = NOTEQ;

        it++;
        it++;


        while(it != input.end()) {
            if(*it != '&'){
                word2.push_back(*it);
                it++;   
            }
            else {
                break;
            }
        }

        if(it != input.end()) {
            it++;
            it++;
        }
        elem.first.first = word1;
        elem.first.second = word2;
        elem.second = flag;
        parsed.push_back(elem);
        word1.clear();
        word2.clear();
    }
}

int isVariable(pair<string, string> input) {
    int result = 0;
    if(input.first[0] == '-' || (int)input.first[0] < 10)
        result += 1;
    if(input.second[0] == '-' || (int)input.second[0] < 10)
        result += 2;

    return result;
}

// 변수, 변수
// 변수, 상수 || 상수, 변수
// 상수, 상수
void makeset(vector<pair< pair<string, string>, int> >& parsed) {
    for(const auto i : parsed) {
        switch (isVariable(i.first))
        {
        case 0:
            if(i.first.first != i.first.second) {
                // 쓸모 없는 상황
                // Ex. aa==aa
            }
            else {
                
            }
            break;
        case 1:
            /* code */
            break;
        case 2:
            /* code */
            break;
        case 3:
            if(i.first.first != i.first.second) {
                set.clear();
                return;
            }
            else {
                // 쓸모 없는 상황
                // Ex. 2019==2019
            }
            break;
        }
    }
}

int main() {
    string input;
    cin >> input;
    
    parsing(input);
    makeset(parsed);
    
}