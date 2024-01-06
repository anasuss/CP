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
     
    string s1 , s2 ; 

    void solve(){
        string s1,s2 ; cin >> s1 >> s2 ; 
        if (s1 == s2){
            cout << 0 << endl ; 
            return ; 
        }
        while(s1.size()<s2.size()){
            s1 = "0"+s1 ; 
        }
        int ans = 0 ; 
        int idx = s1.size() ; 
        for (int i = 0 ; i<s1.size() ; i++){
            if (s1[i] != s2[i] && idx == s1.size()) idx = i ; 
            ans+=abs(s1[i]-s2[i]) ; 
        }
        int x = s1[idx] ; 
        int y = s2[idx] ; 
        for (int i = 0 ; i<=9 ; i++){
            s1[idx]++ ; 
            s2[idx]-- ; 
            if(s2[idx]<x || s1[idx]>y) break ; 
            ans = max(ans,abs(s1[idx]-s2[idx])+9*((int)s1.size()-idx-1)) ; 
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