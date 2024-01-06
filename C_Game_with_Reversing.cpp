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
     
    int work(const string &s1 , const string &s2 , int x){
        int ans = x ; 
        int dif = 0 ; 
        for (int i = 0 ; i<s1.size() ; i++){
            dif+=(s1[i] != s2[i]) ; 
        }
        if (dif>0 && ans>0) --dif ; 
        ans+=dif; 
        if (dif%2 == 0 && x == 0){
            ans+=dif ; 
        }else if (dif%2 == 1 && x == 0){
            ans+=(dif-1) ; 
        }else if (dif%2 == 0 && x == 1){
            ans+=(dif+1) ; 
        }else if (dif%2 == 1 && x == 1){
            ans+=dif ; 
        }
        return ans ;
    }

    void solve(){
        cin >> n ; 
        string s1 , s2 ; 
        cin >> s1 >> s2 ; 
        int ans = work(s1,s2,0) ; 
        reverse(s1.begin(),s1.end()) ; 
        cout << min(ans,work(s1,s2,1)) << endl ; 
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
        return 0; 
        cout << "NIKOMHA il 10 laf" ;
    }