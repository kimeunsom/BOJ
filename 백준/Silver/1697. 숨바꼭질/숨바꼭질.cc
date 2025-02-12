#include <iostream>
#include <queue>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, k;
    queue<int> q;
    int dist[100002];
    
    cin >> n >> k;
    
    q.push(n);
    fill(dist, dist+100001, -1); // -1로 배열 초기화
    dist[n] = 0;
    
    while(!q.empty()) {
        int cur = q.front();
        q.pop();
        
        for(int nxt : {cur-1, cur+1, cur*2}) {
            
            if(nxt<0 || nxt>100000) continue; // 범위 외 패스
            if(dist[nxt] != -1) continue; // 이미 채워진 값이면 패스
            
            dist[nxt] = dist[cur] + 1;
            q.push(nxt);
        }
    }
    
    cout << dist[k];
    
    return 0;
}