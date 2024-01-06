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
     
    const ll INF = 1000*1000*1000; // 1 e 9
    const ll inf = (ll)1e18;
     
    const ll N = 2e5+100 ;
     
    const ll mod = 1e9+7 ;
     
    const ll MAXN = 1e7+200 ; 

    map<ll,ll> mp ; 
    vector<ll> getFactorization(ll x){
        vector<ll> v ; 
        for (ll i = 1 ; i<=sqrt(x) ; i++){
            if (x%i) continue; 
            v.pb(i) ; 
            if ((x/i) != i) v.pb(x/i) ; 
        }
        return v ;
    }
    ll n ;
     
    ll a[N] ;

    void solve(){
        mp.clear() ; 
        cin >> n ; 
        for (ll i = 0 ; i<n ; i++){
            ll x ; cin >> x ; 
            mp[x]++ ; 
        }
        ll ans = 0 ; 
        for (ll i = 1 ; i<=n ; i++){
            ll sum = 0 ; 
            vector<ll> v = getFactorization(i) ; 
            for (ll x : v) sum+=mp[x] ; 
            ans = max(sum,ans) ; 
        }
        cout << ans << endl; 
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