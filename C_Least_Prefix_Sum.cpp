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
     
     
     
    ll n,m ;
     
    ll a[N] ;
    ll b[N] ;  
    void solve(){
        cin >> n >> m; 
        priority_queue<ll> pq1 ; 
        priority_queue<ll> pq2 ;
        ll prf = 0 ; 
        for (int i = 0 ; i<n ; i++){
            cin >> a[i] ; 
        }
        int ans = 0 ; 
        ll s = 0 ; 
        for (int i = m-1 ; i>0 ; i--){
            s+=a[i] ; 
            pq1.push(a[i]) ; 
            if (s>0){
                ++ans ; 
                ll x = pq1.top() ; 
                pq1.pop() ;
                s-=(2*x) ; 
            }
        }
        s = 0 ; 
        for (int i = m ; i<n ; i++){
            s+=a[i] ; 
            pq2.push(-a[i]) ; 
            if (s<0){
                ++ans ; 
                ll x = pq2.top() ;
                pq2.pop() ; 
                s+=(2*x) ; 
            }
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