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
     
    const int N = 1e6+100;
     
    const int mod = 1e9+7 ;
     
     
     
    int n ;
      

    vector<int> graph[N] ; 



    ll cal (ll x){
        return x*(x+1)*(2*x+1)/6 ; 
    }

    void solve(){
        cin >> n ;
        ll left = n , right = n ; 
        ll ans = 0 ; 
        while(graph[left].size()){
            ans+=cal(right)-cal(left-1LL) ; 
            left = graph[left][0] , right = graph[right].back() ; 
        } 
        cout << ans+1 << endl ; 
        return ;
    }
     
     
     
    int main(){
        SaveTime
       // freopen("input.txt","r",stdin) ;
        int cnt = 1 ; 
        for (int i = 1 ; i<2025 && cnt+i+1<=1e6+10 ; i++){
            for (int j = 1 ; j<=i && cnt+i+1<=1e6+10 ; j++){
                graph[cnt+i].pb(cnt) ; 
                graph[cnt+i+1].pb(cnt) ; 
                ++cnt ; 
            }
        }
        int t = 1 ;
        cin >> t ;
        for (int i = 1 ; i<=t ; i++){
            solve() ;
        }
    }