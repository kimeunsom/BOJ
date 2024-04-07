#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n , m;
    string temp;

    vector<int> v;
    
    cin >> n;
    
    while(n--) {
        cin >> temp;
        
        if(temp.compare("push")==0) {
            cin >> m;
            v.push_back(m);
        } else if(temp.compare("pop")==0) {
            if( v.empty() ) { //사이즈가 0이면,
                cout << -1 << '\n';
            } else {
                cout << v.back() << '\n';
                v.pop_back();
            }
        } else if(temp.compare("size")==0) {
            cout << v.size() << '\n';
        } else if(temp.compare("empty")==0) {
            if( v.empty() ) {
                cout << 1 << '\n';
            } else {
                cout << 0 << '\n';
            }
        } else if(temp.compare("top")==0) {
            if( v.empty() ) {
                cout << -1 << '\n';
            } else {
                cout << v.back() << '\n';
            }

        } 
    }

    return 0;
}