#include <iostream>

using namespace std;

typedef long long ll;

int recursion(ll a, ll b, ll c) {
    
    if(b==0) return 1; // 0승은 1
    else if(b==1) return a%c; // 1승이면 그냥 a
    
    ll half = recursion(a, b/2, c);
    half = (half*half) %c;
    
    if(b%2) half = (half*a) %c; // b가 홀수면 a 한 번 더 곱하기
    
    return half; 
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    ll a, b, c;
    cin >> a >> b >> c;
    
    cout << recursion(a, b, c);
    
    return 0;
}