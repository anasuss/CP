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
     
     
     
    int n ;
     
    ll a[N] ;
    ll b[N] ;  
    void solve(){
        string s ; 
        cin >> s ; 
        vector<int> v(26,0) ; 
        int ans = 2e5+10 ; 
        for (int i = 0 ; i<s.size() ; i++){
            v[s[i]-'a']++ ; 
        }
        for (int i = 0 ; i<26 ; i++){
            vector<int> pos ; 
            if (v[i] == 0) continue; 
            if (v[i] == s.size()){
                cout <<0<<endl ; 
                return ; 
            }
            int nb = 0 ; 
            for (int j = 0 ; j<s.size() ; j++){
                if (s[j] != char(i+'a')){
                    ++nb ; 
                }else{
                    if (nb)
                        pos.pb(nb) ; 
                    nb =  0 ; 
                }
            }
            if (nb) 
                pos.pb(nb) ; 
            vector<int> temp ; 
            int cnt = 0 ; 
            while(pos.size()){
                ++cnt ; 
                temp.clear() ; 
                for (int x : pos){
                    if (x/2) temp.pb(x/2) ; 
                }
                pos = temp ; 
            }
            ans = min(ans,cnt) ; 
        }
        cout << ans << endl ; 
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