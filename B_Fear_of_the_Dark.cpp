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
     
     
     
    int n,q ;
     
    ll a[N] ; 
    int ans[N] ; 
    void solve(){
        cin >> n >> q; 
        for (int i = 1 ; i<=n ; i++){
            cin >> a[i] ; 
        }
        int cur = 1 ; 
        ans[n] = 1 ; 
        for (int i = n-1 ; i>=1 ; i--){
            if (a[i]<=cur){
                ans[i] = 1 ; 
            }else{
                if (cur<q){
                    cur++ ; ans[i] = 1 ; 
                }else{
                    ans[i] = 0 ; 
                }
            }
        }
        for (int i = 1 ; i<=n ; i++){
            cout << ans[i] ; 
        }
        cout << endl ; 
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