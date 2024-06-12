#include <bits/stdc++.h>
using namespace std;

int R, C, cnt, ret;
const int MAX = 22;
const int dy[] ={-1, 0, 1, 0};
const int dx[] ={0, -1, 0, 1};
char a[MAX][MAX];
int visited[MAX][MAX];
int alpa[26];

map<char, int> m;

void dfs(int y, int x){

    m[a[y][x]]++;
    cnt++;
    visited[y][x]=1;

    ret = max(ret, cnt);

    for(int i=0; i<4; i++){
        int ny=y+dy[i];
        int nx=x+dx[i];

        if(ny <0 || nx <0 || ny >= R || nx >= C || visited[ny][nx]) continue;
        if(m[a[ny][nx]]>0) continue;

        dfs(ny, nx);

    }
      
    cnt--;
    m[a[y][x]]--;
    visited[y][x]=0;


    return;
}


int main(){

    //map 초기화
    for(int i=0; i<26; i++){
        m.insert({65+i, 0});
    }
    

    //입력 받기
    cin >> R >> C; 

    for(int i =0; i <R; i++){
        for(int j=0; j<C ; j++){
            cin >> a[i][j];
        }
    }
    m[a[0][0]]++;
    dfs(0,0);

    //0,0 에서 시작해서 dfs 탐색
    //탐색 하면서 만나는 알파벳 개수--, visitied++
    //다른쪽 탐색도 수행해야하니까, visitied랑 -- 했던거 복구


    cout << ret << "\n";

    return 0;
}