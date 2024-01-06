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
     
     
     
    int n,k;
    string s ; 
    void solve(){
        cin >> n >> k; 
        cin >> s ; 
        vector<int> freq(26,0) ; 
        for (int i = 0 ; i<s.size() ; i++){
            int x = s[i]-'a' ; 
            freq[x]++ ; 
        }
        int rem = 0 ; 
        for (int i = 0 ; i<26 ; i++){
            rem+=(freq[i]%2) ; 
        }
        if (k<rem){
            if (rem-k == 1 && (n-k)%2 == 1)
                yes ; 
            else 
                no ; 
            return ; 
        }
        if ((k-rem)%2 == 1 && (n-k)%2 == 1){
            yes ; 
            return ; 
        }
        if ((k-rem)%2 == 0 && (n-k)%2 == 0){
            yes; return ; 
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