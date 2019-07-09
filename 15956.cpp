#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <utility>
#include <algorithm>

#define P(a) cout<<a<<endl;
#define EQ 0
#define NOTEQ 1
using namespace std;


//index의 first에서 해당 단어가 있는 지 확인. 있으면 해당 position 반환, 없으면 -1 반환
int search(vector< pair< vector<string>, vector<string> > >& index, string word) {
    for(int i = 0; i < index.size() ; ++i) {
        if(find(index[i].first.begin(), index[i].first.end(), word) != index[i].first.end()) {
            return i;
        }
    }
    return -1;
}

int countNumber(vector<string> input) {
    bool flag = true;
    int count = 0;
    for(const string& s : input) {
        flag = true;
        if(s.size() > 1){
            for(int i = 1;i < s.size() ; i++) {
                if((int)s[i] > 9) {
                    flag = false;
                } 
            }
        }
        else {
            if((int)s[0] > 9)
                flag = false;
        }
        if(flag) {
            count++;
        }
        
    }

    return count;
}

// string vector에 들어있는 string 중, 길이가 가장 짧은 string 반환
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

void solve(vector<pair< pair<string, string>, int> >& set) {
    vector<string> ans;
    vector< pair< vector<string>, vector<string> > > index;
    string word1, word2;
    int flag;
    for(vector<pair< pair<string, string>, int> >::iterator it = set.begin(); it != set.end(); it++){
        word1 = (*it).first.first;
        word2 = (*it).first.second;
        flag = (*it).second;
        if(word1 == word2) {
            if(flag == EQ) {
                int where = search(index, word1);
                if(where == -1) {
                    pair< vector<string>, vector<string> > temp;
                    temp.first.push_back(word1);
                    index.push_back(temp);
                }                
            }
            else {
                cout << "1==0" << endl;
                return;
            }
        }
        else {
            if(index.size() == 0) {
                pair< vector<string>, vector<string> > temp;
                temp.first.push_back(word1);
                if(flag == EQ)
                    temp.first.push_back(word2);
                else
                    temp.second.push_back(word2);
                
                index.push_back(temp);
            }
            else {
                int where = search(index, word1);
                int where2 = search(index, word2);
                if(flag == EQ) {
                    // 둘 다 처음 나오는 단어인 경우
                    if(where == -1 && where2 == -1) {
                        pair< vector<string>, vector<string> > temp;
                        temp.first.push_back(word1);
                        temp.first.push_back(word2);
                        index.push_back(temp);
                    }
                    // word2만 처음 나오는 단어인 경우
                    else if(where != -1 && where2 == -1) {
                        index[where].first.push_back(word2);
                    }
                    // word1만 처음 나오는 단어인 경우
                    else if(where == -1 && where2 != -1) {
                        index[where2].first.push_back(word1);
                    }
                    // 둘 다 이미 나온 경우
                    else {
                        // possible?
                    }
                }
                else { // flag == NOTEQ
                    // 둘 다 처음 나오는 경우
                    if(where == -1 && where2 == -1) {
                        pair< vector<string>, vector<string> > temp;
                        temp.first.push_back(word1);
                        temp.second.push_back(word2);
                        index.push_back(temp);
                    }
                    // word2만 처음 나오는 경우
                    else if(where != -1 && where2 == -1) {
                        // 먼저, index[where].second에 word2가 있는지 확인
                        // 있다면 - Pass
                        // 없다면 - 추가
                        if(find(index[where].second.begin(), index[where].second.end(), word2) == index[where].second.end()){
                            index[where].second.push_back(word2);
                        }                  
                    }
                    else if(where == -1 && where2 != -1) {
                        // 먼저, index[where2].second에 word1가 있는지 확인
                        // 있다면 - Pass
                        // 없다면 - 추가
                        if(find(index[where2].second.begin(), index[where2].second.end(), word1) == index[where2].second.end()){
                            index[where2].second.push_back(word1);
                        }
                    }
                    // 둘 다 이미 나온 경우
                    // Case 1. 같은 곳에 존재 - 모순!
                    // Case 2. 다른 곳에 존재 - 둘 중에 한 군데만 추가하면 됨.
                    else {
                        if(where == where2) {
                            cout << "1==0"<< endl;
                            return;
                        }
                        if(find(index[where].second.begin(), index[where].second.end(), word2) != index[where].second.end()){
                            continue;
                        }
                        if(find(index[where2].second.begin(), index[where2].second.end(), word1) == index[where2].second.end()){
                            continue;
                        }
                        index[where].second.push_back(word2);
                    }
                }   
            }
        }
    }

    // 출력
    if(index.size() == 1) {
        if(index[0].first.size() == 1 && index[0].second.size() == 0){
            cout << "0==0" << endl;
            return;
        }
    }
    for(const pair< vector<string>, vector<string> >& p : index) {
        cout << "count is "<< countNumber(p.first) << endl;        
        if(countNumber(p.first) > 1) {
            cout << "1==0" << endl;
            return;
        }
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

    /*
    for(const auto& p : index) {
        for(const auto& q : p.first)  {
            cout << q << ' ';
        }
        cout << endl;
        for(const auto& q : p.second)  {
            cout << q << ' ';
        }
        cout << endl << endl;
    }
    */

}

int main() {
    vector<pair< pair<string, string>, int> > set;
    //pair< pair<string, string>, bool> elem;
    
    string input;
    string word1, word2;
    int flag = EQ;
    cin >> input;
    
    string::iterator it = input.begin();

    // preprocessing
    while(it != input.end()) {
        pair< pair<string, string>, int> elem;
        while(*it != '=' && *it != '!') {
            word1.push_back(*it);
            it++;
        }

        
        if(*it == '=')
            flag = EQ;
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
        set.push_back(elem);
        word1.clear();
        word2.clear();
    }

    // preprocess check
    /*
    for(vector<pair< pair<string, string>, int> >::iterator it2 = set.begin(); it2 != set.end(); it2++){
        cout << (*it2).first.first <<' '<<(*it2).first.second << ' '<<(*it2).second << endl;
    }
    */

    solve(set);

    return 0;
}