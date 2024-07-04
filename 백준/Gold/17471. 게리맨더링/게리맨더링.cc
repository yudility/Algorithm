#include <bits/stdc++.h>
using namespace std;


int a[12];   // 각 구역의 인구수
int g[11];   // 각 구역이 속한 선거구 ( 0 | 1 )
int n, c, d; // 구역수, 인접한 구역의 수, 인접한 구역의 번호
vector<int> adj[12]; //연결 리스트
int visited[11]; // 방문 처리

const int INF = 987654321;
int ret = INF; // 결과 값 (최소 인구 차이)


// void go(int here, int depth){

//     visited[here]=1;
//     int rsum = 0;
//     int lsum = 0;

//     if(depth == n){
//         //인구 차이 계산
//         for(int i=0; i<n; i++){
//             if(g & (1 << i)){
//                 rsum += a[i];
//             }
//             else{
//                 lsum += a[i];
//             } 
//         }
//         diff = abs(rsum-lsum);
//         ret = min(ret, diff);
//         return;
//     }
    
//     for(int i=0; i < v[here].size(); i++){
//        if(visited[v[here][i]]) continue;
//        g |=(1 << v[here][i]);//인접한 구역 번호를 켜기
//        go(v[here][i], depth+1);//켜져있는 상태로 그 구역 들어가기
//        g &= ~(1 << v[here][i]);//인접한 구역 번호를 끄기
//        go(v[here][i], depth+1);
//     }

//     return;
// }


pair<int, int> dfs(int here, int num){

    visited[here]=1;
    pair<int, int> result = {1, a[here]}; //초기값 세팅

    for(int there : adj[here]){
        if(g[there] != num) continue;
        if(visited[there]) continue;
        pair<int, int> temp = dfs(there, num);
        result.first += temp.first; //구역 count
        result.second += temp.second; //인구 수 count
    }
    return result;
}


int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    //1. 입력 받기
    cin >> n;

    for(int i=1; i<=n; i++){
        cin >> a[i];
    }

    for(int i=1; i<=n ; i++){
        cin >> c;
        for(int j=0; j<c; j++){
            cin >> d;
            adj[i].push_back(d);
            adj[d].push_back(i);
            //양방향 간선
        }
    }

    for(int i=1; i< (1<<n)-1; i++){
        fill(g, g+11, 0);
        fill(visited, visited+11, 0);
        int idx1 =-1, idx2= -1; // 초기값을 지정
        //각 구역의 시작점을 나타냄과 동시에
        //반복문을 전부 돌았음에도 -1인 경우, 연결되어있는 곳이 없다고 판단하기 위함

        for(int j=0; j<n; j++){
            if( i & (1 << j)){
                g[j + 1]= 1;
                idx1 = j + 1;
            }
            else { idx2 = j + 1;}
        }

        // .first (각 선거구에 속한 구역 수)
        // .second (각 선거구의 인원 수)
        pair<int, int> g1= dfs(idx1, 1);
        pair<int, int> g2= dfs(idx2, 0);
    
        if(g1.first + g2.first == n ){
            ret = min(ret, abs(g1.second - g2.second));
        }
    }

    //3. 결과 출력
    cout << (ret==INF ? -1 : ret) << '\n';

    return 0;
}