#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    vector<int> v (26,0);
    
    string str;
    cin >> str;
    
    for(int i=0; i<str.length(); i++) {
        v[str[i]-'a']++;
    }
    
    for(int i=0; i<v.size(); i++) {
        cout << v[i] << " ";
    }

    return 0;
}