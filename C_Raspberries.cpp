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
    void solve(){
        cin >> n >> k;
        ll f = 1 ; 
        bool ok = false ;
        int cnt = 0 ; 
        for (ll i = 0 ; i<n; i++){
            cin >> a[i] ;
            if (a[i]%k == 0) ok = true ;
            if (a[i]%2 == 0 && k == 4) ++cnt ;  
        } 
        if (ok || cnt >= 2){
            cout << 0 << endl ; return ; 
        }
        if (k == 4){
            vector<ll> v2 ;
            vector<ll> v4 ; 
            ok = false ; 
            for (ll i = 0 ; i<n ; i++){
                if (a[i]%2 == 0) ok = true ; 
                ll x = a[i]/2+1;
                ll y = x*2 ; 
                v2.pb(y-a[i]) ; 
                x = a[i]/k+1 ;
                y = k*x ; 
                v4.pb(y-a[i]) ; 
            }
            sort(all(v2)) ; sort(all(v4)) ; 
            if (ok){
                cout << min(v2[0],v4[0]) << endl ; 
            }else{
                cout << min(v2[0]+v2[1],v4[0]) << endl ; 
            }
            return ; 
        }
        ll ans = inf ; 
        for (ll i = 0 ; i<n ; i++){
            ll x = a[i]/k+1;
            ll y = x*k ; 
            if (y<k) y = k ; 
            ans = min(ans,y-a[i]) ;  
        }
        cout << ans << endl ; 
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