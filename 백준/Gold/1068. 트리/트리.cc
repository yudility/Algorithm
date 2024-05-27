#include <bits/stdc++.h>
using namespace std;

int n, x, d, root; //n은 노드 수, x는 입력 받을 수, d는 지울 노트 인덱스
vector<int> adj[54];

int dfs(int here){
    
    int ret=0;
    int child=0;

    for(int there :adj[here]){
        if(there == d) continue;
        ret += dfs(there);
        child++;
    }
    if( child == 0) return 1;
    return ret;
}  


int main(){

    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> n;

    for(int i=0; i< n; i++){
        cin >> x;
        if(x==-1)root=i;
        else adj[x].push_back(i);
    }
    //입력받고
    cin >> d;

    //지워야할 노드가 루트인 경우 0출력하고 프로그램 종료
    if(d== root) {
        cout << 0 << "\n"; 
        return 0;
    }

    //아니라면 로직 수행

    // 출력
    cout <<  dfs(root) << "\n";

    return 0;

}
