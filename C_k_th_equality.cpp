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
     
    ll a[N] ;
    ll b[N] ;  
    #include <iostream>
#include <string>

std::string findKthLexSmallestEquality(int A, int B, int k) {
    int C = A + B;
    int count = 0;

    for (int a = 1; a <= 9; ++a) {
        for (int b = 1; b <= 9; ++b) {
            int c = a + b;
            if (std::to_string(c).length() == C) {
                count++;
                if (count == k) {
                    return std::to_string(a) + "+" + std::to_string(b) + "=" + std::to_string(c);
                }
            }
        }
    }

    return "The k-th lexicographically smallest equality does not exist.";
}

    void solve(){
        int A,B,C,K ; 
        cin >> A >> B >> C >> K ; 
        cout << findKthLexSmallestEquality(A,B,K) << endl ; 
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