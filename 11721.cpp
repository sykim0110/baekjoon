// 열 개씩 끊어 출력하기
#include <iostream>
#include <string>

using namespace std;

int main() {
    string input;
    cin >> input;
    for(int i = 0 ; i < input.size() ; i = i+10) {
        if(i+10 >= input.size())
            cout << input.substr(i, input.size()-i) << endl;
        else
            cout << input.substr(i,10) << endl;
    }

    return 0;
}