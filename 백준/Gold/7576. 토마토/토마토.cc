#include <iostream>
#include <queue>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int tmt[1002][1002];

    int dx[4] = {0, 1, 0, -1};
    int dy[4] = {1, 0, -1, 0};
    
    int n, m, max=0 ;
    queue<pair<int,int>> q;
    
    cin >> m >> n;
    
    // 토마토 입력
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cin >> tmt[i][j];
            
            if(tmt[i][j] == 1) q.push({i,j}); 
            //익은 토마토는 모두 큐에 넣고 시작 - 시작점이 여러개인 BFS
        }
    }
    
    // BFS
    while(!q.empty()) {
        pair<int,int> cur = q.front();
        q.pop();
        
        for(int i=0; i<4; i++) {
            int x = cur.first + dx[i];
            int y = cur.second + dy[i];
            
            if(x<0 || x>=n || y<0 || y>=m) continue; // 범위밖 패스
            if(tmt[x][y]!=0) continue; // 안익은 토마토 아니고,빈칸이거나 익은 토마토면 패스?
            
            tmt[x][y] = tmt[cur.first][cur.second] + 1; // 이전칸에서 +1;
            q.push({x, y});
        }
    }
    
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(tmt[i][j]==0) { // 안익은 토마토 남아있으면 -1 출력
                cout << "-1"; 
                return 0;
            }
            
            if(max<tmt[i][j]) max=tmt[i][j]; // 익은 토마토와의 최장거리 갱신
        }
    }

    cout << max-1;


    return 0;
}