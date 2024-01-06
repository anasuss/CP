#include <bits/stdc++.h> 
using namespace std ; 
int n ; 
struct Node{
    int c[26] ; 
    int flag ; 
    Node(){
        for (int i = 0 ; i<26 ; i++) c[i] = -1 ; 
        flag = false ; 
    }
};

vector<Node> nxt ; 

void insert(const string &s){
    int root = 0 ; 
    for (int i = 0 ; i<s.size() ; i++){
        int x = s[i]-'a' ;
        if (nxt[root].c[x] == -1){
            nxt[root].c[x] = nxt.size(); 
            nxt.push_back(Node()) ; 
        }
        root = nxt[root].c[x] ; 
    }
    nxt[root].flag = true ; 
}

string ans = "" ; 
bool ok = false ; 
void dfs(int node , string &s){
    if (s.size()>ans.size()){
        ans = s ; 
        ok = true ; 
    }
    for (int i = 0 ; i<26 ; i++){
        if (nxt[node].c[i] != -1 && nxt[nxt[node].c[i]].flag){
            s+=char(i+'a') ; 
            dfs(nxt[node].c[i],s);
            s.pop_back() ; 
        }
    }
}
string completeString(int n, vector<string> &a){
    ans = "" ; 
    nxt.clear() ; 
    nxt.push_back(Node()) ;
    ok = 0;   
    for (string &s : a){
        insert(s) ; 
    }
    string s = "" ; 
    dfs(0,s) ; 
    if (ok)
        return ans ; 
    else 
        return "None" ; 
}
void solve(){
    cin >> n ; 
    vector<string> v(n) ; 
    for (auto &s : v) cin >> s ; 
    cout << completeString(n,v) << endl ; 
    return ;
}
     
     
     
    int main(){
       // SaveTime
       // freopen("input.txt","r",stdin) ;
        int t = 1 ;
        cin >> t ;
        for (int i = 1 ; i<=t ; i++){
            solve() ;
        }
    }