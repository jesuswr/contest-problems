#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

int dasdas;

#define FOR(i,n,m) for(int i = n; i < (int)m; i++)
#define ROF(i,n,m) for(int i = n; i > (int)m; i--)
#define ms(obj,val) memset(obj,val,sizeof(obj))
#define ri(a) dasdas=scanf("%d", &a)
#define rii(a,b) ri(a), ri(b)
#define lri(a) dasdas=scanf("%lld", &a)
#define lrii(a,b) lri(a), lri(b)
#define all(x) x.begin(),x.end()
#define sz(x) (int)(x).size()
#define pb push_back
#define S second
#define F first

const int INF = 0x3f3f3f3f;
const ll INFLL = 1e18;
const int MOD = 1e9+7;
const int MAXN = 2e5+5;

void fastIO() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}


int main(){
	int x; ri(x);
	vi dsts;
	FOR(i,1,3) {
		int a = i;
		int mn = INF;
		int carry = 0;
		while(a > 0) {
			cout << a << "    " << carry + abs(x-a) << endl;
			mn = min(mn, carry + abs(x - a));
			a = a / 2;
			carry++;
		}
		dsts.pb(mn);
	}
	FOR(i,1,sz(dsts)) cout << dsts[i] << endl; 
	return 0;
}
