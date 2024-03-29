#include <iostream>
#include <stack>

using namespace std;

int getSum(stack<int> s) {
    int sum = 0;
    
    while(!s.empty()) {
        sum += s.top();
        s.pop();
    }
    
    return sum;
}


int main()
{
    
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int k, temp;
    stack<int> s;
    
    cin >> k;
    while (k--) {
        cin >> temp;
        if(temp) {
            s.push(temp); //0이 아닌 경우 push
        } else {
            s.pop(); //0인 경우 pop
        }
    }
    
    cout << getSum(s);

    return 0;
}