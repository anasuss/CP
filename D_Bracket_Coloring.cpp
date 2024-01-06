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
    string s ; 
    ll a[N] ;
    ll b[N] ;  
    void solve(){
        vector<int> ans ; 
        cin >> n >> s ; 
        int cnt = 0 ; 
        int p = 1 ; 
        int color = 1 ; 
        int mx = 1 ; 
        if (s[0] == ')') p = -1 ; 
        for (int i = 0 ; i<n ; i++){
            if (s[i] == '(') ++cnt ; 
            else --cnt; 
            if (cnt*p<0){
                cout << -1 << endl ; 
                return ; 
            }
            ans.pb(color) ; 
            if (cnt == 0){
                int lst = p ; 
                if (s[i+1] == '(' && i<n)
                    p = 1 ; 
                else if (i<n && s[i+1] == ')')
                    p = -1 ; 
                
                if (p != lst)
                    if (color == 1) color = 2 ; 
                    else color = 1 ; 
            }
            mx = max(mx,color) ; 
        }
        if (cnt != 0){
            cout << -1 << endl ; 
            return ; 
        }
        cout << mx << endl ; 
        for (int i : ans) cout << i << " " ; 
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