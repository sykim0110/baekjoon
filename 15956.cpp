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

int search(vector< pair< vector<string>, vector<string> > >& index, string word) {
    for(int i = 0; i < index.size() ; ++i) {
        if(find(index[i].first.begin(), index[i].first.end(), word) != index[i].first.end()) {
            return i;
        }
    }
    return -1;
}

void solve(vector<pair< pair<string, string>, int> >& set) {
    vector< pair< vector<string>, vector<string> > > index;
    string word1, word2;
    int flag;
    for(vector<pair< pair<string, string>, int> >::iterator it = set.begin(); it != set.end(); it++){
        word1 = (*it).first.first;
        word2 = (*it).first.second;
        flag = (*it).second;
        
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

            if(where != -1) {
                if(flag == EQ)
                    index[where].first.push_back(word2);
                else
                    index[where].second.push_back(word2);
            }
            else {
                int where2 = search(index, word2);
                if(where2 != -1) {
                    if(flag == EQ)
                        index[where2].first.push_back(word1);
                    else    
                        index[where2].second.push_back(word2);
                }
                pair< vector<string>, vector<string> > temp;
                temp.first.push_back(word1);
                if(flag == EQ)
                    temp.first.push_back(word2);
                else
                    temp.second.push_back(word2);
                index.push_back(temp);
            }
        }
    }

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