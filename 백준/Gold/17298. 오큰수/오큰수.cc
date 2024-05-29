#include <bits/stdc++.h>
using namespace std;

int n, m;
int a[1000004], ret[1000004];
stack<int> st;


int main(){
    
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> n;
    memset(ret, -1, sizeof(ret) );

    for(int i=0; i<n; i++){
        cin >> a[i]; 
        while(st.size() && a[i] > a[st.top()]){
            ret[st.top()]=a[i]; st.pop();
        }
        st.push(i);
    }

    for(int i=0; i<n; i++){
        cout << ret[i] << " ";
    }

    return 0;


}

