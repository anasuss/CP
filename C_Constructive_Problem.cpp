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
        set<int> s ; 
        for (int i = 0 ; i<n ; i++){
            cin >> a[i] ; 
            s.insert(a[i]) ; 
        }
        int mx = 0; 
        for (int i : s){
            if (i == mx) ++mx ; 
            else 
                break ; 
        }
        if (mx>=n){
            no ; 
            return ; 
        }
        if (mx == 0){
            yes; 
            return ; 
        }
        int l = -1 , r = -2 ; 
        for (int i = 0 ; i<n ; i++){
            if (a[i] == mx+1){
                l = i ; 
                break ; 
            }
        }
        if (l == -1){
            yes ; 
            return ;
        }
        for (int i = n-1 ; i>=0 ; i--){
            if (a[i] == mx+1){
                r = i ; 
                break ; 
            }
        }
        for (int i = l ; i<=r ; i++){
            a[i] = mx ; 
        }
        sort(a,a+n) ; 
        int mxx = 0 ; 
        for (int i = 0 ; i<n ; i++){
            if (a[i] == mxx) ++mxx ; 
        }
        if (mx+1 == mxx) yes; 
        else no ; 
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