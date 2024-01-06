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
     
    const int N = 55;
     
    const int mod = 1e9+7 ;
     
     
     
    int n ;
    set<int> a[N] ; 
    set<int> S ; 
    void solve(){
        cin >> n ; 
        S.clear() ; 
        for (int i = 0 ; i<n ; i++) a[i].clear() ; 
        for (int i = 0 ; i<n ; i++){
            int k ; cin >> k ; 
            for (int j = 0 ; j<k ; j++){
                int x ; cin >> x ; S.insert(x) ; 
                a[i].insert(x) ; 
            }
        }
        int ans = 0 ; 
        for (int e : S){
            set<int> s; 
            for (int i = 0 ; i<n ; i++){
                if (a[i].count(e)) continue;
                for (int x : a[i]) s.insert(x) ; 
            }
            ans = max(ans,(int)s.size()) ; 
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