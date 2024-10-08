#include <iostream>
#include <vector>

using namespace std;

string solution(string &p, int &n, string &arr) {
    
    vector<int> v;
    string ans = "[";
    string num = "";
    bool is_reverse = false;
    
    // 숫자 배열 벡터에 차례로 저장
    for(int i=1; i<arr.length()-1; i++) {
        while(arr[i]!=',' && arr[i]!=']') { // 구분자 나올때까지 i++
            num += arr[i];
            i++;
        }
        v.push_back(stoi(num));
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
            if(v.empty()) { // 더이상 지울 요소가 없다면 에러 출력
                return "error";
            }
            
            is_reverse ? v.erase(v.end() -1) : v.erase(v.begin()) ;
       }
    }
    
    
    // 최종 배열 담기
    if(is_reverse) {
        for(int i=v.size()-1; i>=0; i--) { // 벡터 역순으로 담기
            ans +=  to_string(v[i]);
            if(i==0) {
                break;
            }
            ans += ',';
        }
    } 
    else {
        for(int i=0; i<v.size(); i++) {
            ans += to_string(v[i]);
            if(i==v.size()-1) {
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