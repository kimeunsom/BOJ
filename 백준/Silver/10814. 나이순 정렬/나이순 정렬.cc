#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef pair<int,string> p;

bool cmp(const p &a, const p &b) {
    
    // 나이순 정렬
    if(a.first!=b.first) {
        return a.first < b.first; 
    } 
    
    // 나이가 같으면 변화없이 그대로 !
    else {
        return false; // 원래 순서 유지 !
    }
}


void sortUser(vector<p>& user) {
    
    stable_sort(user.begin(), user.end(), cmp);
    
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    // 입력
    int n;
    cin >> n;
    
    int age;
    string name;
    
    vector <p> user;
    
    while (n--) {
        cin >> age >> name;
        user.push_back(make_pair(age, name));
    }
    
    // 연산
    sortUser(user);
    
    
    // 출력
    for (int i=0; i<user.size(); i++) {
        cout << user[i].first << " " << user[i].second << '\n';
    }

    return 0;
}