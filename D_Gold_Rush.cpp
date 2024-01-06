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
     
     
     
    int n , m ;
     
    ll a[N] ;
    ll b[N] ;  
    void solve(){
        cin >> n >> m ;
        if (n == m || (n%3 == 0 && (n/3 == m || 2*(n/3) == m))){
            yes; 
            return ; 
        } 
        if (n<m || n%3 != 0){
            no ; 
            return ; 
        }
        queue<int> q ; 
        q.push(n) ; 
        while(!q.empty()){
            int x = q.front() ; 
            q.pop() ;
            int y = x/3 ; 
            int z = 2*(x/3) ; 
            if (y == m || z == m){
                yes; 
                return ; 
            } 
            if (y>m && y%3 == 0){
                q.push(y) ; 
    
            }
            if (z>m && z%3 == 0){
                q.push(z) ;
        
            }
        }
        no ; 
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