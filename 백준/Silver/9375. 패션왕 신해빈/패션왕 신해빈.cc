#include <bits/stdc++.h>
using namespace std;

int n, m, ret;
string s, k;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    
    for(int i=0; i<n ; i++){
        map<string, int> c;
        int ret = 1;
        cin >> m;

        for(int j=0; j<m ; j++){
            cin >> s >> k;
            if(c.find(k)!=c.end())
                c[k]++;
            else
                c.insert({k, 1});
        }
        for(auto a: c){
            ret *= (a.second+1);
        }

        ret = ret-1;
        cout << ret << "\n";
    }

    return 0;
}