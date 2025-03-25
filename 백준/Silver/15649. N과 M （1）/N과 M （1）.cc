#include <iostream>

using namespace std;

int n,m;
int arr[10];
int isUsed[10];

void func(int k) {
    // 종료조건 - 배열에 채워진 수(k)가 m개가 되면, arr 출력 후 종료 ~
    if(k==m) {
        for(int i=0; i<m; i++) {
            cout << arr[i] << " ";
        }
        cout << '\n';
        return;
    }
    
    for(int i=1; i<=n; i++) {
        if(!isUsed[i]) { // 아직 사용되지 않은 수라면,
            arr[k] = i;
            isUsed[i] = true;
            func(k+1);
            isUsed[i] = false;
        }
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