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
     
    ll a[N] ;
    ll b[N] ;  
    bool check(string &s1 , string &s2){
        for (int i = 0 ; i<n/2 ; i++){
            if (s2[i] == s1[0]){
                bool ok = false ; 
                for (int j = 0 ; j<n/2 ; j++){
                    if (s1[j] != s2[i+j]){
                        ok = true ; 
                        break ; 
                    }
                }
                if (!ok) return true ; 
            }
        } 
        return false ; 
    }
    void solve(){
        string s ; cin >> s ; 
        n = s.size() ; n*=2 ; 
        string s1 = "" ; string s2 = "" ; 
        for (int i = 0 ; i<n ; i++){
            if(i%2 == 0) s1+='(' ; 
            else s1+=')' ; 
        }
        for (int i = 0 ; i<n ; i++){
            if (i<n/2) s2+='(' ;
            else s2+=')' ;  
        }
        if (!check(s,s1)){
            yes ; 
            cout << s1 << endl ; 
        }else if (!check(s,s2)){
            yes ; 
            cout << s2 << endl ; 
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
    }