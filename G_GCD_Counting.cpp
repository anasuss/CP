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
     
    const ll INF = 1000*1000*1000; // 1 e 9
    const ll inf = (ll)1e18;
     
    const ll N = 2e5+100 ;
     
    const ll mod = 1e9+7 ;
     
    const ll MAXN = N ; 
     
    ll n ;
     
    ll a[N] ;
    ll spf[MAXN] ;
    vector<ll> primes ; 
    vector<ll> tree[N] ; 
    ll vis[N] ; 
    ll mx , farthest ; 
    void sieve(){
        for (ll i = 1; i < MAXN; i++)
            spf[i] = i ; 
        for (ll i = 2; i < MAXN; i++) {
            if (spf[i] == i) {
                primes.pb(i) ; 
                for (ll j = i*2 ; j < MAXN; j += i)    
                        spf[j] = i;
            }
        }
    }
    void dfs(ll node , ll parent , ll p , ll depth = 1){
        if (depth>mx){
            farthest = node ; 
            mx = depth ; 
        }
        vis[node] = p ; 
        for (ll child : tree[node]){
            if (child == parent) continue; 
            if (a[child]%p == 0){
                dfs(child,node,p,depth+1) ; 
            }
        }
    }
    vector<ll> A[MAXN] ; 
    void solve(){
        cin >> n ; 
        sieve() ;  
        for (ll i = 0 ; i<n ; i++){
            cin >> a[i] ; 
            A[a[i]].pb(i) ; 
        }
        for (ll i = 0 ; i<n-1 ; i++){
            int u , v ; cin >> u >> v ; --u ; --v ; 
            tree[u].pb(v) ; 
            tree[v].pb(u) ; 
        }
        ll ans = 0 ;
        for (ll p : primes){
            vector<ll> v ; 
            for (ll i = p ; i<MAXN ; i+=p){
                for (ll j : A[i]){
                    v.pb(j) ; 
                }
            }
            for (ll x : v){
                if (vis[x] != p){
                    mx = 0 ; farthest = 0 ; 
                    dfs(x,-1,p) ; 
                    mx = 0 ; 
                    dfs(farthest,-1,p) ;
                    ans = max(ans,mx) ;  
                }
            }
        }
        cout << ans << endl ; 
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