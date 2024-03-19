#include <iostream>
#include <vector>

using namespace std;

bool isEmpty(const vector<int>& q) { //벡터에 담긴게 처음 담아준 0밖에 없다면, 텅빈거야 !
    return q.size() == 1;
}

void pop(vector<int> &q) {
    
    q[1] = q[q.size()-1]; //마지막 노드를 루트 노드에
    q.pop_back(); //마지막 노드 삭제
    
    int parent = 1; 
    int child = 2;
    int biggerChild=0; // 더 큰 자식의 인덱스
    
    while(child < q.size()) {
        
        biggerChild = child;
        
        // 오른쪽 자식 노드 존재하고, 
        if(child<q.size()-1) {
            if(q[child] < q[child+1]) { // 오른쪽이 왼쪽보다 크다면, 
                biggerChild = child+1; // 오른쪽 자식의 인덱스를 biggerChild에 저장
            } 
        }
        
        // 부모가 자식보다 작으면 swqp
        if(q[parent] < q[biggerChild]) {
            swap(q[parent], q[biggerChild]);
            
            // 새 부모노드 기준으로 인덱스 업데이트
            parent = biggerChild;
            child = parent*2;
            
        } else { //부모가 크면, break
            break;
        }
    }
}

void insert(int x, vector<int> &q) {
    
    q.push_back(x); // x를 마지막 노드에 삽입
    
    int idx = q.size()-1; // x가 들어간 마지막 노드의 인덱스
    
    
    while(idx > 1) {
        //부모와 비교
        if(q[idx] > q[idx/2]) { // 자식인덱스 / 2 = 부모인덱스
            swap(q[idx], q[idx/2]);
            idx /=2;
        } else { // 부모보다 작다면, 자기 자리 찾음 ! break
            break;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
    
    int n, x;
    cin >> n;
    
    // 배열로 최대힙 구현
    vector<int> q;
    q.push_back(0);
    
    
    while(n--) {
        cin >> x;

        
        if(x) {
            // 삽입 연산
            insert(x, q); 
        } 
        
        else {
            // 삭제 연산
            
            //비어있다면 0 출력
            if(isEmpty(q)) {
                cout << "0\n";
            } 
            
            else {
                cout << q[1] <<"\n"; // 루트노드 출력
                pop(q);
            }
            
        }
    }

    return 0;
}