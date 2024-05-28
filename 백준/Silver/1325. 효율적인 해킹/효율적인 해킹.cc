#include <bits/stdc++.h>
using namespace std;

int n, m, a, b, mc;
vector<int> adj[10003];
int result[10003];
int visited[10003];
int dfs(int here){
    int ret=1;
    for(int there :adj[here]){
        if(visited[there]) continue;
        visited[there] = 1;
        ret += dfs(there);
    }
    return ret;
}

int main(){

    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> n >> m;

    for(int i=1; i<= m; i++){
        cin >> a >> b;
        adj[b].push_back(a);
    }

    for(int i=1; i<=n; i++){
        memset(visited, 0, sizeof(visited));
        //fill(&visited[0],&visited[0]+10004 , 0);
        visited[i] =1;
        result[i]=dfs(i);
        mc = max(mc, result[i]);
    }

    for(int i=1; i<=n; i++){
        if(mc == result[i]) cout << i << " ";
    }
    
    return 0;
}