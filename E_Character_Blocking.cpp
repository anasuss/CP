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
     
     
     
    string s[2] ; 
    int blocked[N] , unblocked[N] ; 
    int q,k ;  
    int diff ; 

    void add(int x){ diff += s[0][x] != s[1][x] ; } ; 
    void rem(int x) {diff -= s[0][x] != s[1][x] ; } ; 

    void solve(){
        cin >> s[0] >> s[1]; 
        int n = s[0].size() ; 
        diff = 0 ; 
        for (int i = 0 ; i<n ; i++){
            diff+=(s[0][i] != s[1][i]) ; 
        }
        cin >> k >> q ; 
        for (int i = 0 ; i<=q ; i++){
            unblocked[i] = -1 ; 
        }
        for (int i = 0 ; i<q ; i++){
            if (unblocked[i] != -1){
                add(unblocked[i]) ; 
                
            }
            int x ;  cin >> x ; 
            if (x == 1){
                int p ; cin >> p ; --p ; 
                unblocked[i+k] = p ; 
                rem(p) ; 
            }else if (x == 2){
                int c1,p1,c2,p2 ; 
                cin >> c1 >> p1 >> c2 >> p2 ; 
                --c1 ; --p1 ; --p2 ; --c2 ; 
                if (s[c1][p1] == s[c2][p2]) 
                    continue; 
                rem(p1) ; 
                rem(p2) ; 
                swap(s[c1][p1],s[c2][p2]) ; 
                add(p1) ; 
                add(p2) ; 
            }else if (x == 3){
                if (diff == 0){
                    yes ; 
                }else 
                    no ; 
            }
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
    }