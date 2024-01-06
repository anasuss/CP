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
	const int mod = 1e9+7 ;
	const int N = 2e5+100 ;
	ll gcd(ll a , ll b) {return b ? gcd(b , a % b) : a ;}
	ll lcm(ll a , ll b) {return (a * b) / gcd(a , b);}
	ll inv(ll i) {if (i == 1) return 1; return (mod - ((mod / i) * inv(mod % i)) % mod) % mod;}  
	ll C(int n , int k){
		assert(n>=k) ; 
		//return fact[n]*inv(fact[k]*fact[n-k]%mod)%mod ; 
		return 0 ; 
	}
	 
	 
	int n ;
	void solve(){
		cin >> n ; 
		string ans = "ROYGBIV" ; 
		string s = "ROYGBIV" ; 
		for (int i = 7 ; i<n-3 ; i++){
			ans+=s[i%7] ; 
		}
		int i = ans.size()-1 ;
		for (int k = 0 ; k<3 && ans.size() != n ; k++){
			for (int j = 0 ; j<s.size() ; j++){
				if (s[j] == ans[i] || s[j] == ans[i-1] || s[j] == ans[i-2] || s[j] == ans[0] || s[j] == ans[1] || s[j] == ans[2]){
					continue;
				}
				ans+=s[j] ; 
				break ; 
			}
			++i ; 
		}
		cout << ans ; 
	}
	 
	 
	 
	int main(){
		SaveTime
	   // freopen("input.txt","r",stdin) ;
		int t = 1 ;
		for (int i = 1 ; i<=t ; i++){
			solve() ;
		}
	}