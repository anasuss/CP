    #include<bits/stdc++.h>
    typedef long long  ll;
     
    #define all(x) (x).begin() , (x).end()
    #define pb push_back
    #define getunique(v) {sort(all(v)); v.erase(unique(all(v)), v.end());}
    #define sz(x) (int)(x).size()
    #define yes cout << "YES\n"
    #define no cout << "NO\n"
    #define nope cout << "-1\n" ;
    #define pii pair<int,int>
    #define pll pair<ll,ll>
    #define SaveTime ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    #define endl "\n"
     
    using namespace std;
     
    const int INF = 1000*1000*1000; // 1 e 9
    const ll inf = (ll)1e18;
     
    const int N = 2e2+10;
     
    const int mod = 1e9+7 ;
     
     
     
    int n ;
    string s ;
    vector<int> graph[N] ; 
    int color[N] ; 
    bool vis[N] ; 
    bool bipartite(int node){
        queue<int> q ; 
        q.push(node) ;
        color[node] = 1 ; 
        while(!q.empty()){
            node = q.front() ;
            q.pop() ;  
            vis[node] = 1 ; 
            for (int child : graph[node]){
                if (!vis[child]){
                    q.push(child) ;
                    color[child] = (color[node]^1) ; 
                }else if (color[child] == color[node]){
                    return false ; 
                }
            }
        } 
        return true ; 
    }
    void solve(){
        cin >> n >> s ; 
        for (int i = 0 ; i<s.size() ; i++){
            for (int j = i+1 ; j<sz(s) ; j++){
                if (s[j]<s[i]){
                    graph[i].pb(j) ; 
                    graph[j].pb(i) ; 
                }
            }
        }
        for (int i = 0 ; i<sz(s) ; i++){
            if (!vis[i] && !bipartite(i)){
                no ; 
                return ;
            }
        } 
        yes ; 
        for (int i = 0 ; i<n ; i++){
            cout << color[i] ;  
        }
        return ;
    }
     
     
     
    int main(){
        SaveTime
       // freopen("input.txt","r",stdin) ;
        int t = 1 ;
       // cin >> t ;
        for (int i = 1 ; i<=t ; i++){
            solve() ;
        }
    }