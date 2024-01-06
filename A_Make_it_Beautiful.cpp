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
     
    int a[N] ;
    int b[N] ;  
    void solve(){
        for (int i = 0 ; i<=100 ; i++) b[i] = 0 ; 
        cin >> n ; 
        int mx = 0 ; 
        for (int i = 0 ; i<n ; i++){
            cin >> a[i] ;
            b[a[i]]++ ;
            mx = max(mx,b[a[i]]) ;
        }
        if (mx == n){
            no ; 
            return ; 
        }
        sort(a,a+n) ; 
        reverse(a,a+n) ; 
        yes ; 
        cout << a[0] << " " << a[n-1] ; 
        for (int i = 1 ; i<n-1 ; i++){
            cout << " " << a[i] ; 
        }
        cout << endl ; 
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