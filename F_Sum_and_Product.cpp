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
     
     
     
    int n ;
    map<ll,ll> mp ; 
    void solve(){
        cin >> n ; 
        mp.clear() ; 
        for (int i = 0 ; i<n ; i++){
            ll x ; cin >> x ; mp[x]++ ; 
        } 
        int q ; cin >> q ; 
        while(q--){
            ll b , c ; cin >> b >> c ; 
            ll delta = b*b-4*c ; 
            if (delta<0){
                cout << 0 << " " ; 
                continue;
            }
            ll r = sqrt(delta) ;
            if (r*r != delta){
                cout << 0 << " " ; continue; 
            } 
            ll ans = 0 ; 
             if ((b-r)%2 == 0){
                ll x = (b-r)/2; ll y = b-x ; 
                if (x == y) ans+=(mp[x]*(mp[x]-1))/2 ;
                else ans+=mp[x]*mp[y] ;   
            }
            else if ((b+r)%2 == 0){
                ll x = (b+r)/2 ; ll y = b-x ;  
                if (x == y) ans+=(mp[x]*(mp[x]-1))/2 ;
                else ans+=mp[x]*mp[y] ;   
            }
            cout << ans << " n" ; 
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