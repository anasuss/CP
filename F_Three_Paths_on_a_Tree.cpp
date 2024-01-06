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

    int dist[N] ; 
    
    int dist1[N] ; 

    int mx , mxnode ; 

    int up[N][L] ; 

    int depth[N] ; 

    int power[L] ; 
    
    int x , y , z ; 

    void dfs(int node , int parent){
        up[node][0] = parent ; 
        for (int j = 1 ; j<L ; j++){
            up[node][j] = up[up[node][j-1]][j-1] ; 
        } 
        for (int child : tree[node]){
            if (child == parent) continue ; 
            depth[child] = depth[node]+1 ;
            dfs(child,node) ; 
        }
    }

    int getLCA(int u , int v){
        if (depth[u]<depth[v]) swap(u,v) ; 
        int l = depth[u]-depth[v] ;
        for (int i = L-1 ; i>=0 ; i--){
            if (l-(1<<i)>=0){
                u = up[u][i] ; 
                l-=(1<<i) ; 
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
        depth[x] = 0 ; 
        dfs(x,x) ; 
    }
    
    void dfs1(int node , int parent){
        if (parent != -1) dist[node] = dist[parent]+1 ; 
        if (dist[node]>mx){
            mx = dist[node] ; 
            mxnode = node ; 
        }
        for (int child : tree[node]){
            if (child == parent) continue;
            dfs1(child,node) ; 
        }
    }
    void dfs2(int node , int parent){
        if (parent != -1) dist1[node] = dist1[parent]+1 ; 
        if (dist1[node]>mx){
            mx = dist1[node] ; 
            mxnode = node ; 
        }
        for (int child : tree[node]){
            if (child == parent) continue;
            dfs2(child,node) ; 
        }
    }
    int diamater(){
        for (int i = 0 ; i<=n ; i++){
            dist[i] = 0 ; 
        }  
        dfs1(0,-1) ; 
        for (int i = 0 ; i<=n ; i++){
            dist[i] = 0 ; 
        }
        x = mxnode ; 
        mx = 0 ; 
        dfs1(mxnode,-1) ; 
        y = mxnode ;      
        mx = 0 ; 
        dfs2(mxnode,-1) ;    
        return mx ; 
    }
    
    void solve(){
        cin >> n ;
        for (int i = 0 ; i<n-1 ; i++){
            int x , y ; cin >> x >> y ; --x ; --y ; 
            tree[x].pb(y) ; 
            tree[y].pb(x) ; 
        } 
        int diam = diamater() ;
        int ans = diam ; 
        prep() ;  
        z = -1 ; 
        for (int i = 0 ; i<n ; i++){
            if (i == x || i == y) continue;
            int lca = getLCA(i,y) ; 
            if (lca != i && lca != y && lca != x){
                if (diam+get_dist(lca,i)>ans && i != x && i != y){
                    ans = diam+get_dist(lca,i) ; 
                    z = i ; 
                }
            }
        }
        if (z == -1) z = up[y][0] ; 
        cout << ans << endl ; 
        cout << x+1 << " " << y+1 << " " << z+1 ;
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