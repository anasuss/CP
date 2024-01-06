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
        int s ; 
        cin >> n >> s ; 
        int ans = -1;
        int mx = 0 ;  
        for (int i = 0 ; i<n ; i++){
            cin >> a[i] ; 
        }
        for (int i = 0 ; i<n ; i++)
            cin >> b[i] ; 
        for (int i = 0 ; i<n ; i++){
            if (i+a[i]<=s){
                if (b[i]>mx){
                    mx = b[i] ; 
                    ans = i+1 ; 
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