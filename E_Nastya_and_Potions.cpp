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
     
     
     
    ll n,k ;
     
    ll a[N] ;

    ll dp[N] ; 

    vector<ll> v[N] ; 

    ll work(int node){
        if (dp[node] != -1)  return dp[node]; 
        ll total = 0 ; 
        for (ll x : v[node]){
            total+=work(x) ; 
        }
        if (v[node].size() == 0)
            return dp[node] = a[node] ; 
        return dp[node] = min(a[node],total) ; 
    }

    void solve(){
        cin >> n >> k ;
        for (ll i = 1 ; i<=n ; i++){
            cin >> a[i] ;  
            v[i].clear() ; 
            dp[i] = -1 ;
        } 
        vector<ll> cost(n+1,inf) ; 
        for (ll i = 0 ; i<k ; i++){
            ll x ; cin >> x ;
            a[x] = 0 ;  
        }
        for (ll j = 1 ; j<=n ; j++){
            ll m ; cin >> m ;
            for (ll i = 0 ; i<m ; i++){
                ll x ; cin >> x ; v[j].pb(x) ;  
            }
        } 
        for (int i = 1 ; i<=n ; i++){
            if (dp[i] == -1) work(i) ; 
        }   
        for (int i = 1 ; i<=n ; i++){
            cout << dp[i] << " " ; 
        }
        cout << endl ; 
        return ;
    }
     
     
     
    int main(){
        SaveTime
       // freopen("input.txt","r",stdin) ;
        int t = 1 ;
        cin >> t ;
        for (int i = 1 ; i<=t ; i++){
            solve() ;
        }
    }