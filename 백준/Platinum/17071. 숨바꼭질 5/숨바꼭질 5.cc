#include <bits/stdc++.h>
using namespace std;

const int MAX=500000;
int n, k, ret, here;
int visited[2][MAX+4]; //[홀or짝][방문한 곳]

void fastIO(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}
int main(){

    fastIO();

    cin >> n >> k;

    if(k==n){ // 처음 입력받을 때 부터 같은 위치라면
        cout << 0 <<"\n";
        return 0; 
    }
    queue<int> q;
    q.push(n);
    visited[0][n] = 1;
    int turn=1;

    while (q.size()){
        k+= turn;

        if(k > MAX ){
            ret=-1;
            break;
        }
        if(visited[turn%2][k]){ //수빈이가 왔던 적이 있는데 홀짝이 맞는 경우
            ret = turn;
            break;
        }
        bool ok=0;
        int qSize = q.size(); // q 사이즈 저장
        for(int i=0; i <qSize ; i++){ // 큐의 크기만큼(부모 개수만큼) 반복. -> 부모와 자식의 턴을 분리하기 위함
            here = q.front();
            q.pop();
            for(int next: {here+1, here-1, here*2}){
                if(next < 0 || next > MAX || visited[turn%2][next]) continue;
                visited[turn%2][next] = visited[(turn-1)%2][here]+1;
                if(next == k){ //수빈이가 이동하려 하는데, 이동하려는 곳에서 동생이랑 만나는 경우
                    ret = turn;
                    ok=1;
                    break;
                }
                q.push(next);
            }
            if(ok) break;
        }
        if(ok) break;

        turn++;
    }
    
    cout << ret << "\n";

    return 0;

}
