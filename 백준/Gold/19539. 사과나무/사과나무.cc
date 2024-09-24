#include <iostream>

using namespace std;

bool solve(int odd, int sum) {
    
    if(sum%3) {
        return false;
    }
    
    if(odd > sum/3) {
        return false;
    }
    
    return true;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int n, h, sum=0, odd=0;
    cin >> n;
    
    while(n--) {
        cin >> h;
        sum += h;
        if(h%2) {
            odd++;
        }
    }
    
    solve(odd, sum) ? cout << "YES" : cout << "NO";

    return 0;
}