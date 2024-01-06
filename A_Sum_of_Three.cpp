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
     
     
     
    int n ;

    void solve(){
        cin >> n ; 
        int x = 1 ; 
        int y = 2 ; 
        int z = n-3 ; 
        if (z <= 0 || z == x || z == y){
            no ; 
            return ; 
        }
        if (z%3 == 0){
            while(z%3 == 0 && z>y){
                ++y; --z ; 
                while(y%3 == 0 && z>y){
                    y++ ; z-- ;  
                }
            }
            if (z<=y){
                no ; return ;
            }
            yes ; 
            cout << x << " " << y << " " << z << endl  ; return ; 
        }
        yes ; 
        cout << x << " " << y << " " << z << endl ; 
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