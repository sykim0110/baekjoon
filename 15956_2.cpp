#include <iostream>
#include <vector>
#include <utility>

#define EQUAL 0
#define NOTEQ 1
using namespace std;

vector<pair< pair<string, string>, int> > parsed;
vector< pair< vector<string>, vector<string> > > set;
bool alwaysFlag = true;

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
    /* 
    cout << "input.first[0] is" << input.first[0] << endl;
    cout << "(int)input.first[0] is " << (int)input.first[0] << endl;
    cout << "input.second[0] is " << input.second[0] << endl;
    cout << "input.second[0] is " << (int)input.second[0] << endl;
    */
    if(input.first[0] == '-' || ((int)input.first[0] <58 && (int)input.first[0] > 47))
        result += 1;
    if(input.second[0] == '-' || ((int)input.second[0] <58 && (int)input.second[0] > 47))
        result += 2;
    //cout << "case is : " << result << endl;
    return result;
}

int countNumber(vector<string> input) {
    int count = 0;
    for(const string& s : input) {
        if(s[0] == '-' || ((int)s[0] <58 && (int)s[0] > 47))
            count++;
    }
    //cout << "count is "<<count << endl;
    return count;
}

int isExist(string input) {
    for(int i = 0 ; i < set.size() ; ++i) {
        for(int j = 0 ; j < set[i].first.size() ; ++j) {
            if(set[i].first[j] == input)
                return i;
        }
    }
    return -1;
}

bool isExistCounterpart(int index, string input) {
    for(int i = 0; i < set[index].second.size() ; ++i) {
        if(set[index].second[i] == input) {
            return true;
        }
    }
    return false;
}

