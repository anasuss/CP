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
     
    const int N = 3e5+10 ;
     
    const int mod = 1e9+7 ;
    
    const int L = 18 ; 
     
     
    int n ;
    
    map<int,int> tree[N] ; 

    int up[N][L] ; 

    int mn[N][L] ; 

    int depth[N] ; 

    int power[L] ; 
    

    void dfs(int node , int parent){
        up[node][0] = parent ; 
        mn[node][0] = tree[node][parent] ; 
        for (auto p : tree[node]){
            
            int child = p.first ; 

            if (child == parent) continue ; 

            depth[child] = depth[node]+1 ;

            dfs(child,node) ; 
        }
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
        depth[0] = 0 ; 
        dfs(0,0) ; 
        for (int j = 1 ; j<L ; j++){
            for (int i = 0 ; i<n ; i++){
                up[i][j] = up[up[i][j-1]][j-1] ; 
                mn[i][j] = min(mn[i][j-1],mn[up[i][j-1]][j-1]) ; 
            }
        } 
    }
    int goUp(int u , int v){
        int dist = get_dist(u,v) ; 
        int ans = 1e9+10 ; 
        for (int i = L-1 ; i>=0 ; i--){
            if (dist-power[i]>=0){
                ans = min(ans,mn[u][i]) ; 
                u = up[u][i] ;
                dist-=power[i] ; 
            }
        }
        return ans ; 
    }
    int m ; 
    void solve(){
        cin >> n >> m;
        for (int i = 0; i <m ; i++) {
            int u , v , w ; cin >> u >> v >> w ; --u , --v ; 
            tree[u][v] = w ; tree[v][u] = w ; 
        }
        prep() ; 
        int q;
        cin >> q;
        while (q--){
            int u, v;
            cin >> u >> v; --u,--v ; 
            int lca = getLCA(u,v) ; 
            cout << min(goUp(u,lca),goUp(v,lca)) << endl ; 
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