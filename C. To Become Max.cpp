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
     
     
     
    int n,m;
     
    int a[N] ;
 
    void solve(){
        cin >> n >> m ;
        int ans = 0 ; 
        for (int i = 0 ; i<n ; i++){
            cin >> a[i] ; 
            ans = max(ans,a[i]) ; 
        }
        for (int i = 0 ; i<n ; i++){
            for (int j = i+1 ; j<n ; j++){
                int f = a[i] ; 
                int l = a[j] ; 
                int mx = a[j]+(j-i) ; 
                if (f>=mx) continue; 
                cout << i << " " << j << " " << mx << endl ; 
                if (ans>=mx) continue; 
                int temp = m ; 
                bool ok = 1 ; 
                int lst = a[j] ; 
                for (int k = j-1 ; k>=i ; k--){
                    if (a[k]<=lst){
                        temp -= (lst-a[k]+1) ; 
                        if (temp<0) break ; 
                        ans = max(ans,lst+1) ; 
                        lst++ ; 
                    }
                }
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