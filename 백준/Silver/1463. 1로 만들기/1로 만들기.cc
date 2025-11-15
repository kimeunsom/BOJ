#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    queue<int> q;
    vector<int> vis(1000001, -1); // 방문여부 체크
    
    int n;
    cin >> n;
    
    q.push(n);
    vis[n] = 0;
    
    // BFS
    while(!q.empty()) {
        
        int cur = q.front();
        q.pop();
        
        if(cur == 1) {
            cout << vis[cur];
            break;
        }
        
        // 연산 1: X - 1
        int next1 = cur-1;
        if(next1 >=1 && vis[next1] == -1) { // 아직 1보다 크고, 방문안했으면?
            vis[next1] = vis[cur]+1; //횟수
            q.push(next1);
        }

        // 연산 2: X / 2
        if(cur%2==0) {
            int next2 = cur/2;
            if(next2 >=1 && vis[next2] == -1) {
                vis[next2] = vis[cur]+1; 
                q.push(next2);
            }
        }
        
        // 연산 3: X / 3
        if(cur%3==0) {
            int next3 = cur/3;
            if(next3 >=1 && vis[next3] == -1) { 
                vis[next3] = vis[cur]+1; 
                q.push(next3);
            }
        }
    }

    return 0;
}