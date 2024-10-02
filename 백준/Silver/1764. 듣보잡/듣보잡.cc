#include <iostream>
#include <set>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int n, m, cnt=0;
    string name;
    set<string> names;
    set<string> answer;
    cin >> n >> m;
    
    // 듣도 못한 사람 set에 입력
    while(n--) {
        cin >> name;
        names.insert(name);
    }
    
    // 보도 못한 사람이 set에 존재하면 출력
    while(m--) {
        cin >> name;
        if( names.find(name) != names.end() ) {
            cnt++;
            answer.insert(name);
        }
    }
    
    cout << cnt << '\n';
    for(auto i=answer.begin(); i!=answer.end(); i++) {
        cout << *i << '\n';
    }

    return 0;
}