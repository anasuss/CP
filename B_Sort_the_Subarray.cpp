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
        for (int i = 0 ; i<n ; i++){
            cin >> a[i] ; 
        }
        for (int i = 0 ; i<n ; i++){
            cin >> b[i] ; 
        }
        int l = 0 ; 
        int r = 0 ; 
        int len = -1 ; 
        for (int i = 0 ; i<n-1 ; i++){
            if (b[i]>b[i+1]) continue;
            int j = i ; 
            bool ok = 0 ; 
            while(j<n-1 && b[j]<=b[j+1]){
                ok |= (b[j]!=a[j]);
                j++ ; 
            }
            if (j-i+1>len && ok){
                l = i ; 
                r = j ; 
            }
            i = j ; 
        }
        cout << l+1 << " " << r+1 << endl ; 
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