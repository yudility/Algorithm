#include <bits/stdc++.h>
using namespace std;

string str;

string go(string s){
    bool isB=true;
    stack<char> st;
    for(int i=0; i<s.length(); i++){
        if(s[i]=='(' || s[i]=='['){
            st.push(s[i]);
        }
        else if(s[i]==']'|| s[i]==')'){
           if(st.size()==0) {
                isB=false;
                break;
           }
           else if(s[i]==']'&& st.top() =='('){
             isB=false;
                break;
           }
           else if(s[i]==')'&& st.top() =='[' ){
             isB=false;
                break;
           }

           else if(s[i]==']'&& st.top() =='[') st.pop();
           else if(s[i]==')'&& st.top() =='(' ) st.pop();
        }
    }
            
    if(isB && st.size()==0) return "yes\n";
    else return "no\n";
}


int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    while(true){
        
        getline(cin, str);

        if(str ==".") break;

        cout << go(str);
    } 

    return 0;
}