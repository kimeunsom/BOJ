#include <iostream>
#include <vector>
#include <algorithm> 
// unique(first, last ; 연속된 중복 원소 제거)  
// lower bound(first, last, target ; 타겟값의 시작 위치 이터레이터 리턴.)

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;
    
    vector<int> v(n, 0);

    for(int i=0; i<n; i++) {
        cin >> v[i];
    }
    
    vector<int> sorted = v;
    
    sort(sorted.begin(), sorted.end()); // 벡터 정렬
    sorted.erase(unique(sorted.begin(), sorted.end()), sorted.end()); // 벡터 중복 제거
    
    for(int i=0; i<n; i++) {
        cout << lower_bound(sorted.begin(), sorted.end(), v[i]) - sorted.begin() << " ";
    }
    
    return 0;
}