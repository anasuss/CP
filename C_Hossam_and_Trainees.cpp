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
     
    const int N = 2e5+100 ;
     
    const int mod = 1e9+7 ;
     
    const int MAXN = 31622+100 ; 
    int n ;
     
    bool spf[MAXN] ;
    vector<int> primes ;  

    void sieve(){
        for (int i = 2 ; i< MAXN; i++) {
            if (!spf[i]) {
                primes.pb(i) ; 
                for (int j = i*i ; j < MAXN; j += i)    
                        spf[j] = true;
            }
        }
    }
    map<int,int> mp ; 
    void solve(){
        mp.clear() ; 
        cin >> n ;
        int ok = 0 ; 
        for (int i = 0 ; i<n ; i++){
            int x ; cin >> x ; 
            int j = 0 ; 
            while(j<primes.size() && primes[j]*primes[j]<=x && !ok){
                if (x%primes[j] == 0){
                    mp[primes[j]]++ ;
                    if (mp[primes[j]]>1){
                        ok = 1 ; 
                    }
                    while(x%primes[j] == 0){
                    x/=primes[j] ; 
                } 
            }
            ++j ; 
            }
            if (x != 1 && !ok){
                mp[x]++ ; 
                if (mp[x]>1) ok = 1 ; 
            }
        }
        (ok == 1 ? yes : no) ; 
        return ;
    }
     
     
     
    int main(){
        SaveTime
        sieve();
       // freopen("input.txt","r",stdin) ;
        int t = 1 ;
        cin >> t ;
        for (int i = 1 ; i<=t ; i++){
            solve() ;
        }
    }