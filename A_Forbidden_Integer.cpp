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
     
    const int N = 200 ;
     
    const int mod = 1e9+7 ;
     
     
     
    int n,k,x ;
    int dp[N][N] ; 
    vector<int> ans ; 
    vector<int> vec ; 
    bool ok ; 
    void work(int i = 1 , int s = 0){ 
        if (s == n && !ok){
            ans = vec ;  
            ok = true ; 
            return ; 
        }
        if (ok) return ;
        if (dp[i][s] != -1) 
            return  ; 
        if (i>k)
            return  ; 
        dp[i][s] = 1 ; 
        if (s+i<=n && !ok && i != x){
            vec.pb(i) ; 
            work(i,s+i) ; 
            work(i+1,s+i) ; 
            vec.pop_back() ; 
        }
        work(i+1,s) ; 

    }
    void solve(){
        memset(dp,-1,sizeof(dp)) ; 
        cin >> n >> k  >> x ;
        ok = false ; 
        ans.clear() ; 
        vec.clear() ; 
        work(1,0) ; 
        if (ans.size() != 0){
            yes ; 
            cout <<ans.size()  << endl ; ; 
            for (int i : ans){
                cout << i << " " ; 
            }
            cout << endl ; 
        }else{
            no ; 
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
        return 0 ; 
    }