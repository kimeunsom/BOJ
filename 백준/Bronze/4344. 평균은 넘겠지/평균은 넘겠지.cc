#include <iostream>
#include <vector>
#include <iomanip> // 소수점 출력을 위해 필요


using namespace std;

int main()
{

    int t, n, score, sum, cnt;
    double avg;
    cin >> t;
    
    while (t--) {
        cin >> n ;
        sum = 0;
        cnt = 0;
        vector<int> students(n);
        
        for (int i = 0; i < n; ++i) {
            
            cin >> score;
            students[i] = score;
            sum += score;
            
        }
        
        avg = static_cast<double>(sum)/n;
        
        for(int i=0; i<n; i++) {
            if(students[i]>avg) { // 평균을 넘으면,
                cnt ++;
            }
        }
        
        // fixed는 C++의 출력 조작자 중 하나
        // 부동 소수점 값을 고정된 소수점 표기로 출력하도록 지시
        cout << fixed << setprecision(3) <<  static_cast<double>(cnt)/n*100 << "%\n";
    }
    
    
    return 0;
}