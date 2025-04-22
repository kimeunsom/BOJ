#include <iostream>

using namespace std;

int main()
{
    int a, b;

    while(true) {
        cin >> a >> b;
        if(a == 0 && b == 0) {
            break; // a와 b 모두 0이면 루프를 종료합니다.
        }
        if(a > b) {
            cout << "Yes\n";
        } else {
            cout << "No\n";
        }
    }
    return 0;
}