#include <iostream>
#include <queue>

using namespace std;

typedef pair<int,int> p;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t, m, n, k;
    cin >> t;
    
    while(t--) {
        cin >> m >> n >> k;
        
        int ground[51][51] = {0};
        bool visited[51][51] = {0};
        int cnt = 0;
        queue<p> q;
        
        while(k--) { // 배추 위치 입력받기기
            int a, b;
            cin >> a >> b;
            ground[a][b] = 1;
        }
        
        for(int r=0; r<m; r++) {
            for(int c=0; c<n; c++) {
                if(visited[r][c] || ground[r][c]!=1) continue; // 이미 방문했거나, 배추 없으면 패스
                q.push({r, c}); // 배추 있으면 큐에 넣기. 
                cnt++ ;

                // BFS
                while(!q.empty()) {
                    p cur = q.front();
                    q.pop();
                    
                    for(int i=0; i<4; i++) {
                        int x = cur.first+dx[i];
                        int y = cur.second+dy[i];
                        
                        if(x<0 || x>=m || y<0 || y>=n) continue; // 범위 외 패스스
                        if(visited[x][y] || ground[x][y]!=1) continue; // 이미 방문했거나, 배추 없으면 패스
                        
                        visited[x][y] = true;
                        q.push({x, y});
                    }
                }
            }
        }
        cout << cnt << "\n";
    }
    return 0;
}