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
     
     
     
    ll n,m,h ; 
    bool comp(pair<int,pll> x , pair<int,pll> y){
        if (x.second.first != y.second.first)
            return x.second.first>y.second.first ; 
        if (x.second.second != y.second.second)
            return x.second.second<y.second.second ; 
        return x.first<y.first ; 
    }
    void solve(){
        cin >> n >> m >> h; 
        vector<pair<int,pll>> ans ; 
        for (int i = 0 ; i<n ; i++){
           vector<ll> v(m) ; 
           for (int j = 0 ; j<m ; j++){
            cin >> v[j] ; 
           }
           sort(v.begin(),v.end()) ; 
           vector<ll> penl ; 
           ll s = 0 ; 
           ll cnt = 0 ; 
           for (int j = 0 ; j<v.size() ; j++){
                if (s+v[j]<=h){
                    s+=v[j] ;
                    penl.pb(s) ; 
                    ++cnt;  
                }else 
                    break; 
           }
           s = 0 ; 
           for (ll j : penl) s+=j ; 
          // if (i == 0) cout << s << endl ; 
           ans.pb({i,{cnt,s}}) ; 
        }   
        sort(ans.begin(),ans.end(),comp) ; 
        for (int i = 0 ; i<ans.size() ; i++){
            if (ans[i].first == 0){
               cout << i+1 << endl ; 
                return ; 
            }
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