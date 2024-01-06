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
             
            const int N = 4e5+100 ;
             
            const int mod = 1e9+7 ;
             
             
             
            string s , l , r  ;
            int n ; 
            set<int> indxes[15] ; 
            set<ll> dp[15] ;  
            bool ok ; 
            ll power[15] ; 
            ll to_ll(const string &ss){
                ll sum = 0 ; 
                for (int i = 0 ; i<ss.size() ; i++){
                    ll x = ss[i]-'0' ; 
                    sum+=x*power[n-i-1] ; 
                }
                return sum ; 
            }
            void work(int idx, string &ans){
                if (ok) return ; 
                if (dp[idx].count(to_ll(ans))) return ; 
                if ((int)ans.size() == n){
                    int cnt = 0 ;
                    if (indxes[ans[0]-'0'].size() == 0){
                        ok = true ; 
                        return ; 
                    }
                    int x = *indxes[ans[0]-'0'].begin() ; 
                    for (int i = 1 ; i<ans.size() ; i++){
                        int idx = ans[i]-'0' ;
                        auto it = indxes[idx].lower_bound(x+1) ; 
                        if (it == indxes[idx].end()){
                            ok = true ; 
                            return ; 
                        }
                        x = *it ; 
                    }
                    return ; 
                }
                dp[idx].insert(to_ll(ans)) ; 
                for (int i = idx ; i<l.size() && !ok; i++){
                    for (char j = l[i] ; j<=r[i] && !ok ; j++){
                        ans.pb(j) ; 
                        work(i+1,ans) ; 
                        ans.pop_back() ; 
                    }
                }
            }
            void solve(){
                cin >> s >> n >> l >> r ; 
                for (int i = 0 ; i<15 ; i++){
                    indxes[i].clear() ; 
                    dp[i].clear() ; 
                }
                string ans = "" ; 
                ok = false ; 
                for (int i = 0 ; i<s.size() ; i++){
                    int x  = s[i]-'0'; 
                    indxes[x].insert(i) ; 
                }
                work(0,ans) ; 
                if (ok){
                    yes ; 
                }else{
                    no ; 
                }
                return ;
            }
             
             
             
            int main(){
                SaveTime
                ll x = 1 ; 
               // freopen("input.txt","r",stdin) ;
               for (int i = 0 ; i<11 ; i++){
                power[i] = x ; 
                x*=10 ; 
               }
                int t = 1 ;
                cin >> t ;
                for (int i = 1 ; i<=t ; i++){
                    solve() ;
                }
            }
     