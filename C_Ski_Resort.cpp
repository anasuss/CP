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
     
     
     
    int n ,k,q;
     
    ll a[N] ;
    ll b[N] ;  
    void solve(){
        cin >> n >> k >> q; 
        for (int i = 0 ; i<n ; i++) cin >> a[i] ; 
        ll ans = 0 ; 
        ll cnt = 0 ; 
        for (int i = 0 ; i<n ; i++){
            if (a[i]>q) continue; 
            int j = i ;
            int nb = 0 ;  
            while(a[j]<=q && j<n){
                ++nb ; 
                ++j;
                if (nb>=k){
                    ++cnt ; 
                    ans+=cnt ; 
                }
            }
            cnt = 0 ; 
            i = j; 
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