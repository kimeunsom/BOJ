#include <iostream>
#include <vector>
#include <stack>

using namespace std;


int solution(int n, const vector<int>& seq, vector <bool>& ans) {
    
    int cnt = 0;
    int num = 1;
    int i = 0;
    stack <int> s;
    
    
    while( i<n ) {
        
        if(s.empty()) {
            s.push(num);
            ans.push_back(true);
            num++;
        } else {
            while (s.top() != seq[i]) {
                
                if(num>n) return 0; // n까지 다 넣었는데, 수열 형성 안되는 경우
                
                s.push(num);
                ans.push_back(true);
                num++;
            }
            
            s.pop();
            ans.push_back(false);
            i++;
        }
    }
    
    return 1;
}

int main()
{
    
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int n, temp;
    vector <int> seq;
    vector <bool> ans; // 1이면 +, 0이면 -
    
    // 입력
    cin >> n;
    
    for(int i=0; i<n; i++) {
        cin >> temp;
        seq.push_back(temp);
    }
    
    // 연산
    int res = solution(n, seq, ans);
    
    
    // 출력
    if(res) {
        for(int i=0; i<ans.size(); i++) {
            if(ans[i]) cout << "+\n";
            else cout << "-\n";
        }
    } else {
        cout << "NO";
    }
    
    return 0;
}