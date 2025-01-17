#include <iostream>
#include <queue>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int maze[102][102];
    int dist[102][102];
    int dx[4] = {0, 1, 0, -1};
    int dy[4] = {1, 0, -1, 0};
    
    int n, m;
    string input;
    cin >> n >> m;
    
    cin.ignore(); // 개행 무시

    // 미로 입력받기
    for(int i=0; i<n; i++) {
        getline(cin, input);
        
        for(int j=0; j<m; j++) {
            maze[i][j] = input[j]-'0';
        }
    }

    // dist 배열 -1로 초기화
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            dist[i][j] = -1;
        }
    }
    
    queue<pair<int,int>> q;
    q.push({0,0});
    dist[0][0] = 1;
    
    // BFS로 최단거리 찾기
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(dist[i][j]!=-1 || maze[i][j]==0) continue; // 이미 채워졌거나 0이면 패스
            
            while(!q.empty()) {
                
                pair<int, int> cur = q.front();
                q.pop();

                for(int i=0; i<4; i++) {
                    int x = cur.first + dx[i];
                    int y = cur.second + dy[i];
                    
                    if(x<0 || x>=n || y<0 || y>=m) continue; // 범위 벗어나면 패스
                    if(dist[x][y]!=-1 || maze[x][y]==0) continue; // 해당 칸이 0이거나 이미 채워졌으면 패스..
                    
                    q.push({x, y});
                    dist[x][y] = dist[cur.first][cur.second]+1 ; // 현재 칸보다 이동거리 +1
                }
            }
        }
    }
    
    cout << dist[n-1][m-1];

    return 0;
}