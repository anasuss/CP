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
    vector<pii> v; 
    vector<int> query ; 
    int n , m ; 
    bool can(int x){
        vector<int> pref(n+1,0) ; 
        for (int i = 0 ; i<=x ; i++){
            pref[query[i]] = 1 ; 
        }
        for (int i = 1 ; i<=n ; i++){
            pref[i]+=pref[i-1] ; 
        }
        for (int i = 0 ; i<m ; i++){
            int l = v[i].first ; 
            int r = v[i].second ; 
            int nb1 = pref[r]-pref[l-1] ; 
            int nb0 = (r-l+1)-nb1 ; 
            if (nb1>nb0) return true ; 
        }
        return false ; 
    }
    void solve(){
        v.clear() ; query.clear() ; 
        cin >> n >> m ; 
        for (int i = 0 ; i<m ; i++){
            int x , y ; cin >> x >> y ; v.pb({x,y}) ; 
        }
        int q ; cin >> q ; 
        for (int i = 0 ; i<q ; i++){
            int x ; cin >> x ; query.pb(x) ; 
        }
        int l = 0 , r = q-1 ;
        int ans = -1 ; 
        while(l<=r){
            int mid = (l+r)/2 ; 
            if (can(mid)){
                ans = mid+1 ; 
                r = mid-1 ; 
            }else
                l = mid+1 ; 
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