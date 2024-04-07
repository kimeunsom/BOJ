#include <iostream>
#include <stack>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int n , m;
    string temp;

    stack<int> s;
    
    cin >> n;
    
    while(n--) {
        cin >> temp;
        
        if(temp=="push") {
            cin >> m;
            s.push(m);
        } else if(temp=="pop") {
            if( s.empty() ) { //사이즈가 0이면,
                cout << -1 << '\n';
            } else {
                cout << s.top() << '\n';
                s.pop();
            }
        } else if(temp=="size") {
            cout << s.size() << '\n';
        } else if(temp=="empty") {
            if( s.empty() ) {
                cout << 1 << '\n';
            } else {
                cout << 0 << '\n';
            }
        } else if(temp=="top") {
            if( s.empty() ) {
                cout << -1 << '\n';
            } else {
                cout << s.top() << '\n';
            }

        } 
    }

    return 0;
}