// 변수, 변수
// 변수, 상수 || 상수, 변수
// 상수, 상수
void makeset(vector<pair< pair<string, string>, int> >& parsed) {
    for(const pair< pair<string, string>, int> i : parsed) {
        int index1 = isExist(i.first.first);
        int index2 = isExist(i.first.second);
        //cout << "index is " << index1 << " " <<index2 << endl;
        switch (isVariable(i.first))
        {
        case 0:
            if(i.first.first != i.first.second) {
                if(i.second == EQUAL) {
                    // Ex. a == b
                    if(index1 == -1 && index2 == -1) {
                        pair< vector<string>, vector<string> > temp;
                        temp.first.push_back(i.first.first);
                        temp.first.push_back(i.first.second);
                        set.push_back(temp);
                    }
                    else if(index1 == -1 && index2 != -1) {
                        if(isExistCounterpart(index2, i.first.first)) {
                            set.clear();
                            alwaysFlag = false;
                            return;
                        }
                        else {
                            set[index2].first.push_back(i.first.first);
                        }
                    }
                    else if(index1 != -1 && index2 == -1) {
                        if(isExistCounterpart(index1, i.first.second)) {
                            set.clear();
                            alwaysFlag = false;
                            return;
                        }
                        else {
                            set[index1].first.push_back(i.first.second);
                        }
                    }
                    else {
                        if(index1 == index2) {
                            // 이미 존재하는 경우
                            // pass
                        }
                        else {
                            // 가능하지 않는 경우
                        }
                    }
                }
                // i.second == NOTEQ
                else {
                    // Ex. a != b
                    if(index1 == -1 && index2 == -1) {
                        pair< vector<string>, vector<string> > temp;
                        temp.first.push_back(i.first.first);
                        temp.second.push_back(i.first.second);
                        set.push_back(temp);
                    }
                    else if(index1 == -1 && index2 != -1) {
                        if(isExistCounterpart(index2, i.first.first)) {
                            // 이미 존재하는 경우
                            // pass
                        }
                        else {
                            // 존재하지 않는 경우
                            set[index2].second.push_back(i.first.first);
                        }
                    }
                    else if(index1 != -1 && index2 == -1) {
                        if(isExistCounterpart(index1, i.first.second)) {
                            // 이미 존재하는 경우
                            // pass
                        }
                        else {
                            // 존재하지 않는 경우
                            set[index1].second.push_back(i.first.second);
                        }
                    }
                    else {
                        if(index1 == index2) {
                            set.clear();
                            alwaysFlag = false;
                            return;
                        }
                        else {
                            // 존재하지 않는 경우..?(불확실))
                        }
                    }
                }
            }
            // i.first.first == i.first.second
            else {
                if(i.second == EQUAL) {
                    // 쓸모 없는 상황
                    // Ex. aa == aa
                }
                else {
                    // 항상 거짓이 되는 상황
                    // Ex. aa != aa
                    set.clear();
                    return;
                }
            }
            break;
        // 상수, 변수 case
        case 1:
        case 2:
            if(i.second == EQUAL) {
                if(index1 == -1 && index2 == -1) {
                    pair< vector<string>, vector<string> > temp;
                    temp.first.push_back(i.first.first);
                    temp.first.push_back(i.first.second);
                    set.push_back(temp);
                }
                else if(index1 == -1 && index2 != -1) {
                    if(isExistCounterpart(index2, i.first.first)) {
                        set.clear();
                        alwaysFlag = false;
                        return;
                    }
                    else {
                        //넣을 곳에 이미 상수가 있는 지 확인 필요!
                        if(countNumber(set[index2].first) == 1) {
                            set.clear();
                            alwaysFlag = false;
                            return;
                        }
                        else {
                            set[index2].first.push_back(i.first.first);
                        }
                    }
                }
                else if(index1 != -1 && index2 == -1) {
                    if(isExistCounterpart(index1, i.first.second)) {
                        set.clear();
                        alwaysFlag = false;
                        return;
                    }
                    else {
                        //넣을 곳에 이미 상수가 있는 지 확인 필요!
                        if(countNumber(set[index1].first) == 1) {
                            set.clear();
                            alwaysFlag = false;
                            return;
                        }
                        else {
                            set[index1].first.push_back(i.first.second);
                        }
                    }
                }
                else {
                    if(index1 == index2) {
                        // 이미 존재하는 경우
                        // pass
                    }
                    else {
                        // 가능하지 않는 경우
                    }
                }
            }
            // i.second == NOTEQ
            else {
                if(index1 == -1 && index2 == -1) {
                    pair< vector<string>, vector<string> > temp;
                    temp.first.push_back(i.first.first);
                    temp.second.push_back(i.first.second);
                    set.push_back(temp);
                }
                else if(index1 == -1 && index2 != -1) {
                    if(isExistCounterpart(index2, i.first.first)) {
                        // 이미 존재하는 경우
                        // pass
                    }
                    else {
                        set[index2].second.push_back(i.first.first);
                    }
                }
                else if(index1 != -1 && index2 == -1) {
                    if(isExistCounterpart(index1, i.first.second)) {
                        // 이미 존재하는 경우
                        // pass
                    }
                    else {
                        set[index1].second.push_back(i.first.first);
                    }
                }
                else {
                    if(index1 == index2) {
                        set.clear();
                        alwaysFlag = false;
                        return;
                    }
                    else {
                        // 상관 x
                    }
                }
            }
            break;
        case 3:
            if(i.first.first != i.first.second) {
                if(i.second == EQUAL) {
                    set.clear();
                    alwaysFlag = false;
                    return;    
                }
                else {
                    // 항상 참인 구문
                    // Ex. 2018 != 2019
                    // pass
                }
            }
            else {
                if(i.second == EQUAL) {
                    // 쓸모 없는 상황
                    // Ex. 2019 == 2019
                    // pass
                }
                else {
                    // 모순 되는 상황
                    // Ex. 2019 != 2019
                    set.clear();
                    return;
                }
            }
            break;
        }
    }
}

pair<string, int> findShortest(vector<string> list) {
    size_t threshold = -1;
    string shortest;
    int index = -1;
    for(int i = 0 ; i < list.size() ; ++i) {
        if(list[i].length() < threshold) {
            threshold = list[i].length();
            shortest = list[i];
            index = i;
        }
    }

    return make_pair(shortest, index);
}

void print() {
    vector<string> ans;

    if(set.size() == 0) {
        if(alwaysFlag == true) {
            cout << "0==0" << endl;
        }
        else {
            cout << "1==0" << endl;
        }

        return;
    }
    for(const pair< vector<string>, vector<string> >& p : set) {
        pair<string, int> shortestInfo = findShortest(p.first);
        for(int i = 0 ; i < p.first.size(); ++i) {
            if(i != shortestInfo.second) {
                string insert = shortestInfo.first + "==" + p.first[i];
                ans.push_back(insert);
            }
        }
        if(p.second.size() != 0) {
            for(int i = 0 ; i < p.second.size(); ++i) {
                string insert = shortestInfo.first + "!=" + p.second[i];
                ans.push_back(insert);
            }   
        }
    }
        
        int i = 0;
        for(; i < ans.size() - 1 ; ++i) {
            cout << ans[i] << "&&";
        }
        cout << ans[i] << endl;

}

int main() {
    string input;
    cin >> input;
    
    parsing(input);
    makeset(parsed);
    print();
    
}