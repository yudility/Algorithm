#include <bits/stdc++.h> 
using namespace std;

int ret, n;
int visited[64][64][64];

int attack[6][3]={
    {9, 3, 1},
    {9, 1, 3},
    {3, 9, 1},
    {3, 1, 9},
    {1, 3, 9},
    {1, 9, 3}
};

struct A{
    int a; 
    int b;
    int c;
};

struct A svn={0,0,0};

int main(){

    cin >> n;

    cin >> svn.a >> svn.b >> svn.c;

    //bfs 최단거리 찾기 활용 -> <=0 <=0 <=0 하면 출력!

    queue<A> q;
    q.push(svn);

    while(q.size()){
        int s1 = q.front().a;
        int s2 = q.front().b;
        int s3 = q.front().c;
        q.pop();

        if(s1==0 && s2==0 && s3==0){
            ret = visited[s1][s2][s3];
            break;
        }

        for(int i=0; i<6; i++){
            int na = max(0, s1 - attack[i][0]);
            int nb = max(0, s2- attack[i][1]);
            int nc = max(0, s3 - attack[i][2]);
            
            if(visited[na][nb][nc])continue;

            visited[na][nb][nc] = visited[s1][s2][s3]+1;
            q.push({na, nb, nc});
        }
    }

    cout << ret << "\n";

    return 0;

}

