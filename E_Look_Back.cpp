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
	 
	 
	 
	ll n,h,a,c,q ;
	 
	void solve(){
		cin >> n >> h >> a >> c >> q ;
		vector<ll> v(n) ; v[0] = h ; 
		for (ll i = 1 ; i<n ; i++){
			v[i] = (((v[i-1])*(a))+c)%q;
		}
		stack<pair<ll,ll>> stk ; 
		ll ans = 0 ; 
		for (int i = n-1 ; i>=0 ; i--){
			while(!stk.empty() && stk.top().first<=v[i])
				stk.pop() ; 
			if (!stk.empty()){
				int x = stk.top().second-i-1 ;
				if (x) ans+=x ; 
			}else{
				if (i+2<n){
					ans+=(n-i-2) ; 
				}
			}
			stk.push({v[i],i}) ; 
		}
		cout << ((ans+n-1)) ; 
		return ;
	}
	 
	 
	 
	int main(){
		SaveTime
	   // freopen("input.txt","r",stdin) ;
		int t = 1 ;
		//cin >> t ;
		for (int i = 1 ; i<=t ; i++){
			solve() ;
		}
	}