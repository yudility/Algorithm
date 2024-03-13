#include <bits/stdc++.h>
using namespace std;

map<int, string> ntos;
map<string, int> ston;
int n, m, isNum;
string s, i_s;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;

    for(int i=0; i < n ; i++ ){
        cin >> s;
        ston.insert({s, i+1});
        ntos.insert({i+1, s});
    }

    for(int i =0 ; i <m ;i++){
        cin >> s;
        isNum = atoi(s.c_str()); 
        if(isNum){
            cout << ntos[isNum] << "\n";
        }
        else{
            cout << ston[s] << "\n";
        }
    }
    
    return 0;
}