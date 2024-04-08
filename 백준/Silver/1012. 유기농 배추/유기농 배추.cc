#include <bits/stdc++.h>

using namespace std;

int t, k, y, x, ny, nx, ret, n, m; //t 테케 개수, k 배추 개수

int dy[4]= {-1, 0, 1, 0};
int dx[4]= {0, -1, 0, 1};
int a[51][51];
bool visited[51][51]; 

void dfs(int y, int x){
    visited[y][x] = 1;
    for(int i = 0; i<4; i++){
        ny= y + dy[i];
        nx= x + dx[i];
        if(ny < 0 || nx < 0 || ny >= n || nx >= m ) continue;
        if(!visited[ny][nx] && a[ny][nx]==1 ){
            dfs(ny, nx);
        } 
    }
    return;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> t; 
    for(int i=0; i<t; i++){

        fill(&a[0][0], &a[0][0] + 51 * 51, 0);
        fill(&visited[0][0], &visited[0][0] + 51 * 51, 0);

        ret =0;
        cin >> m >> n >> k;
        
        for(int j=0; j<k ; j++){
            cin >> x >> y;
            a[y][x] = 1;
        }
        
        for(int h=0 ; h<n; h++){
            for(int l=0; l<m; l++ ){
                if(visited[h][l]==0 && a[h][l]==1){
                    dfs(h,l);
                    ret++;
                }
            }
        }

        cout << ret << "\n";
    }

    return 0;
}