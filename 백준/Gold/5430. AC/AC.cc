#include <iostream>
#include <deque>

using namespace std;

string solution(string &p, int &n, string &arr) {
    
    deque<int> dq;
    string ans = "[";
    string num = "";
    bool is_reverse = false;
    
    // 숫자 배열 벡터에 차례로 저장
    for(int i=1; i<arr.length()-1; i++) {
        while(arr[i]!=',' && arr[i]!=']') { // 구분자 나올때까지 i++
            num += arr[i];
            i++;
        }
        dq.push_back(stoi(num));
        num = "";
    }
    
    // RD 명령 수행
    for(int i=0; i<p.size(); i++) {
        // reverse
        if(p[i]=='R') { 
            is_reverse = !is_reverse;
        } 
        // delete
        else { 
            if(dq.empty()) { // 더이상 지울 요소가 없다면 에러 출력
                return "error";
            }
            
            is_reverse ? dq.pop_back() : dq.pop_front() ;
       }
    }
    
    
    // 최종 배열 담기
    if(is_reverse) {
         while (!dq.empty()) {
            ans+= to_string(dq.back());
            dq.pop_back();
            if(dq.empty()) {
                break;
            }
            ans += ',';
        }
    } else {
         while (!dq.empty()) {
            ans+= to_string(dq.front());
            dq.pop_front();
            if(dq.empty()) {
                break;
            }
            ans += ',';
        }
    }
    
    
    return ans+']';
    
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int t, n;
    string p;
    string arr;
    
    cin >> t;
    
    while(t--) {
        cin >> p >> n >> arr;
        cout << solution(p, n, arr) << '\n';
    }

    return 0;
}