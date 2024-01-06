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
    
    vector<int> v[N] ; 

    void solve(){
        cin >> n ; 
        for (int i = 1 ; i<=n ; i++) v[i].clear() ; 
        for (int i = 0 ; i<n ; i++){
            int x , y ; cin >> x >> y ;  
            v[x].pb(y) ; 
        }
        for (int i = 1 ; i<=n ; i++){
            sort(v[i].rbegin(),v[i].rend()) ; 
        }
        ll ans = 0 ; 
        for (int i = 1 ; i<=n ; i++){
            if (v[i].size() == 0) continue; 
            for (int j = 1 ; j<=min(i,(int)v[i].size()) ; j++){
                ans+=v[i][j-1] ; 
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