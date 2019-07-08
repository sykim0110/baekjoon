#include <iostream>
#include <string>

using namespace std;

int main() {
  int testcase;
  int valid = 0;
  string input;

  cin >> testcase;
  
  for(int i = 0 ; i < testcase ; ++i) {
    valid = 0;
    cin >> input;
    for(string::iterator it = input.begin(); it != input.end() ; ++it) {
      if(*it == '(')
        valid++;
      else if(*it == ')')
        valid--;

      if(valid < 0){
        break;
      }
    }
    if(valid == 0)
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }
  
  return 0;
}
