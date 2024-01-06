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
        const int mod = 1e9+7 ;
        const int N = 2e5+100 ;
        ll gcd(ll a , ll b) {return b ? gcd(b , a % b) : a ;}
        ll lcm(ll a , ll b) {return (a * b) / gcd(a , b);}
        ll inv(ll i) {if (i == 1) return 1; return (mod - ((mod / i) * inv(mod % i)) % mod) % mod;}  
        ll C(int n , int k){
            assert(n>=k) ; 
            //return fact[n]*inv(fact[k]*fact[n-k]%mod)%mod ; 
            return 0 ; 
        }
        
        
        
        int n,k ;
        
        ll a[N] ;
        ll b[N] ;  
        void solve(){
            cin >> n ; 
            int imp = 0 ; 
            ll sum = 0 ; 
            for (int i = 0 ; i<n ; i++){
                int x ; cin >> x ;
                sum+=x ; 
                imp+=x%2 ; 
                if (imp == 0 || i == 0){
                    cout << sum << " " ; 
                    continue;
                }
                if (imp == 1){
                    cout << sum-1 << " " ; 
                }else if (imp == 2){
                    cout << sum << " " ; 
                }else{
                    int y = imp-2 ; 
                    cout << sum-y/3-y%3 << " " ; 
                }
            }
            cout << endl ; 
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