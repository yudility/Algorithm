#include <bits/stdc++.h>
using namespace std;


int n, m, nofc, d, mind;
int a[52][52];
vector<pair<int, int>> houses;
vector<pair<int, int>> chickens;
vector<vector<int>> cLists;


void combi(int start,vector<int> v){

    
    if(v.size() == m){
        cLists.push_back(v);
        return;
    }

    for(int i=start+1; i<chickens.size() ;i++){
        v.push_back(i);
        combi(i, v);
        v.pop_back();
    }
    
    return;
}

int main(){
    
    cin >> n >> m;

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> a[i][j];
            if(a[i][j]==1) houses.push_back({i, j});
            if(a[i][j]==2) chickens.push_back({i, j});
        }
    }

    //치킨집 조합목록 만들기
    vector<int> v;
    combi(-1, v);

    int result = 9999999;

    //치킨집 조합 목록을 토대로 각 경우의 수에서 치킨 거리 구하기
    for( auto clist : cLists){
        
       int ret=0; 
       for(auto h: houses){
            int mind = 900000;
            for(auto c: clist){
                int dist = abs(h.first -chickens[c].first) + abs(h.second -chickens[c].second) ;
                mind = min( dist, mind);
            }
            ret+=mind;
       }
       result = min(ret, result);
    }


    cout << result << "\n";
    
    return 0;

}