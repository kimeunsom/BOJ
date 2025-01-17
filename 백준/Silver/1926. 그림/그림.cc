#include <iostream>
#include <queue>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int paper[502][502];
    int vis[502][502];
    int dx[4] = {0, 1, 0, -1};
    int dy[4] = {1, 0, -1, 0};
    
    int max = 0, area = 0, cnt = 0;

    queue<pair<int,int>> q;
    
    int n, m;
    cin >> n >> m;
    
    // 도화지 입력받기
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cin >> paper[i][j];
        }
    }
    
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(!vis[i][j] && paper[i][j]==1) { // 아직 방문도 안하고, 1인 칸부터 새로 시작.
                q.push({i, j});
                vis[i][j]=1;
                cnt ++;
                
                while(!q.empty()){
        
                    pair<int, int> cur = q.front();
                    q.pop(); area++;
                    
                    for(int i=0; i<4; i++) {
                        
                        int x = cur.first + dx[i];
                        int y = cur.second + dy[i];

                        if(x<0 || x>=n || y<0 || y>=m) continue; // 행렬 범위 넘어갔으면 패스
                        if(vis[x][y] || paper[x][y]==0) continue; // 이미 방문 or 0이면 패스
                        vis[x][y]=1;
                        q.push({x,y});
                    }
                }
                
                if(max<area) max = area; //최대넓이 갱신
                area = 0; // 넓이 초기화
            }
        }
    }
    
    cout << cnt << '\n' << max;

    return 0;
}