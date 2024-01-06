    #include<bits/stdc++.h>
    typedef long long  ll;
    typedef long double ld ;
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
     
    const double eps = 1e-6 ; 
     
    int n ; 
    ll a[N] ;
    ll b[N] ;  
    pair<ld,ld> intersect(pair<ld,ld> Frange , pair<ld,ld> range){
        if (Frange.second<range.first || Frange.first>range.second){
            return {-1,-1} ; 
        }
        return {max(Frange.first,range.first),min(range.second,Frange.second)};
    }
    void solve(){
        cin >> n ; 
        for (int i = 0 ; i<n ; i++){
            cin >> a[i] ;
        }
        for (int i = 0 ; i<n ; i++){
            cin >> b[i] ; 
        }
        ll l = 0 , r = 1e10 ;
        double ans = 0.0 ;  
        int iteration = 40 ; 
        while(l<=r){
            ll mid = l+(r-l)/2 ; 
            bool ok = 1 ; 
            pair<ld,ld> Frange = {0,1e9} ; 
            for (int i = 0 ; i<n ; i++){
                if (mid<b[i]){
                    ok = 0 ; break ; 
                }
                ll dif = mid-b[i] ; 
                pair<ld,ld> range = {a[i]-dif,a[i]+dif} ; 
                Frange = intersect(Frange,range) ; 
                if (Frange.first == -1){
                    ok = 0 ; 
                    break ; 
                }
            }
            if (ok){
                ans = (Frange.first+Frange.second)/2 ; 
                r = mid-1 ; 
            }else{
                l = mid+1 ; 
            }
        }
        cout << setprecision(10) << fixed << ans << endl ; 
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