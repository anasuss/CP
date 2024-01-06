    #include<bits/stdc++.h>
    typedef long long  ll;
     
    #define all(x) (x).begin() , (x).end()
    #define pb push_back
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
     
    const int N = 3e5+100 ;
     
    const int mod = 1e9+7 ;
     
     
     
    int n ;
    
    vector<int> graph[N] ; 

    bool vis[N] ; 
    
    bool color[N] ; 

    // detect odd length cycle ; 
    bool bipartite(int node){
        vis[node] = true ; 
        for (int child : graph[node]){
            if (!vis[child]){
                color[child] = (color[node]^1) ; 
                if (!bipartite(child))
                    return false ;  
            }else if (color[child] == color[node])
                return false ; 
        }
        return true ; 
    }

    int m ; 

    void solve(){
        cin >> n >> m ;
        for (int i = 0 ; i<=n ; i++){
            color[i] = -1 ; 
        }
        vector<pii> v ; 
        for (int i = 0 ; i<m ; i++){
            int x , y ; cin >> x >> y ; --x; --y; 
            graph[x].pb(y) ; 
            graph[y].pb(x) ; 
            v.pb({x,y}) ; 
        } 
        color[0] = 1 ; 
        if (!bipartite(0)){
            no ; 
            return ; 
        } 
        yes;
        for (int i = 0 ; i<v.size() ; i++){
            if (color[v[i].first] == 0 && color[v[i].second] == 1){
                cout << 0 ; 
            }else
                cout << 1 ; 
        }
        return ;
    }
     
     
     
    int main(){
        SaveTime
        //freopen("input.txt","r",stdin) ;
        int t = 1 ;
        //cin >> t ;
        for (int i = 1 ; i<=t ; i++){
            solve() ;
        }
    }