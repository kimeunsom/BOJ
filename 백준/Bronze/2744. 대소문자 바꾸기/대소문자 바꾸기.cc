#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    string str;
    
    cin >> str;
    for(int i=0; i<str.length(); i++) {
        if(str[i] >= 'A' && str[i] <= 'Z') { // 대문자면
            str[i]+=32;
        } else { // 소문자면 대문자로
            str[i]-=32;
        }
    }
    
    cout << str;

    return 0;
}