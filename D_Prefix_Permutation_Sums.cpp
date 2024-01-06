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
     
     
     
    ll n ;
     
    ll a[N] ;

    bool visited[N] ;  

    void solve(){
        cin >> n ;
        for (ll i = 0 ; i<=n ; i++){
            visited[i] = false ; 
        } 
        for (ll i = 0 ; i<n-1 ; i++){
            cin >> a[i] ;
        }
        bool ok = false ;
        vector<ll> d ; 
        for (ll i = 1 ; i<n-1 ; i++){
            ll dif = a[i]-a[i-1] ; 
            if (dif>n){
                d.pb(dif) ; 
                ok = true ; 
            }
            if (dif<=n){
                if (!visited[dif]){
                    visited[dif] = true ;
                }else{
                    d.pb(dif) ; 
                } 
            }
        }
        if (a[0]>n){
            d.pb(a[0]) ; 
        }
        if (a[0]<=n){
            if (!visited[a[0]])
                visited[a[0]] = true ; 
            else
                d.pb(a[0]) ; 
        }
        vector<ll> v ; 
        for (ll i = 1 ; i<=n ; i++){
            if (!visited[i]){
                v.pb(i) ; 
            }
        }
        if (v.size() == 1){
            if (d.size() == 0)
                yes ;
            else 
                no ;  
            return ; 
        }
        if (v.size() == 2 && d.size() == 1){
            if (v[0]+v[1] == d[0]){
                yes ; 
            }else 
                no ; 
            return ; 
        }
        no ; 
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