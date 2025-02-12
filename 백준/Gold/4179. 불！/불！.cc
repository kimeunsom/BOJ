#include <iostream>
#include <queue>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int fire[1001][1001]; // 불이 번지는 데 걸리는 시간 저장
    int jh[1001][1001]; // 지훈이의 이동 시간 저장
    
    int dx[4] = {0, 1, 0, -1};
    int dy[4] = {1, 0, -1, 0};
    
    int r, c;
    char tmp;
    cin >> r >> c;
    
    queue<pair<int,int>> q_jh;
    queue<pair<int,int>> q_fire;
    
    for(int i=0; i<r; i++) {
        for(int j=0; j<c; j++) {
            cin >> tmp;
            switch(tmp) {
                case '#':
                    fire[i][j] = -1;
                    jh[i][j] = -1;
                    break;
                case 'J':
                    q_jh.push({i, j});
                    jh[i][j] = 1;
                    break;
                case 'F':
                    q_fire.push({i, j});
                    fire[i][j] = 1;
                    break;
            }
        }
    }
    
    // 불 번져나가는 시간 계산하는 BFS
    while(!q_fire.empty()) {
        pair<int,int> cur = q_fire.front();
        q_fire.pop();
        
        for(int i=0; i<4; i++) {
            int x = cur.first + dx[i];
            int y = cur.second + dy[i];
            
            if(x<0 || x>=r || y<0 || y>=c) continue; // 범위 외 패스
            if(fire[x][y]!=0) continue; // 빈 공간이 아닌 경우 패스 -> 벽이거나 이미 채워졌거나.
            
            fire[x][y] = fire[cur.first][cur.second] + 1;
            q_fire.push({x,y});
        }
    }

    // 지훈이 이동하는 BFS
    while(!q_jh.empty()) {
        pair<int,int> cur = q_jh.front();
        q_jh.pop();
        
        for(int i=0; i<4; i++) {
            int x = cur.first + dx[i];
            int y = cur.second + dy[i];
            
            if(x<0 || x>=r || y<0 || y>=c) continue; // 범위 외 패스
            if(jh[x][y]!=0) continue; // 빈 공간이 아닌 경우 패스
            
            jh[x][y] = jh[cur.first][cur.second] + 1;
            q_jh.push({x,y});
        }
    }

    int min_t = 10000;
    bool flag = false;
    
    for(int i=0; i<r; i++) {
        for(int j=0; j<c; j++) {
            if(i==0 || i==r-1 || j==0 || j==c-1) { // 가장자리 좌표에 대해
                if(jh[i][j]==0) continue; // 지훈이가 닿지 못한 곳은 비교 제외.
                
                if(fire[i][j] > jh[i][j] || fire[i][j]==0) { // 불이 안 난 곳이거나, 불 난 시간보다 지훈이의 이동시간이 짧으면
                    min_t = min(min_t, jh[i][j]);
                    flag = true;
                }
            }
        }
    }
    
    if (flag) {
        cout << min_t;
    } else {
        cout << "IMPOSSIBLE";
    }

    return 0;
}