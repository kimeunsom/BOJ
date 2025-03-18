#include <iostream>
#include <queue>
#include <cstring> // memset을 사용하기 위한 헤더 추가

using namespace std;

using pii = pair<int, int>;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};
int map[1001][1001]; // 지도
int ground[1001][1001]; // 땅

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, m;
    queue<pii> q;
    
    cin >> n >> m;
    
    memset(ground, -1, sizeof(ground)); // 모든 값을 -1로 초기화

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> map[i][j]; // 지도 입력받기

            if (map[i][j] == 2) { // 목표지점이면 큐에 삽입
                q.push({i, j});
                ground[i][j] = 0;
            }
            else if (map[i][j] == 0) 
                ground[i][j] = 0;
        }
    }
    
    // BFS
    while (!q.empty()) {
        pii cur = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int x = cur.first + dx[i];
            int y = cur.second + dy[i];

            if (x < 0 || x >= n || y < 0 || y >= m) continue; // ❗ 범위 수정
            if (ground[x][y] != -1) continue; // 이미 방문한 곳 패스

            ground[x][y] = ground[cur.first][cur.second] + 1; // 거리 한 칸 증가
            q.push({x, y});
        }
    }
    
    // 출력
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << ground[i][j] << " ";
        }
        cout << "\n";
    }
    
    return 0;
}