#include <iostream>
#include <set>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int n, m;
    string name;
    set<string> names;
    set<string> answer;
    cin >> n >> m;
    
    // 듣도 못한 사람 set에 입력
    while(n--) {
        cin >> name;
        names.insert(name);
    }
    
    // 보도 못한 사람이 set에 존재하면 정답 set에 삽입
    while(m--) {
        cin >> name;
        if( names.find(name) != names.end() ) {
            answer.insert(name);
        }
    }
    
    cout << answer.size() << '\n';
    for(auto i=answer.begin(); i!=answer.end(); i++) {
        cout << *i << '\n';
    }

    return 0;
}