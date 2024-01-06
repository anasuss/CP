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
     
    const int N = 2e5+100 ;
     
    const int mod = 1e9+7 ;
     
     
     
    int n ;
    
    vector<int> tree[N] ; 

    ll leaf[N] ; 

    void dfs(int node , int parent){
        bool isleaf = true ; 
        for (int child : tree[node]){
            if (child == parent) continue;
            isleaf = false ; 
            dfs(child,node) ; 
        }
        leaf[node] = (isleaf == true ? 1LL : 0LL) ; 
    }
    void dfs2(int node , int parent){ 
        for (int child : tree[node]){
            if (child == parent) continue;
            dfs2(child,node) ; 
            leaf[node]+=leaf[child] ; 
        }
    }
    int m ; 
    void solve(){
        cin >> n ;
        for (int i = 0 ; i<=n ; i++){
            tree[i].clear() ; 
            leaf[i] = 0 ; 
        }
        for (int i = 0 ; i<n-1 ; i++){
            int x , y ; cin >> x >> y ; 
            --x ; --y ; 
            tree[x].pb(y) ; 
            tree[y].pb(x) ; 
        } 
        cin >> m ;
        dfs(0,-1) ;
        dfs2(0,-1) ; 
        while(m--){
            int x , y ; cin >> x >> y ; --x; --y ; 
            ll ans = leaf[x]*leaf[y] ; 
            cout << ans << endl ; 
        }
        return ;
    }
     
     
     
    int main(){
        SaveTime
        //freopen("input.txt","r",stdin) ;
        int t = 1 ;
        cin >> t ;
        for (int i = 1 ; i<=t ; i++){
            solve() ;
        }
    }