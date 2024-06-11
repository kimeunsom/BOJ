#include <iostream>

using namespace std;

int main()
{

    int n, t, p, shirts_bun, p_bun, p_one;
    int tshirts[6];
    
    cin >> n ;
    for(int i=0; i<6; i++) {
        cin >> tshirts[i];
    }
    cin >> t >> p;
    
    shirts_bun = 0; 
    for(int i=0; i<6; i++) {
        shirts_bun += tshirts[i]/t;
        if (tshirts[i]%t != 0) shirts_bun++; //나누어 떨어지지 않는 경우 묶음 +1;
    }
    
    p_bun = n/p;
    p_one = n%p;
    
    cout << shirts_bun << "\n" << p_bun << " " << p_one;
    return 0;
}