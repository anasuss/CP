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
    string s ; 
    ll a[N] ;
    ll b[N] ;  
    void solve(){
        cin >> s ;
        n = s.size() ;  
        ll ans = 0 ; 
        s+=s ; 
        ll cnt = 0 , mx = 0 ; 
        for (int i = 0 ; i<2*n ; i++){
            if(s[i] == '1'){
                ++cnt ; 
            }else{
                mx = max(mx,cnt) ; 
                cnt = 0 ; 
            }
        }
        ans = n ; 
        mx = max(cnt,mx) ; 
        if (mx == 2*n) cout << ans*ans << endl ; 
        else if (mx == 0 || mx == 1) cout << mx << endl ; 
        else{
            ans = 0 ; 
            ll j = mx , i = 1;
            while(j != 1){
                ans = max(ans,i*j) ; 
                --j ; 
                ++i ; 
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