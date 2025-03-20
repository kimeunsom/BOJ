#include <iostream>
#include <cmath>

using namespace std;

int func(int n, int r, int c) {
    int x=0;
    if(n==0) return 0;
    
    // 몇 번째 사분면인지 체크 ; 4분면의 기준이 2의 n-1승.
    int power = static_cast<int>(pow(2, n-1));
    
    if(r<power && c>=power) x=1;
    else if(r>=power && c<power) x=2;
    else if(r>=power && c>=power) x=3;
    
    return x*power*power + func(n-1, r%power, c%power);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    
    int n, r, c;
    cin >> n >> r >> c;

    cout << func(n, r, c);

    return 0;
}