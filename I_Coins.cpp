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
     
    const int N = 3e3;
     
    const int mod = 1e9+7 ;
     
     
     
    int n ;
    double a[N] ; 
    double dp[N] ; 

    void solve(){
        cin >> n ; 
        dp[0] = 1 ; 
        for (int i = 0 ; i<n ; i++){
            cin >> a[i] ; 
            for (int j = i+1 ; j>=0 ; j--){
                dp[j] = (j == 0 ? 0 : (dp[j-1]*a[i]))+(dp[j]*(1-a[i])) ; 
            }
        }
        double ans = 0 ; 
        for (int heads = 0 ; heads<=n ; heads++){
            int tails = n-heads ; 
            if (heads>tails){
                ans+=dp[heads] ; 
            }
        }
        cout << fixed << setprecision(10) << ans << endl ; 
        return ;
    }
     
     
     
    int main(){
        SaveTime
       // freopen("input.txt","r",stdin) ;
        int t = 1 ;
        //cin >> t ;
        for (int i = 1 ; i<=t ; i++){
            solve() ;
        }
    }