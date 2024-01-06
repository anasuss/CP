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
        int ans = 1e9 ; 
        map<int,int> mp ; 
        for (int i = 0 ; i<n ; i++){
            cin >> a[i] ;
            if (a[i]<0){
                ans = a[i] ; 
            } 
           mp[a[i]]++ ; 
        }
        if (ans<0){
            cout << ans << endl ; 
            return ; 
        }
        sort(a,a+n) ;
        reverse(a,a+n) ; 
        for (int i = 0 ; i<n ; i++){
            for (int j = i+1 ; j<n ; j++){
                int x = abs(a[i]-a[j]) ; 
                int y = mp[x] ; 
                if (y == 0) continue; 
                if (x == a[i]) --y ; 
                if (x == a[j]) --y ; 
                if (y>0){
                    cout << a[i] << endl ; 
                    return ; 
                }                 
            }
        }
        cout << 0 << endl ; 
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