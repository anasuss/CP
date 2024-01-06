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
        for (int i = 0 ; i<n; i++){
            cin >> a[i] ; 
        }
        for (int i = 0 ; i<n ; i++){
            cin >> b[i] ; 
        }
        sort(a,a+n) ; 
        sort(b,b+n) ; 
        for(int i = 0 ; i<n ; i++){
            if (a[i]<=b[i]){
                cout << 0 << endl ; 
                return ; 
            }
        }
        ll ans = 1 ; 
        for (int i = 0 ; i<n ; i++){
            int l = i , r = n-1 ; 
            while(l<=r){
                int mid = (l+r)/2 ; 
                if (b[mid]<a[i])
                    l = mid+1 ; 
                else 
                    r = mid-1 ; 
            }
            ans*=(ll)(l-i) ;
            ans%=mod ;  
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