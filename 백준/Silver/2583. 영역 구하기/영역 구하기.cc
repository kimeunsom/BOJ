#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
#include <cstring> // memset 사용

using namespace std;

int m, n, k, cnt = 0;
int board[101][101]; // 전역 배열은 자동으로 0으로 초기화됨
int dx[4] = {1, 0, -1, 0}; // 동, 남, 서, 북
int dy[4] = {0, 1, 0, -1};
vector<int> width;
stack<pair<int, int>> s;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> m >> n >> k;
    
    memset(board, 0, sizeof(board)); // 모든 칸을 0으로 초기화

    // 직사각형 입력 받기
    while (k--) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        
        for (int i = y1; i < y2; i++) { // 세로(y) 좌표 기준
            for (int j = x1; j < x2; j++) { // 가로(x) 좌표 기준
                board[i][j] = 1; // 직사각형을 1로 표시
            }
        }
    }

    // DFS를 이용한 영역 탐색
    for (int i = 0; i < m; i++) { // 세로(행)
        for (int j = 0; j < n; j++) { // 가로(열)
            if (board[i][j] != 0) continue; // 이미 방문했거나 직사각형이면 패스

            s.push({i, j});
            board[i][j] = 1; // 방문 표시
            cnt++; // 영역 개수 증가
            int w = 0; // 새로운 영역의 면적을 0으로 초기화

            while (!s.empty()) {
                pair<int, int> cur = s.top();
                s.pop();
                w++; // 면적 증가

                for (int d = 0; d < 4; d++) { // 4방향 탐색
                    int x = cur.first + dx[d];
                    int y = cur.second + dy[d];

                    if (x < 0 || x >= m || y < 0 || y >= n) continue; // 범위 체크
                    if (board[x][y] != 0) continue; // 이미 방문했거나 직사각형이면 패스

                    board[x][y] = 1; // 방문 표시
                    s.push({x, y});
                }
            }
            width.push_back(w); // 영역 크기 저장
        }
    }

    // 면적 오름차순 정렬
    sort(width.begin(), width.end());

    // 출력
    cout << cnt << '\n';
    for (int i = 0; i < width.size(); i++) {
        cout << width[i] << " ";
    }

    return 0;
}
