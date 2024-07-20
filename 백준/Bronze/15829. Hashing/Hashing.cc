#include <iostream>
#include <cmath> // 제곱함수 헤더

using namespace std;

const int m = 1234567891;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int l;
    long long hash = 0;
    long long r = 1;
    string str; 
    
    // 입력
    cin >> l >> str;
    
    // 연산
    for(int i=0; i<l; i++) {
        hash += ((str[i]-'a'+1) * r) % m;
        
        r = (r * 31) % m;
    }
    hash %= m;
    
    // 출력
    cout << hash;

    return 0;
}