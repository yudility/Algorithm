#include <bits/stdc++.h>
using namespace std;

int r, c, k, v[6][6], cnt;
int dy[]={-1, 0, 1, 0};
int dx[]={0, -1, 0, 1};
char a[6][6];

void find(int y, int x, int d){
    if(y==0 && x== c-1 ){
        if(d==k){
            cnt++;
        } 
        return;
    }

    for(int i=0; i<4; i++){
        int ny= y+ dy[i];
        int nx= x+ dx[i];
        
        if(ny<0 || nx <0 || ny >=r || nx >= c|| v[ny][nx]) continue;
        if(a[ny][nx]=='T') continue;
        v[ny][nx]=1;
        find(ny, nx, d+1);
        v[ny][nx]=0;
    }

    return;
}

int main(){

    cin >> r >> c >> k;

    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            cin >> a[i][j];
        }
    }
    v[r-1][0]=1;
    find(r-1, 0, 1);

    cout << cnt << "\n";
    return 0;
}