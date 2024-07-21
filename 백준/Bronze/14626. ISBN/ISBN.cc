#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    string str;
    int x;
    int sum = 0;
    
    cin >> str;
    
    for(int i=0; i<13; i++) {
        if(str[i]=='*') x=i;
        else if (i%2==0) {
            sum += str[i]-'0';
        } else {
            sum += 3*(str[i]-'0');
        }
    }
    
    sum %= 10;
    
    if(x%2==0) cout << 10-sum;
    else {
        for(int i=0; i<10; i++) {
            if((sum+3*i)%10==0) {
                cout << i;
                break;
            }
        }
    }

    return 0;
}