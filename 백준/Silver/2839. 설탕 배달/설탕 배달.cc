#include <iostream>

using namespace std;

int sugarDelivery(int n) {
    
    int last3mul = -1 ; // 5를 빼며 나온 3 배수 저장
    int ans = 0;
    int copy_n = n;
    
    if(n%5==0) {
        return n/5;
    }
    
    while (n>0) {
        
        
        if(n%3==0) {
            last3mul = n;
        }
        
        n-=5;
    }    
    
    if(last3mul == -1 ) {
        return -1;
    } else {
        ans = (copy_n - last3mul)/5 + last3mul/3; // 5설탕 봉지 + 3설탕 봉지 갯수
        return ans;
    }
}

int main()
{

    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int n;
    cin >> n;
    
    cout << sugarDelivery(n);
    
    
    return 0;
}