#include <iostream>
#include <vector>

using namespace std;

int solution(int n) {
    vector<int> v (n+1, -1);
    v[0]=1;
    v[1]=1;
    
    for(int i=2; i<=n; i++) {
        v[i] = v[i-1] + v[i-2];
        v[i] %= 10007;
    }
    
    return v[n] % 10007;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int n;
    cin >> n;
    
    cout << solution(n);

    return 0;
}