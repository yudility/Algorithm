#include <bits/stdc++.h>
using namespace std;

int n, l, r, days, cnt, sum;
int a[54][54], visited[54][54];
const int dy[]={-1, 0, 1, 0};
const int dx[]={0, -1, 0, 1};
vector<pair<int, int>> unites;

void go(int y, int x, vector<pair<int, int>> &unites){

    for(int i=0; i<4; i++){
        int ny=y+dy[i];
        int nx=x+dx[i];
        if(ny<0 || nx< 0|| ny>=n || nx>=n || visited[ny][nx]) continue;
        if(abs(a[y][x]-a[ny][nx]) >= l && abs(a[y][x]-a[ny][nx]) <= r ){
            visited[ny][nx]=1;
            sum += a[ny][nx]; 
            unites.push_back({ny, nx});
            go(ny, nx, unites);
        }
    }
    return;
}


int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> l >> r;

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> a[i][j];
        }
    }
    
    
    while(true){
        memset(visited, 0, sizeof(visited));

        bool flag= true;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(!visited[i][j]) {
                    unites.clear();
                    sum = a[i][j];
                    visited[i][j]=1;
                    unites.push_back({i,j});
                    go(i, j, unites);
                    if(unites.size()==1)continue;
                    for(pair<int, int> c:unites){
                        a[c.first][c.second] = sum / unites.size();
                        flag = false;
                    }
                }
            }
        }

        if(flag)break;
        days++;
    }

    cout << days <<"\n";

    return 0;
}