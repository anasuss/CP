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
     
    const int N = 3e3+10 ;
     
    const int mod = 1e9+7 ;
     
     
    string s1 , s2 ; 
    int dp[N][N] ; 
    void solve(){
        cin >> s1 >> s2 ;
        int n = s1.size() ; int m = s2.size() ;  
        for (int ind1 = 1; ind1 <= n; ind1++) {
            for (int ind2 = 1; ind2 <= m; ind2++) {
            if (s1[ind1 - 1] == s2[ind2 - 1])
                dp[ind1][ind2] = 1 + dp[ind1 - 1][ind2 - 1];
            else
                dp[ind1][ind2] = 0 + max(dp[ind1 - 1][ind2], dp[ind1][ind2 - 1]);
            }
        }
        int len = dp[n][m];
            int i = n;
            int j = m;

            int index = len - 1;
            string str = "";
            for (int k = 1; k <= len; k++) {
                str += "$"; // dummy string
            }

            while (i > 0 && j > 0) {
                if (dp[i - 1][j-1]+1 == dp[i][j]) {
                str[index] = s1[i - 1];
                index--;
                i--;
                j--;
                } else if (dp[i-1][j] == dp[i][j]) {
                i--;
                } else j--;
            }
            cout << str; 
        return ;
    }
     
     
     
    int main(){
        SaveTime
       // freopen("input.txt","r",stdin) ;
        int t = 1 ;
       // cin >> t ;
        for (int i = 1 ; i<=t ; i++){
            solve() ;
        }
    }