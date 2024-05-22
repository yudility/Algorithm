#include <bits/stdc++.h>
using namespace std;

string s; 
int t;

int main(){

    ios_base::sync_with_stdio(false);

    cin.tie(NULL);
    cout.tie(NULL);

    cin >> t;

    for(int i=0 ; i<t;i++){
        cin >> s;
        stack<char> st; //stack
        int j=0;
        while(j< s.length()){
            if(s[j]=='('){
                st.push(s[j]);
            }
            else if(s[j]==')' && st.size()==0){
                break;
            }
            else{ //s[i]==')'&& st.size()>0
                st.pop();
            }
            j++;
        }

        if(st.size()==0 && j==s.length()){
            cout << "YES\n";
        }else{
            cout << "NO\n";
        }

    }
    
}