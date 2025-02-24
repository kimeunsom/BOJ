#include <iostream>

using namespace std;
typedef long long ll;

int rec(ll a, ll b, ll c) {
    
    if(b==1) return a%c;
    
    ll half = rec(a, b/2, c);
    ll ans = half*half%c;
    
    if(b%2) return ans*a%c;
    else return ans;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    ll a, b, c;
    cin >> a >> b >> c;
    
    cout << rec(a, b, c);
    
    return 0;
}