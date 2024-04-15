#include <bits/stdc++.h>
using namespace std;

int n, c, m;
map<int, int> mp, mpord;
// mp : 숫자 - counting
// ord: 숫자 - 들어온 순서
vector<pair<int, int>> v;
//v : counting - 숫자

bool cmp(pair<int, int> a, pair<int, int> b){
    if(a.first==b.first){
        return mpord[a.second] < mpord[b.second];
    }
    return a.first > b.first;
}


int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> c;
    
    for(int i=0; i<n; i++){
        cin >> m;
        if(mp.find(m)==mp.end()){
            mp[m]=1;
            mpord[m]=i+1;
        }
        else{
            mp[m]++;
        }
    }
    for(auto it : mp){
        v.push_back({it.second, it.first});
    }
    
    sort(v.begin(), v.end(), cmp);
    for(auto it :v){
        for(int j=0; j<it.first; j++){
            cout << it.second<< " ";
        }
    }

    return 0;
}