#include <iostream>
#include <cmath> // 제곱함수 헤더

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int l;
    long hash = 0;
    string str; 
    
    // 입력
    cin >> l >> str;
    
    // 연산
    for(int i=0; i<l; i++) {
        hash += (str[i]-'a'+1) * pow(31, i);
    }
    hash %= 1234567891;
    
    // 출력
    cout << hash;

    return 0;
}