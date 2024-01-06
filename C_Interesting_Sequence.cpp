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
     
     
     
    void solve(){
        ll n , x ; cin >> n >> x ; 
        if (x>n){
            cout << -1 << endl ; 
            return ; 
        } 
        if (x == n){
            cout << x << endl ; 
            return ; 
        }
        ll ans = 0 ;
        vector<ll> v ;  
        for (ll i = 60 ; i>=0 ; i--){
            ll bitN = (1LL<<i)&n ; 
            ll bitX = (1LL<<i)&x ; 
            if(bitN == bitX){
                if (bitN){
                    v.push_back((1LL<<i)) ; 
                }
            }else{
                v.push_back((1LL<<(i+1))) ; 
                break ; 
            }
        }
        for (ll i : v) ans+=i ;
        if (ans<n || (ans&n) != x){
            cout << -1 << endl ; 
            return ; 
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