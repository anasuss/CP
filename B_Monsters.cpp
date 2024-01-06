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
     
     
     
    int n ;
    ll k ; 
    bool comp(pair<ll,int> x , pair<ll,int> y){
        if (x.first != y.first){
            return x.first>y.first ; 
        }
        return x.second<y.second ; 
    }
    void solve(){
        cin >> n >> k ; 
        vector<pair<ll,int>> v ; 
        for (int i = 0 ; i<n ; i++){
            ll x ; cin >> x ; x = x%k ; 
            if (x == 0){
                cout << i+1 << " " ;  
            }else{
                v.pb({x,i+1}) ; 
            } 
        }
        sort(v.begin(),v.end(),comp) ; 
        for (auto p : v){
            cout << p.second << " " ; 
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