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
     
    const int N = 2e5+100 ;
     
    const int mod = 1e9+7 ;
     
     
     
    int n,m ; 

    vector<pair<int,ll>> graph[N] ;

    int par[N] ; 

    bool visited[N] ; 

   // shortest path graph 

    void dijkstra(){
        priority_queue <pll, vector<pll>, greater<pll>> pq ;
        vector<ll> dist(n,inf) ; 
        // node start 0 
        pq.push({0,0}) ; 
        dist[0] = 0 ; 
        while(!pq.empty()){
            ll w = pq.top().first ; 
            ll node = pq.top().second ; 
            pq.pop() ; 
            if (visited[node]) continue; 
            visited[node] = 1 ; 
            for (auto x : graph[node]){
                ll child = x.first ; 
                ll wch = x.second ; 
                if (dist[node]+wch<dist[child]){
                    dist[child] = dist[node]+wch ; 
                    par[child] = node ; 
                    pq.push({dist[child],child}) ; 
                }
            }
        }
    }
    void solve(){
        cin >> n >> m ;
        for (int i = 0 ; i<m ; i++){
            ll u , v , w ; cin >> u >> v >> w ; --u;--v ;  graph[u].pb({v,w}) ; 
            graph[v].pb({u,w}) ; 
        } 
        for (int i = 0 ; i<=n ; i++) par[i] = -1 ; 
        dijkstra() ;
        if (par[n-1] == -1){
            cout << -1 ; return ; 
        }
        vector<ll> ans ; 
        ll x = n-1 ; 
        ans.pb(x) ; 
        while(par[x] != -1){
            ans.pb(par[x]) ; 
            x = par[x] ; 
        }
        reverse(all(ans)) ; 
        for (ll i : ans ) cout << i+1 << " " ; 
        return ;
    }
     
     
     
    int main(){
        SaveTime
       // freopen("input.txt","r",stdin) ;
        int t = 1 ;
        //cin >> t ;
        for (int i = 1 ; i<=t ; i++){
            solve() ;
        }
    }