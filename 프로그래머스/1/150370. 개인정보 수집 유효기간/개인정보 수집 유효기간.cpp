#include <string>
#include <vector>
#include <map>

using namespace std;

// 날짜를 일수로 전환하는 함수
int dateToDays(const string& date) {
    int y, m, d;
    
    y = stoi(date.substr(0,4));
    m = stoi(date.substr(5,2));
    d = stoi(date.substr(8,2));
    
    return (y*12*28)+(m-1)*28+d;
}

vector<int> solution(string today, vector<string> terms, vector<string> privacies) {
    vector<int> answer;
    
    map<char, int> terms_map; //terms를 map에 저장
    for(int i=0; i<terms.size(); i++) {
        terms_map[terms[i][0]] = stoi(terms[i].substr(2));
    } 
    
    for(int i=0; i<privacies.size(); i++) {
        int m = terms_map[privacies[i][11]]; // 유효기간 추출
        int when = dateToDays(privacies[i].substr(0,10)) + m*28;
        
        if( when > dateToDays(today) ) { // 파기할 개인정보 거름
            continue;
        }
            
        answer.push_back(i+1); //보관 가능한 개인정보
    }
    return answer;
}