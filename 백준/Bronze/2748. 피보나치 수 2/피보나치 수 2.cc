#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    long arr[91];
    arr[0] = 0;
    arr[1] = 1;
    
    for(int i=2; i<=90; i++) {
        arr[i] = arr[i-2]+arr[i-1];
    }
    
    int n;
    cin >> n;
    cout << arr[n];

    return 0;
}