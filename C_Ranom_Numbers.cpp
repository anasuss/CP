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
     
     
     
    string s , s1; 

    ll n ; 

    ll mul [] = {1,10,100,1000,10000} ; 

    ll calc(){
        ll ans = 0 ; 
        ll mx = 0 ; 
        for (int i = n-1 ; i>=0 ; i--){
            ll x = mul[s[i]-'A'] ; 
            if (x>=mx){
                ans+=x ;
            } 
            else{
                ans-=x ; 
            }
            mx = max(mx,x) ; 
        }
        return ans ; 
    }

    void solve(){
        cin >> s ;
        n = s.size(); 
        ll ans = calc() ; 
        int a , b , c , d , e ; 
        a = b = c = d = e = 0 ; 
        for (int i = n-1 ; i>=0 ; i--){
            char cc = s[i] ; 
            if (s[i] == 'B' && !b){
                ++b ; 
                    s[i] = 'A' ; 
                    ans = max(ans,calc()) ; 
            }else if (s[i] == 'C' && !c){
                ++c ; 
                    s[i] = 'A' ; ans = max(ans,calc()) ; 
                    s[i] = 'B' ; ans = max(ans,calc()) ; 
            }else if (s[i] == 'D' && !d){
                ++d ; 
                    s[i] = 'A' ; ans = max(ans,calc()) ; 
                    s[i] = 'B' ; ans = max(ans,calc()) ; 
                    s[i] = 'C' ; ans = max(ans,calc()) ;   
            }else if (s[i] == 'E' && !e){
                ++e ; 
                    s[i] = 'A' ; ans = max(ans,calc()) ; 
                    s[i] = 'B' ; ans = max(ans,calc()) ; 
                    s[i] = 'C' ; ans = max(ans,calc()) ;  
                    s[i] = 'D' ; ans = max(ans,calc()) ; 
            }
            s[i] = cc ; 
            if (b && c && d && e) break ; 
        }
        a = b = c = d = e = 0 ; 
        for (int i = 0 ; i<n ; i++){
            char cc = s[i] ; 
            if (s[i] == 'A' && !a){
                ++a ; 
                s[i] = 'E'; 
                ans = max(ans,calc()) ; 
            }else if (s[i] == 'B' && !b){
                ++b ; 
                s[i] = 'E'; 
                ans = max(ans,calc()) ; 
            }else if (s[i] == 'C' && !c){
                ++c;
                s[i] = 'E' ; 
                ans = max(ans,calc()) ; 
            }else if (s[i] == 'D' && !d){
                ++d; 
                s[i] = 'E' ; 
                ans = max(ans,calc()) ; 
            }
            s[i] = cc ; 
            if (b && c && d && a) break ; 
        }
        cout << ans << endl ; 
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