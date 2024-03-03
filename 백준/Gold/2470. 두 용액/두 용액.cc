#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX_POTIONS = 2e9; //한 용액의 최대값이 e9이므로, 섞으면 최대 2e9
typedef pair <int, int> p;

p makePotion (const vector<int> &potions) {
    
    //최종 두 용액 저장할 ans pair 변수
    p ans = {0,0}; 
    
    //투 포인터 선언 및 초기화
    int lp = 0;
    int rp = potions.size()-1;
    
    int cur_mix = 0;
    //현재 용액 특성값
    
    int mix = MAX_POTIONS +1; 
    //가능한 최대 용액의 특성값 + 1로 초기화 ! 
    //그래야 0과 가까운 다음 값으로 갱신됨.
    
    while( lp < rp ) {
        
        //printf("mix:%d / 현재: %d  / 왼 오 : %d %d\n", mix, cur_mix, potions[lp], potions[rp]);
        
        cur_mix = potions[lp] + potions[rp];
        
        //   #1 특성값 0이면, 곧바로 리턴.
        if(cur_mix==0) { 
            return {potions[lp], potions[rp]};
        }
        
        //   #2. 포인터 옮기기 전, 이전 믹스값과 현재 믹스값을 비교
        if(abs(cur_mix) < abs(mix)) {
            mix = cur_mix;
            ans = {potions[lp], potions[rp]};
            //printf("뿅 %d %d \n",ans.first, ans.second );
        }
        
        //   #3. 그리고 다음 반복 위해, 포인터 조정.
        if(cur_mix>0) {
            rp--;
        } else { // cur_mix < 0 일 때,
            lp++;
        }
        
        
        
    }
    
    return ans;
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n, t;
    cin >> n;
    vector <int> potions; //용액들 저장할 벡터
    
    while(n--) {
        cin >> t;
        potions.push_back(t);
    }

    //서로 다가가는 방식의 투 포인터 활용 : 먼저 배열 정렬 필수.
    sort(potions.begin(), potions.end()); 

    cout << makePotion(potions).first << " " << makePotion(potions).second ;

    return 0;
}