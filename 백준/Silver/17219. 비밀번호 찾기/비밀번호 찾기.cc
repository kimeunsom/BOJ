#include <iostream>
#include <unordered_map>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int n, m;
    string site;
    string pw;
    unordered_map <string, string> passwords;
    cin >> n >> m;
    
    while(n--) {
        cin >> site >> pw;
        passwords[site] = pw;
    }
    
    while(m--) {
        cin >> site;
        cout << passwords[site] << '\n';
    }

    return 0;
}