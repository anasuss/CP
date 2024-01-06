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
    
    const int L = 19 ; 
     
     
    int n ;
    
    vector<int> tree[N] ; 

    int up[N][L] ; 

    int depth[N] ; 

    int power[L] ; 
    

    void dfs(int node , int parent){
        up[node][0] = parent ; 

        for (int i = 1 ; i<L ; i++){
            up[node][i] = up[up[node][i-1]][i-1] ; 
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
    void solve(){
        cin >> n ;
        for (int i = 0 ; i<n-1 ; i++){
            int x , y ; cin >> x >> y ; 
            --x ; --y ; 
            tree[x].pb(y) ; 
            tree[y].pb(x) ; 
        }
        depth[0] = 0 ; 
        dfs(0,0) ;  
        return ;
    }
     
     
     
    int main(){
        SaveTime
        //freopen("input.txt","r",stdin) ;
        int t = 1 ;
        for (int i = 0 ; i<L ; i++)
            power[i] = (1 << i) ; 
        //cin >> t ;
        for (int i = 1 ; i<=t ; i++){
            solve() ;
        }
    }