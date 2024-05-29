#include <bits/stdc++.h>
using namespace std;

int n, m, a, b, mx;
int visited[10003];
int result[10003];
vector<int> adj[10003];


int dfs(int here){

    int ret=1;
    visited[here]=1;
    for(int there: adj[here]){
        if(!visited[there]){
            ret+=dfs(there);
        }
    }
     //ret=1이란 소리는 위에 for문에서 자식 노드를 방문하지 않았다는 뜻이므로
    if(ret==1) return 1;

    return ret;
}

int main(){

    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> n >> m;

    for(int i=0; i<m; i++){
        cin >> a >> b;
        adj[b].push_back(a);
    }

    for(int i=1; i<=n; i++){
        memset(visited, 0, sizeof(visited));
        result[i]= dfs(i);
        mx= max(mx, result[i]);
    }

    for(int i=1; i<=n; i++){
        if(mx==result[i]){
            cout << i << " ";
        }
    }
}