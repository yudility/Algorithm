#include <bits/stdc++.h>
using namespace std;

// 2차원 배열의 행과 열의 개수를 나타내는 수 N
// 2 <= N <= 100
int n, ny, nx;
int a[104][104]; //입력을 받을 곳
//int b[104][104]; //입력을 토대로 비교해서 색칠할 곳? -> 굳이? -> 그냥 숫자 비교하는 곳 로직을 바꾸면 될듯.
int visited[104][104];
int maxh, minh, safe, max_safe; //영역 중 최대 높이, 최소 높이, 안전 영역 개수
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, -1, 0, 1};

void dfs(int y, int x, int h){
    visited[y][x] = 1;
    //4방향 탐색
    for(int i=0; i<4; i++){
        ny = y+ dy[i];
        nx = x+ dx[i];

        //범위를 벗어날 경우 건너뛰기
        if(ny < 0 || nx < 0 || ny >= n || nx >= n) continue;
        //방문한 적이 있거나, 수위보다 높이가 낮을 경우 건너뛰기
        if(visited[ny][nx] || a[ny][nx] <= h) continue;
        dfs(ny, nx, h);
    }
    return;
}

int main(){

    //N과 행렬 입력 받기
    cin >> n;
    for(int i=0; i<n ; i++){
        for(int j=0; j<n; j++){
            cin >> a[i][j];
            if(maxh < a[i][j]){
                maxh = a[i][j]; //새로 들어온 값이 더 크면 최대 높이 갱신
            }
            if(minh > a[i][j]){
                minh = a[i][j]; //반복문 횟수를 줄이기 위한 최소 수위
            }
        }
    }

    //minh~ maxh까지 돌면서 각 분기마다 dfs 수행
    //매 반복문 마다 영역 개수 비교하고 최대 값인 경우 갱신

    for(int h= minh; h<maxh;h++){
        safe =0; // 초기화
        fill(&visited[0][0], &visited[0][0]+104*104, 0);

        for(int i =0; i<n; i++){
            for(int j=0; j<n; j++){
                //만약 지금 h보다 크고?, 방문한 적이 없으면 dfs
                if(a[i][j] > h && visited[i][j]==0){
                    dfs(i, j, h);
                    safe++;
                }
            }
        }
        if(safe > max_safe) {
            max_safe=safe;
        }
    }
    cout << max_safe << "\n";

    return 0;

}