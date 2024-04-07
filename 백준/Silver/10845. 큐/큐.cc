#include <iostream>
#include <queue>

using namespace std;

int main()
{
    
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int n;
    cin >> n;
    
    string str;
    int x;
    queue<int> q;
    
    while(n--) {
        
        cin >> str;
        
        if (str=="push") { 
            
            cin >> x;
            q.push(x);
            
        } else if(str=="pop") {
            
            if(q.empty()) {
                cout << "-1\n";
            } else {
                cout << q.front() << "\n";
                q.pop();
            }
            
        } else if(str=="size") {
            
            cout << q.size() << "\n";

            
        } else if(str=="empty") {
            
            cout << q.empty() << "\n";
            
        } else if(str=="front") {
            
            if(q.empty()) {
                cout << "-1\n";
            } else {
                cout << q.front() << "\n";
            }
            
        } else if(str=="back") {
            
            if(q.empty()) {
                cout << "-1\n";
            } else {
                cout << q.back() << "\n";
            }
            
            
        }
    }
    
    return 0;
}