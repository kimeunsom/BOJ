#include <iostream>
#include <tuple>
#include <queue>

using namespace std;

typedef tuple<int, int, int> t;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    
    int tmt[101][101][101];
    int n, m, h, max = 0;
    
    // 상하좌우앞뒤
    int dx[6] = {1, -1, 0, 0, 0, 0};
    int dy[6] = {0, 0, 1, -1, 0, 0};
    int dz[6] = {0, 0, 0, 0, 1, -1};
    
    queue<t> q;
    
    cin >> m >> n >> h;
    for(int i=0; i<h; i++) { // 높이
        for(int j=0; j<n; j++) { // 행
            for(int k=0; k<m; k++) { // 열
                cin >> tmt[j][k][i];
                
                if(tmt[j][k][i]==1) q.push({j,k,i}); //익은 토마토 큐에 넣기.
            }
        }
    }
    
    // BFS
    while(!q.empty()) {
        
        t cur = q.front();
        q.pop();
        
        for(int i=0; i<6; i++) {
            int x = get<0>(cur) + dx[i];
            int y = get<1>(cur) + dy[i];
            int z = get<2>(cur) + dz[i];
            
            if(x<0 || x>=n || y<0 || y>=m || z<0 || z>=h ) continue; //범위밖 토마토 패스
            if(tmt[x][y][z]!=0) continue; // 안익은 토마토만 취급
            
            tmt[x][y][z] = tmt[get<0>(cur)][get<1>(cur)][get<2>(cur)] + 1;
            q.push({x,y,z}); // 새롭게 익힌 토마토 큐에 넣기
        }
    }
    
    for(int i=0; i<h; i++) {
        for(int j=0; j<n; j++) {
            for(int k=0; k<m; k++) {
                
                if(tmt[j][k][i]==0) { // 안익은 토마토 여전히 존재
                    cout << "-1";
                    return 0;
                }
                
                if(max<tmt[j][k][i]) max = tmt[j][k][i];
            }
        }
    }
    
    cout << max-1;

    return 0;
}