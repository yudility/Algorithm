#include <bits/stdc++.h>
using namespace std;

int n, m, sx, sy, ex, ey, cnt;
const int dy[]={-1,0,1,0};
const int dx[]={0,-1,0,1};
char a[303][303];
int visited[303][303];
bool ok=false;

void fastIO(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

void dfs(int y, int x){
    if(ok) return;

    visited[y][x]=1;

    if(a[y][x]=='#'){// 
        ok = true;
        return;
    }

    for(int i=0; i<4; i++){
        int ny= y +dy[i];
        int nx= x +dx[i];
        
        if(ny <=0 || nx <=0 || ny > n || nx >m) continue;
        if(visited[ny][nx]) continue;
        if(a[ny][nx]=='#'){
            ok = true;
            break;
        }
        else if(a[ny][nx]=='1'){
            visited[ny][nx]=1;
            a[ny][nx]='0';
            continue;        
        }
        else if(a[ny][nx]=='0' ) dfs(ny, nx);
    
    }
    return;
}

int main(){
    
    cin >> n >> m;
    cin >> sy >> sx >> ey >> ex;

    for(int i=1; i<=n ;i++){
        for(int j=1; j<=m ;j++){
            cin >> a[i][j];
        }
    }

    while(true){
        cnt++;
        memset(visited, 0, sizeof(visited));
        dfs(sy, sx);
        if(ok) break;
    }

    cout << cnt << "\n";
   
    return 0;
}