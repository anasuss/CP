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
    int occ[26];
    
    void solve(){
        string s ; 
        cin >> n >> s ;
        if (n%2){
            cout << -1 << endl ; 
            return ; 
        }
        for (int i = 0 ; i<26 ; i++){
            occ[i] = 0 ; 
        }
        int mx = 0 ; 
        for (int i = 0 ; i<n ; i++){
            occ[s[i]-'a']++ ; 
            mx = max(occ[s[i]-'a'],mx) ; 
        }
        if (mx>n/2){
            cout << -1 << endl ; 
            return ; 
        }
        memset(occ,0,sizeof(occ)) ; 
        int sum = 0 ; 
        for (int i = 0 ; i<n/2 ; i++){
            if (s[i] == s[n-i-1]){
                occ[s[i]-'a']++ ; 
                mx = max(occ[s[i]-'a'],mx) ; 
                sum++ ; 
            }
        }
        sort(occ,occ+26) ; 
        reverse(occ,occ+26) ; 
        if (occ[0]>sum-occ[0]){
            cout << occ[0] << endl ; 
        }else
            cout << (sum+1)/2 << endl ;  
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