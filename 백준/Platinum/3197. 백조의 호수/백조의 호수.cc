#include <bits/stdc++.h>
using namespace std;

const int MAX = 1502;
const int dy[]={-1, 0, 1, 0};
const int dx[]={0, -1, 0, 1};

int r, c, y, x, cnt, sy, sx; 
char a[MAX][MAX];
int swan_visited[MAX][MAX];
int water_visited[MAX][MAX];
queue<pair<int, int>> waterQ;
queue<pair<int, int>> waterQ_temp;
queue<pair<int, int>> swanQ;
queue<pair<int, int>> swanQ_temp;

void Qclear(queue<pair<int, int>> &q){
    queue<pair<int, int>> empty;
    swap(q, empty);
}

bool swan(){
    while (swanQ.size()){
        tie(y, x) = swanQ.front();
        swanQ.pop();

        for(int i=0; i<4; i++){
            int ny=y+dy[i];
            int nx=x+dx[i];
            if( ny < 0 || nx < 0 || ny >= r || nx >= c || swan_visited[ny][nx] ) continue;
            swan_visited[ny][nx]=1;
            if(a[ny][nx]=='.') swanQ.push({ny, nx});
            else if(a[ny][nx]=='X') swanQ_temp.push({ny, nx});
            else if(a[ny][nx]=='L') return true;
        }
    }

    return false;
}

void water_melting(){

    while (waterQ.size()){
        tie(y, x) = waterQ.front();
        waterQ.pop();

        for(int i=0; i<4; i++){
            int ny=y+dy[i];
            int nx=x+dx[i];

            if( ny < 0 || nx < 0 || ny >= r || nx >= c || water_visited[ny][nx]) continue;
            if( a[ny][nx]=='X'){
                waterQ_temp.push({ny, nx});
                water_visited[ny][nx]=1;
                a[ny][nx]='.';
            } 
        }
    }
    return;
}



int main(){ 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> r >> c; 
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            cin >> a[i][j];
            if(a[i][j]=='L'){
                sy = i;
                sx = j;
            }
            if(a[i][j]=='.' || a[i][j]=='L' ){water_visited[i][j]=1; waterQ.push({i, j});}
        }
    }
    swanQ.push({sy, sx});
    swan_visited[sy][sx]= 1;
    
    while(true){
        // 백조들이 만나는지 bfs로 확인
        if(swan()) break;
        water_melting();

        waterQ = waterQ_temp;
        swanQ = swanQ_temp;
        Qclear(waterQ_temp);
        Qclear(swanQ_temp);
        cnt++;
    }

    cout << cnt << "\n";        

    return 0;
}