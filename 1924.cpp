#include <iostream>

using namespace std;

int main() {
    int x, y;
    int day = 0;
    int days[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    cin >> x >> y;
    for(int i = 0 ; i < x-1; ++i) {
        day += days[i];
    }
    day += (y-1);
    switch(day%7){
        case 0:
            cout << "MON\n";
            break;
        case 1:
            cout << "TUE\n";
            break;
        case 2:
            cout << "WED\n";
            break;
        case 3:
            cout << "THU\n";
            break;
        case 4:
            cout << "FRI\n";
            break;
        case 5:
            cout << "SAT\n";
            break;
        case 6:
            cout << "SUN\n";
            break;
    }
    return 0;

}