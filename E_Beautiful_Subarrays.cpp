#include <bits/stdc++.h>
 
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<ll> vl ;
typedef pair<ll,ll> pl;
 
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()
#define max(a,b) (a>b ? a : b)
#define min(a,b) (a<b ? a : b)
#define FAST ios::sync_with_stdio(0), cin.tie(0),cout.tie(0)
 
const int MOD = (int)0+(int)1e8 ;
const int N = 1000005;
const double PI =4*atan(1);
const double eps = 1e-10;
const long long oo = 1e10;
const int K = 26;
 
const int AlPHA = 2, B = 30;
ll res=0;
 
struct Node {
    Node *next[AlPHA];
    ll freq;
    Node() {
        freq = 0;
        for (int i = 0; i < AlPHA; ++i)
            next[i] = NULL;
    }
} *Trie;
 
void insert(int p) {
    Node *cur = Trie;
    for (int i = B - 1; i >= 0; --i) {
        int bit = (p >> i) & 1;
        if (cur->next[bit] == NULL)
            cur->next[bit] = new Node();
        cur = cur->next[bit];
        ++cur->freq;
    }
}
 
ll get(Node * cur){
    if(cur==NULL)return 0;
    return cur->freq;
}
 
 
void DFS(Node *cur, int at, int p, int l) {
    if (cur == NULL || at == -1)
        return;
    int curL = (l >> at) & 1;
    int curP = (p >> at) & 1;
    if(curL==0){
        if(curP==0){
            res+=get(cur->next[1]);
        }else{
            res+=get(cur->next[0]);
        }
        if(curP==0){
            DFS(cur->next[0],at-1,p,l);
        }else{
            DFS(cur->next[1],at-1,p,l);
        }
    }else{
        if(curP==0){
            DFS(cur->next[1],at-1,p,l);
        }else{
            DFS(cur->next[0],at-1,p,l);
        }
    }
}
 
int n;
ll k;
ll a[N];
 
 
int main(){
    FAST;
   // freopen("easy.txt","r",stdin);
    Trie = new Node();
    cin >> n >> k;
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    insert(0);
    ll cur = 0;
    for(int i=0;i<n;i++){
        cur=(cur^a[i]);
        DFS(Trie,B-1,cur,k-1);
        insert(cur);
    }
    cout << res;
 
    return 0;
}