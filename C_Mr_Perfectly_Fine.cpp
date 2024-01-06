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
     
    ll a[N] ;
    ll b[N] ;  
    void solve(){
        cin >> n ; 
        int ans = -1 ; 
        ll x = inf  , y = inf , z = inf ; 
        for (int i = 0 ; i<n ; i++){
            ll k ; 
            string s ; 
            cin >> k >> s ; 
            if (s == "01"){
                x = min(x,k) ; 
            }else if (s == "10"){
                y = min(y,k) ; 
            }else if (s == "11"){
                z = min(z,k) ; 
            }
        }
        if ((x == inf || y == inf)&& z == inf){
            cout << -1 << endl ;
            return ; 
        }
        cout << min(z,x+y) << endl ; 
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