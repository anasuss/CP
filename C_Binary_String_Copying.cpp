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
     
     
     
    int n,m;
    string s ; 
    void solve(){
        cin >> n >> m; 
        cin >> s ; 
        set<pii> sp ; 
        set<int> pos[2] ;
        for (int i = 0 ; i<s.size() ; i++){
            pos[s[i]-'0'].insert(i) ; 
        }  
        while(m--){
            int l , r ; cin >> l >> r ; --l ; --r ; 
            auto it = pos[1].lower_bound(l) ; 
            if (it != pos[1].end()){
                int x = *it ; 
                it = pos[0].upper_bound(r) ; 
                if (it != pos[0].begin()){
                    --it ; 
                    int y = *it ; 
                    if (x<y){
                        sp.insert({x,y}) ; 
                    }else{
                        sp.insert({n,n}) ; 
                    }
                }else{
                    sp.insert({n,n}) ; 
                }
            }else{
                sp.insert({n,n}) ; 
            }
        }
        cout << sp.size() << endl ; 
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