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
     
    const int MAXN = 1e7 ; 
     
    int n ;
     
    ll a[N] ;
    ll b[N] ;  
    ll spf[MAXN] ;
    unordered_map<ll,ll> mp ; 
    void sieve(){
        spf[1] = 1;
        for (int i = 2; i < MAXN; i++)
            spf[i] = i;
    
        for (int i = 4; i < MAXN; i += 2)
            spf[i] = 2;
    
        for (int i = 3; i * i < MAXN; i++) {
            if (spf[i] == i) {
                for (int j = i * i; j < MAXN; j += i)    
                    if (spf[j] == j)
                        spf[j] = i;
            }
        }
    }
    vector<ll> getFactorization(ll x)
    {
        vector<ll> ret;
        while (x != 1) {
            ret.pb(spf[x]) ; 
            x = x / spf[x];
        }
        return ret;
    }

    void solve(){
        int m ; 
        cin >> n >> m; 
        vector<ll> v = getFactorization((ll)n) ; 
        for (ll i : v){
            if (i<=m){
                no;
                return ; 
            }
        }
        yes ; 
        return ;
    }
     
     
     
    int main(){
        SaveTime
       // freopen("input.txt","r",stdin) ;
        int t = 1 ;
        cin >> t ;
        sieve() ; 
        for (int i = 1 ; i<=t ; i++){
            solve() ;
        }
    }