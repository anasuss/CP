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
        int q ; 
        cin >> n >> q ; 
        for (int i = 0 ; i<n ; i++) cin >> a[i] ; 
        vector<int> p(n+1,0) ; 
        for (int i = 1 ; i<n-1 ; i++){
            p[i] = p[i-1]+(a[i-1]>=a[i] && a[i]>=a[i+1]) ; 
        }
        for (int i = 0 ; i<q ; i++){
            int l , r ; 
            cin >> l >> r ; 
            --l , --r ; 
            if (l == r){
                cout << 1 << endl ; 
            }else{
                if (l == 0)
                    cout << (r-l+1)-(p[r-1]) << endl ; 
                else 
                    cout << ((r-l+1)-(p[r-1]-p[l])) << endl ; 
            }
        }
        return ;
    }
     
     
     
    int main(){
        SaveTime
       // freopen("input.txt","r",stdin) ;
        int t = 1 ;
       // cin >> t ;
        for (int i = 1 ; i<=t ; i++){
            solve() ;
        }
    }