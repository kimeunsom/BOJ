#include <iostream>
#include <stack>
#include <vector>

using namespace std;

#define WATCHED 7

int n, m, x=0, ans=100;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

int cctv[10]; // 1~5번 cctv 저장
pair<int,int> xy[10]; // 각 cctv 위치
int room[10][10];
stack<vector<vector<int>>> s; // 이차원 배열 백업할 스택

// 배열 백업 저장하는 함수
void backup() {
    vector<vector<int>> temp(n, vector<int>(m));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            temp[i][j] = room[i][j];
    s.push(temp);
}

// 배열 다시 실행 이전으로 롤백하는 함수
void rollback() {
    vector<vector<int>> temp = s.top();
    s.pop();
    
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            room[i][j] = temp[i][j];
        }
    }
}

// 한 방향으로 CCTV 비추는 함수
void check(int x, int y, int dir) {
    x += dx[dir];
    y += dy[dir];
    
    while( x>=0 && x<n && y>=0 && y<m && room[x][y]!=6 ) {
        if(room[x][y]==0) room[x][y] = WATCHED;
        x += dx[dir];
        y += dy[dir];
    }
}

void func(int cur) {
    if(cur==x) { // x개의 cctv 모두 체크 완료.
        int cnt=0;
    
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(room[i][j]==0) cnt++; // 사각지대 수
            }
        }
        ans = min(ans, cnt); // 최소 사각지대 갱신
        return;
    }
    
    // 현재 시시티비의 좌표
    int r = xy[cur].first;
    int c = xy[cur].second;
    
    switch(cctv[cur]) {
        case 1:
            for(int i=0; i<4; i++) {
                backup();
                check(r, c, i);
                func(cur+1);
                rollback();
            }
            break;
        case 2:
            for(int i=0; i<2; i++) {
                backup();
                check(r, c, i);
                check(r, c, (i+2)%4);
                func(cur+1);
                rollback();
            }
            break;
        case 3:
            for(int i=0; i<4; i++) {
                backup();
                check(r, c, i);
                check(r, c, (i+1)%4);
                func(cur+1);
                rollback();
            }
            break;
        case 4:
            for(int i=0; i<4; i++) {
                backup();
                check(r, c, i);
                check(r, c, (i+1)%4);
                check(r, c, (i+2)%4);
                func(cur+1);
                rollback();
            }
            break;
        case 5:
            backup();
            for(int i=0; i<4; i++) {
                check(r, c, i);
            }
            func(cur+1);
            rollback();
            break;
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m;
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cin >> room[i][j];
            if(room[i][j]>=1 && room[i][j]<=5) { // cctv 종류와 좌표 저장.
                cctv[x] = room[i][j];
                xy[x].first = i;
                xy[x].second = j;
                x++;
            }
        }
    }
    
    func(0);
    cout << ans;

    return 0;
}