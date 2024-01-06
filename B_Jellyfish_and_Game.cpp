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
     
    const int N = 100 ;
     
    const int mod = 1e9+7 ;
     
     
     
    int n , m ; 
    int k ; 
    multiset<ll> s1 , s2 ;   
    ll a[N] , b[N] ; 
    ll work(int kk){
        s1.clear() ; s2.clear();
        ll ans = 0 ; 
        for (int i = 0 ; i<n ; i++){
           s1.insert(a[i]) ; 
        } 
        for (int i = 0 ; i<m ; i++){
            s2.insert(b[i]) ;  
        }
        for (int i = 1 ; i<=kk ; i++){
            if (i%2 == 1){
                int mn = *s1.begin() ; 
                int mx = *(--s2.end()) ; 
                if (mn>=mx) continue; 
                s1.erase(s1.begin()) ;
                s2.erase((--s2.end()));
                s1.insert(mx) ; 
                s2.insert(mn) ;  
            }else{
                int mn = *s2.begin() ; 
                int mx = *(--s1.end()) ; 
                if (mn>=mx) continue; 
                s2.erase(s2.begin()) ;
                s1.erase((--s1.end()));
                s2.insert(mx) ; 
                s1.insert(mn) ;  
            }
        }
        for (ll i : s1) ans+=i ; 
        return ans ; 
    }
    void solve(){
        cin >> n >> m >> k;
        for (int i = 0 ; i<n ; i++){
            cin >> a[i] ; 
        }
        for (int i = 0 ; i<m ; i++){
            cin >> b[i] ; 
        }
        k%=2 ; 
        if (k) cout << work(1) << endl ; 
        else cout << work(2) << endl ; 
        return ;
    }


    // 1 2 3

    // 1 2 3

     
    int main(){
        SaveTime
       // freopen("input.txt","r",stdin) ;
        int t = 1 ;
        cin >> t ;
        for (int i = 1 ; i<=t ; i++){
            solve() ;
        }
    }