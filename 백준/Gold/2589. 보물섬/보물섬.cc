#include <bits/stdc++.h>
using namespace std;

int n, m, md;
char a[54][54];
int visited[54][54];

const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};

void bfs(int y, int x){
    
    memset(visited, 0, sizeof(visited));
   
    visited[y][x] =1; 
    queue<pair<int, int>> q; //L경로가 들어갈 곳
    q.push({y,x});

    while(q.size()){
        tie(y, x) = q.front();
        q.pop();

        for(int i=0; i<4 ;i++){
            int ny = y+dy[i];
            int nx = x+dx[i];
            if(ny < 0 || nx < 0 || ny >= n || nx >= m ) continue;
            if(visited[ny][nx] ) continue;
            if(a[ny][nx]=='W') continue;
            visited[ny][nx]= visited[y][x] +1;
            md = max(visited[ny][nx], md);
            q.push({ny, nx});
        }
    }

    return;
}

int main(){

    //scanf("%d %d", &n, &m);

    cin >> n >> m;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            //scanf("%c", &a[i][j]); //& 써야되던가?
            cin >> a[i][j];
        }
    }
    
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(a[i][j]=='L') bfs(i,j);
        }
    }

    //    printf("%d\n", md-1);
    cout << md-1<< "\n";
    return 0;

}


