#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int a, b, c;
    cin >> a >> b >> c;
    
    cout << a+b-c << '\n' << stoi(to_string(a)+to_string(b))-c;

    return 0;
}