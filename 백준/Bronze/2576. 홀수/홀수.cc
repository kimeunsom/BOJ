#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int x, sum = 0, min = 100;
    
    for(int i=0; i<7; i++) {
        cin >> x;
        
        if(x%2) {
            sum+= x; //합산
            if(min>x) { 
                min = x; //최솟값 갱신
            }
        }
    }
    
    if(!sum) cout << "-1";
    else cout << sum << '\n' << min;

    return 0;
}