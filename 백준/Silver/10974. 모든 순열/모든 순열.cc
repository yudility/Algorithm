#include <bits/stdc++.h>
using namespace std;

int main(){
    vector<int> v;
    int n;

    cin >> n;

    for(int i=1; i<=n ; i++) v.push_back(i);

    do{
        for(int j:v) cout << j << " ";
        cout << "\n";
    }while(next_permutation(v.begin(), v.end()));
    
    return 0;
}