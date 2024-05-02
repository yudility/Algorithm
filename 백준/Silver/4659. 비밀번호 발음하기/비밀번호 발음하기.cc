#include <bits/stdc++.h>
using namespace std;

string s; 
bool isM, flag; 
int mc, gc; 

bool isV(char idx){
    if( idx == 'a' || idx == 'e'|| idx == 'i'|| idx == 'o'|| idx == 'u')
        return true;
    return false;
}


int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    while(true){
        cin >> s;

        if(s=="end"){
            break;
        }

        isM = false; flag = false;
        mc = 0; gc = 0;
        char prev ='*';

        for(int i=0; i<s.size(); i++){
            char idx = s[i];

            if(isV(idx)){
                mc++;
                gc=0;
                isM = true;
            }
            else{
                gc++;
                mc=0;
            }
            if(mc>=3 || gc >=3){
                flag = true;
                break;
            }
            
            if(i>=1){
                prev = s[i-1];
                if(prev == idx){
                    if(idx != 'e' && idx != 'o'){
                        flag = true;
                        break;   
                    }
                    else{
                        continue;
                    }
                }         
            }
        }
        if(!isM) flag = true;

        if(flag){
            cout << "<" << s << "> is not acceptable.\n";
        }else{
            cout << "<" << s << "> is acceptable.\n";
        }

    }
    
    
    return 0;
} 