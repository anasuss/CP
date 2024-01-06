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
     
     
     
    ll n , k , g ;   
    void solve(){
        ll ans = 0 ; 
        cin >> n >> k >> g ;
        ll tot = k*g ; 
        ll best =  ((g+1)/2)-1 ; 
        ll coverd = tot/best ; 
        if (n*best == tot || n*best>tot){
            cout << tot << endl; 
            return ; 
        }
        if (n*best<tot){
            ans = (n-1)*best ; 
            ll x = best+(tot-n*best) ;  
            ll r = x%g ; 
            if (r>=((g+1)/2)){
                ans=ans-(g-r) ; 
            }else{
                ans = ans+r ; 
            }
            cout << ans << endl ; 
            return ; 
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