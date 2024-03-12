#include <bits/stdc++.h>
using namespace std;

unsigned long long pos;
string p, s, f, b, bufferflush;
int n;
vector<string> ret;

vector<string> split(string input, string delimeter){

    getline(cin, bufferflush);
    string token = "";
    while((pos = input.find(delimeter))!= string::npos){
        token = input.substr(0, pos);
        ret.push_back(token);
        input.erase(0, pos+delimeter.length());
    }
    ret.push_back(input);
    return ret;
}

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n; 
    vector<string> pa;
    string bf;

    cin >> p;
    pa = split(p, "*");
    f = pa[0];
    b = pa[1];

    for(int i=0; i<n ; i++){
        getline(cin, s);
        if(s.length()< f.length()+b.length()){
            cout << "NE" << "\n";   
        }
        else {
            if(s.substr(0, f.length())!=f || s.substr(s.length()-b.length(), s.length())!=b) 
                cout << "NE" << "\n";
            else cout << "DA" << "\n";
        }
    }
            
    return 0;
}