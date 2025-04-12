#include <iostream>

using namespace std;

int n, m, cnt;
int arr[10];

void func(int cur) {
    if(cur==m) { // m칸의 배열이 다 찼다 !
        for(int i=0; i<m; i++) {
            cout << arr[i] << " ";
        }cout << '\n';
        return;
    }
    
    for(int i=1; i<=n; i++) {
        arr[cur] = i;
        func(cur+1);
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m;
    func(0);

    return 0;
}