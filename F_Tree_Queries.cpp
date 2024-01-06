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
     
    const int N = 2e5+10 ;
     
    const int mod = 1e9+7 ;
    
    const int L = 18 ; 
     
     
    int n ;
    
    vector<int> tree[N] ; 

    int up[N][L] ; 
    
    int depth[N] ; 

    int power[L] ; 
    
    vector<int> leafs ; 

    int p[N] ; 

    void dfs(int node , int parent){
        bool isleaf = true ; 
        up[node][0] = parent ; 
        p[node] = parent ; 
        for (auto child : tree[node]){    
            if (child == parent) continue ; 
            isleaf = false ; 
            depth[child] = depth[node]+1 ;
            dfs(child,node) ; 
        }
        if (isleaf) leafs.pb(node) ; 
    }

    int getLCA(int u , int v){
        if (depth[u]<depth[v]) swap(u,v) ; 
        int l = depth[u]-depth[v] ;  
        for (int i = L-1 ; i>=0 ; i--){
            if (l-power[i]>=0){
                u = up[u][i] ; 
                l-=power[i] ; 
            }
        }
        for (int i = L-1 ; i>=0 ; i--){
            if (up[u][i] != up[v][i]){
                u = up[u][i] ; 
                v = up[v][i] ;
            }
        }
        if (u != v){
            u = up[u][0] ; 
        }  
        return u ; 
    }

    int get_dist(int u , int v){
        return depth[u]+depth[v]-2*depth[getLCA(u,v)] ; 
    } 

    void prep(){
        p[0] = -1 ; 
        depth[0] = 0 ; 
        dfs(0,0) ; 
        for (int j = 1 ; j<L ; j++){
            for (int i = 0 ; i<n ; i++){
                up[i][j] = up[up[i][j-1]][j-1] ; 
            }
        } 
    }
    int m ; 
    void solve(){
        cin >> n >> m;
        for (int i = 0 ; i<n-1 ; i++){
            int u , v ; cin >> u >> v ; --u ; --v ; 
            tree[u].pb(v) ; 
            tree[v].pb(u) ; 
        }
        prep() ; 
        p[0] = -1 ; 
        vector<int> v ; 
        while(m--){
            int k ; cin >> k ; 
            int mxdepth = 0 ; int nodemx = 0 ; 
            v.clear() ; 
            for (int i = 0 ; i<k ; i++){
                int x ; cin >> x ;--x; v.pb(x) ; 
                if (mxdepth<depth[x]){
                    mxdepth = depth[x] ; 
                    nodemx = x ; 
                }
            }
            bool ok = true ; 
            for (int i = 0 ; i<k ; i++){
                int x = getLCA(nodemx,v[i]) ; 
                if (x == v[i] || x == nodemx) continue; 
                int parent = p[v[i]] ; 
                x = getLCA(nodemx,parent) ; 
                if (x == parent || x == nodemx) continue; 
                ok = false ; 
                break ; 
            }
            if (ok) yes ; 
            else no ; 
        }
        return ;
    }
     
     
     
    int main(){
        SaveTime
        //freopen("input.txt","r",stdin) ;
        int t = 1 ;
        for (int i = 0 ; i<L ; i++)
            power[i] = (1 << i) ; 
       // cin >> t ;
        for (int i = 1 ; i<=t ; i++){
            solve() ;
        }
    }