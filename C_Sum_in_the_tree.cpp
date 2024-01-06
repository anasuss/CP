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
     
    const int N = 1e5+5 ;
     
    const int mod = 1e9+7 ;
     
     
     
    int n ;
    vector<int> tree[N] ; 
    ll a[N] ;
    ll ans = 0 ; 
    bool ok ;  
    void dfs1(int node , int parent){
        int check = (a[node] == -1) ; 
        if (check) a[node] = inf ;
        bool isleaf = true ; 
        for (int child : tree[node]){
            if (child == parent) continue; 
            if(check) a[node] = min(a[node],a[child]) ; 
            isleaf = false ; 
            dfs1(child,node) ; 
        }
        if (isleaf && check) a[node] = a[parent] ; 
    }

    void dfs2(int node , int parent){
        if (!ok)
            return ; 

        for (int child : tree[node]){
            if (child == parent) continue;
            if (a[child]<a[node]){
                ok = false ; 
                return ; 
            }
            ans+=(a[child]-a[node]) ; 
            dfs2(child,node) ; 
        }
    }
    void solve(){
        cin >> n ; 
        for (int i = 2 ; i<=n ; i++){
            int x ; cin >> x ; 
            tree[i].pb(x) ; 
            tree[x].pb(i) ; 
        }
        for (int i = 1 ; i<=n ; i++){
            cin >> a[i] ; 
        }
        ok = 1 ; 
        ans = 0 ; 
        dfs1(1,-1); 
        dfs2(1,-1) ;
        if (!ok){
            cout << -1 << endl ; 
            return ; 
        }
        cout << ans+a[1] << endl ; 
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