#include <bits/stdc++.h>
using namespace std;

//1. 순열 또는 조합으로 모든 경우의 수를 하나씩 탐색
//2. DFS, BFS를 이용해서 cnt
//3. 그 중 Max값 저장
//4. 다시 원복해서 나머지 경우의 수 1부터 반복

int dy[] ={1, 0, -1, 0};
int dx[] ={0, -1, 0, 1};
int n, m, result;
int a[10][10], visited[10][10];

vector<pair<int, int>> wallCandidate;
vector<pair<int, int>> virus;

void dfs(int y, int x){
    for(int i=0; i<4; i++){
        int ny = y+dy[i];
        int nx = x+dx[i];
        if(ny < 0|| nx < 0 || ny >=n || nx >= m || visited[ny][nx] || a[ny][nx]==1 ) continue;
        visited[ny][nx]=1;
        dfs(ny, nx);
    }
    return;
}


int solve(){
    
    fill(&visited[0][0], &visited[0][0] + 10*10, 0);

    for(auto b : virus){
        visited[b.first][b.second] = 1;
        dfs(b.first, b.second);
    }

    int cnt = 0;
    for(int i=0; i < n; i++){
        for(int j=0; j< m ; j++){
            if(a[i][j]==0 &&!visited[i][j] ) cnt++;  // 
        }
    }

    return cnt;
}




int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    
    //맵을 입력받아서, 바이러스가 있는 곳과 빈칸인 곳 위치 저장
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> a[i][j];
            if(a[i][j]==0) wallCandidate.push_back({i, j});
            if(a[i][j]==2) virus.push_back({i,j});
        }
    }

    for(int i=0; i< wallCandidate.size(); i++){
        for(int j=0; j < i ; j++){
            for(int k=0; k < j ; k++){
                a[wallCandidate[i].first][wallCandidate[i].second] = 1;
                a[wallCandidate[j].first][wallCandidate[j].second] = 1;
                a[wallCandidate[k].first][wallCandidate[k].second] = 1;

                result = max(result, solve());

                a[wallCandidate[i].first][wallCandidate[i].second] = 0;
                a[wallCandidate[j].first][wallCandidate[j].second] = 0;
                a[wallCandidate[k].first][wallCandidate[k].second] = 0;

            }
        }
    }

    cout << result << "\n";

    return 0;

}