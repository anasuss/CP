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
     
    const int N = 2e9+100 ;
     
    const int mod = 1e9+7 ;
    
    int k ;

    void back_track(int n , int i , vector<int>& v , vector<vector<int>>& s){
        if (n == 0){
            s.pb(v) ; 
            return ; 
        }
        if (i>n) return ;    
        if (n-i>=0){ 
            v.pb(i) ; 
            back_track(n-i,i,v,s) ; 
            v.pop_back() ; 
        }
        back_track(n,i+1,v,s) ; 
        return ; 
    }
    void solve(){ 
        int totalAdults , totalChildren ; 
        cin >> totalAdults >> totalChildren ; 
        vector<vector<int>> adults ;
        vector<vector<int>> childrens ;
        vector<int> temp ;  
        back_track(totalAdults,1,temp,adults) ; 
        if (totalChildren == 0){
            for (auto v : adults){
                for (auto i : v){
                    cout << "[ adults = " << i << ", children = " << 0 << "]" << " " ; 
                } 
                cout << endl ; 
            }
            return ; 
        }
        back_track(totalChildren,1,temp,childrens) ;
        vector<vector<pair<int,int>>> ans ; 
        for (vector<int> &adult : adults){
            do{
                for (const vector<int> &children : childrens){
                    vector<pair<int,int>> v ; 
                    if (children.size()>adult.size()){
                        continue;
                    } 
                    for (int i = 0 ; i<min(children.size(),adult.size()) ; i++){
                        v.push_back({adult[i],children[i]}) ; 
                    }
                    for (int i = min(children.size(),adult.size()) ; i<max(children.size(),adult.size()) ; i++){
                            if (children.size()>adult.size()){
                                v.push_back({0,children[i]});
                            }
                            else{
                                v.push_back({adult[i],0}) ;
                            } 
                    }
                    ans.push_back(v) ; 
                }
            }while(next_permutation(adult.begin(),adult.end())) ; 
        }
        for (auto &v : ans){
            for (auto &vp : v){
                cout << "[ adults = " << vp.first << ", children = " << vp.second << "]" << " " ; 
            }
            cout << endl ; 
        }
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