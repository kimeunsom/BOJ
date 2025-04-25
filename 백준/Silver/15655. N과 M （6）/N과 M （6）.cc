#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
vector<int> arr(10,0);
int seq[10];
bool isUsed[10];

void func(int cur) {
    if(cur==m) {
        for(int i=0; i<m; i++) {
            cout << seq[i] << " ";
        } cout << '\n';
        return;
    }
    
    for(int i=0; i<n; i++) {
        if(isUsed[i]) continue;
        if(cur==0 || seq[cur-1]<arr[i]) {
            isUsed[i] = true;
            seq[cur] = arr[i];
            func(cur+1);
            isUsed[i] = false;
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m;
    
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }
    
    sort(arr.begin(), arr.begin()+n);
    
    func(0);
    
    return 0;
}