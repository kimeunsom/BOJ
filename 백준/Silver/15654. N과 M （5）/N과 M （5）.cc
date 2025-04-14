#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m, x; 
vector<int> num(10, 0);
int arr[10];
int isUsed[10];

void func(int cur) {
    if(cur == m) { // m개 다 골랐다면,
        for(int i=0; i<m; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
        return;
    }
    
    for(int i=0; i<n; i++) {
        if(isUsed[i]) continue; // 이미 사용한한 수는 패스스
        isUsed[i] = true;
        arr[cur] = num[i]; 
        func(cur+1);
        isUsed[i] = false;
    }
}


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m;
    for(int i=0; i<n; i++) {
        cin >> num[i];
    }
    
    sort(num.begin(), num.begin()+n); // num 벡터 정렬
    func(0);

    return 0;
}