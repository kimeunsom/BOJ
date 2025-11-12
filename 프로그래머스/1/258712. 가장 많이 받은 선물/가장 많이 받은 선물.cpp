#include <string>
#include <vector>
#include <sstream> // istringstream
#include <map>

using namespace std;

pair<string, string> space_split(const string& str) {
    istringstream iss(str); // istringstream 객체 생성
    string a, b;
    iss >> a >> b;        
    return make_pair(a, b);
}

int solution(vector<string> friends, vector<string> gifts) {    
    map<string, int> gift_point;  // 선물지수 맵
    
    map<string, map<string,int>> give_receive;
    for(int i=0; i<gifts.size(); i++) {
        pair<string, string> gr= space_split(gifts[i]); // 스페이스로 구분
        string giver = gr.first;
        string receiver = gr.second;
        
        gift_point[giver] ++; // 선물지수 +/-
        gift_point[receiver] --;
        
        // 서로 주고받은 값 이차원 벡터에 정리
        give_receive[giver][receiver]++;
    }
    
    map<string, int> next_month; // 다음 달에 받을 선물 맵
    for(int i=0; i<friends.size(); i++) {
        for(int j=i+1; j<friends.size() ; j++) {
            pair<int, int> cnt = make_pair(give_receive[friends[i]][friends[j]], give_receive[friends[j]][friends[i]]); // i -> j, j -> i 선물 준 개수
            
            if( cnt.first == cnt.second ) { // 주고받은 개수가 아예 없거나 같은 경우 -> 선물지수 비교
                if(gift_point[friends[i]] == gift_point[friends[j]]) { // 선물지수 같은 경우
                    continue;
                } else if(gift_point[friends[i]] > gift_point[friends[j]]) { // 선물지수가 더 큰 사람이 다음달에 선물 +1
                    next_month[friends[i]]++;
                } else {
                    next_month[friends[j]]++;
                }
            } else if (cnt.first < cnt.second) {
                next_month[friends[j]]++;
            } else { // cnt.first > cnt.second
                next_month[friends[i]]++;
            }
        }
    }
    
    int max_gift = 0;
    for(const string&name : friends) {
        if(next_month[name] > max_gift) {
            max_gift = next_month[name];
        }
    }
    return max_gift;
}