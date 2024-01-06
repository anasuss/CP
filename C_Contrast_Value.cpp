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
     
    const int N = 3e5+100 ;
     
    const int mod = 1e9+7 ;
     
     
     
    int n ;
     
    ll a[N] ;
    ll b[N] ;  
    void solve(){
        cin >> n ; 
        for (int i = 0 ; i<n ; i++) cin >> a[i] ; 
        int contrast = 0;
        for (int i = 1 ; i<n ; i++){
            contrast+=abs(a[i]-a[i-1]) ; 
        }
        if (contrast == 0){
            cout << 1 << endl ; 
        }else if (abs(a[0]-a[n-1]) == contrast){
            cout << 2 << endl ; 
        }else{
            int last = a[0] , ans = 1 , up = 0 ; 
            for (int i = 1 ; i<n ; i++){
                if (a[i] == last)
                    continue; 
                if (a[i]<last && up!=-1){
                    ++ans ; up = -1 ; 
                }else if (a[i]>last && up != 1){
                    up = 1 ; 
                    ans++ ; 
                }
                last = a[i] ; 
            }
            cout << ans << endl ; 
        }
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