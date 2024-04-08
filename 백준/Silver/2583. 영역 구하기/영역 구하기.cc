#include <bits/stdc++.h>
using namespace std;


int n, m, k, lx, ly, rx, ry, ny, nx,ret;
int a[104][104], visited[104][104]; //각각의 칸의 색칠여부를 나타낼 행렬과 방문 표시할 행렬
int area; //영역의 개수
vector<int> s; //각 영역별 칸의 수를 저장할 벡터
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, -1, 0, 1};

/*
int bfs(int y, int x){
    //너비 우선 탐색
    queue<pair<int,int>> q;
    int ret = 0;
    visited[y][x]=1;// 시작하는 곳 방문처리
    q.push({y, x});

    while(q.size()){
        tie(y,x) = q.front();
        q.pop();

        //4방향 탐색
        for(int i=0; i<4; i++){
            ny= y+dy[i];
            nx= x+dx[i];  

            if( ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
            if( visited[ny][nx] || a[ny][nx]) continue;
            visited[ny][nx]= visited[y][x]+1;
            ret = visited[y][x];
            q.push({ny, nx});
        }
    }
    return ret;
}*/

void dfs(int y, int x){
    //너비 우선 탐색
    visited[y][x]=1;// 시작하는 곳 방문처리
    ret++;

    //4방향 탐색
    for(int i=0; i<4; i++){
        ny= y+dy[i];
        nx= x+dx[i];  
        if( ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
        if( visited[ny][nx] || a[ny][nx]) continue;
        dfs(ny, nx);
    }
    return;
}


int main(){
    //1. 입력 값 받기
    
    cin >> n >> m >> k;

    //2. k번 반복해서 각 직사각형 꼭짓점 왼쪽 아래, 오른쪽 위의 값을 받기
    while(k--){
        cin >> rx >> ry >> lx >> ly;
        //3. 값을 받으면서 포함되는 영역 미리 칠하기

        for(int i = ry; i<ly ; i++){//왼쪽 아래 y부터 오른쪽 위 y까지
            for(int j =rx; j< lx ; j++){ //왼쪽 아래 x 부터 오른쪽 위 x까지
                a[i][j]=1;
            }
        }
        // 한칸을 빼야할 거 같은데 아닌가? 어차피 < 때문에 3 까지만 갈 듯
    }
    

    //4. 탐색 시작
    for(int i=0; i<n ; i++){
        for(int j=0; j<m ; j++){
            ret=0;
            // 방문하지 않았고, 색이 칠해져 있지 않다면
            if(visited[i][j] ==0 && a[i][j]==0){
                dfs(i, j);
                s.push_back(ret);
                area++;
            }
        }
    }

    cout << area << "\n";
    sort(s.begin(), s.end());
    for(int i=0; i<s.size(); i++){
        cout << s[i] << " ";
    }

    return 0;

}