#include <iostream>
#include <set>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int n;
    string name, status;
    set<string> names;
    cin >> n;
    
    while(n--) {
        cin >> name >> status;
        
        if(status == "enter") {
            names.insert(name);
        } else {
            names.erase(name);
        }
    }
    
    // set 역순 출력 - rbegin : 마지막 요소, rend: 첫번째 요소 앞
    for(auto iter = names.rbegin(); iter != names.rend(); iter++) {
        cout << *iter << '\n';
    } 

    return 0;
}