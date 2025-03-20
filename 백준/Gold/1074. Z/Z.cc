#include <iostream>
#include <cmath>

using namespace std;

int func(int n, int r, int c) {
    if(n==0) return 0;
    
    int power = 1 << (n - 1);    
    int quadrant = (r >= power) * 2 + (c >= power);

    return quadrant*power*power + func(n-1, r%power, c%power);
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