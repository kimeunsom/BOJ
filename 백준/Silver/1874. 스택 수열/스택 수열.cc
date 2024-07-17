#include <iostream>
#include <vector>
#include <stack>

using namespace std;


int solution(int n, const vector<int>& seq, string& ans) {
    
    int num = 1;
    int i = 0;
    stack <int> s;

    
    while( i<n ) {
        
        if(s.empty()) {
            s.push(num);
            ans += "+\n";
            num++;
        } else {
            while (s.top() != seq[i]) {
                
                if(num>n) return 0; // n까지 다 넣었는데, 수열 형성 안되는 경우
                
                s.push(num);
                ans += "+\n";
                num++;
            }
            
            s.pop();
            ans += "-\n";
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
    string ans="";  

    
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
        cout << ans;
    } else {
        cout << "NO";
    }
    
    return 0;
}