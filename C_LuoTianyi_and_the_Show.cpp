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
     
     
     
    int n ,m;

    void solve(){
        cin >> n >> m; 
        set<int> s ; int cntleft = 0 , cntright = 0 ; 
        int ans = 0 ; 
        for (int i = 0 ; i<n ; i++){
            int x ; cin >> x ; 
            if (x == -1) cntleft++ ; 
            else if (x == -2) cntright++;
            else{
                s.insert(x) ; 
            }
        }
        ans = min(m,cntleft+(int)s.size()) ; 
        ans = max(ans,min(m,cntright+(int)s.size())) ; 
        int p = 0 ; 
        for (int i : s){
            int l = min(m,min(i-1,cntleft+p)) ;
            int r = min(m,min(m-i,cntright+(int)s.size()-p-1));
            ++p ; 
            ans = max(ans,min(m,l+r+1)) ; 
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