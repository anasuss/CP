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

    bool can(int k){
        int cnt = 1 ; 
        int lst = 0 ; 
        for (int i = 0 ; i<n ; i++){
            int mid = (a[i]+a[lst])/2 ;
            if (abs(a[i]-mid)>k || abs(a[lst]-mid)>k){
                ++cnt ; 
                if (cnt>3) return false ; 
                lst = i ; 
            } 
        }
        return true ; 
    }
    void solve(){
        cin >> n ; 
        for (int i = 0 ; i<n ; i++){
            cin >> a[i] ; 
        }
        sort(a,a+n) ; 
        int l = 0 , r = 1e9 ; 
        while(l<=r){
            int mid = l+(r-l)/2 ; 
            if (can(mid))
                r = mid-1 ; 
            else 
                l = mid+1 ;
        }
        cout << l << endl ; 
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