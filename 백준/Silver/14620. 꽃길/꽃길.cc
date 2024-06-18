#include <bits/stdc++.h>
using namespace std;

int n, a[11][11], visited[11][11], ret=987654321;
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, -1, 0, 1};

void fastIO(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

bool check(int y, int x){
    if(visited[y][x]) return 0;
    for(int i=0; i<4; i++){
        int fy=y+dy[i];
        int fx=x+dx[i];
        if(fy <0 || fx <0 || fy>=n || fx >= n || visited[fy][fx]) {
            return 0;
        }
    }
    return 1;
}

void eraseFlower(int y, int x){
    visited[y][x]=0;
    for(int i=0; i<4; i++){
        int fy=y+dy[i];
        int fx=x+dx[i];
        visited[fy][fx] = 0;
    }
}

int setFlower(int y, int x){
    visited[y][x]=1;
    int s = a[y][x];
    for(int i=0; i<4; i++){
        int fy=y+dy[i];
        int fx=x+dx[i];
        visited[fy][fx] = 1 ;
        s+=a[fy][fx];
    }
    return s;
}


void flower(int cnt, int sum){
    if(cnt == 3){
        ret = min( sum, ret);
        return;
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(check(i,j)){
                flower(cnt+1, sum+setFlower(i, j));
                eraseFlower(i, j);
            }
        }
    }

}

int main(){

    fastIO();

    cin >> n;

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> a[i][j];
        }
    }

    flower(0, 0);

    cout << ret << "\n";


    return 0;
}