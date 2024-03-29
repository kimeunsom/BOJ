#include <iostream>
#include <vector>

using namespace std;

int getSum(int a, int b, const vector<int>& num) {
    
    if(a==1) {
        return num[b-1];
    } else {
        return num[b-1] - num[a-2];
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n, m, temp, a, b;
    vector<int> num;
    
    cin >> n;
    
    int sum = 0;
    while(n--) {
        cin >> temp;
        sum += temp; //지난합 + 나
        num.push_back(sum);
    }
    
    cin >> m;
    
    while (m--) {
        cin >> a >> b;
        cout << getSum(a, b, num) << "\n";
    }

    return 0;
}