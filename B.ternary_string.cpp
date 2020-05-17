#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <math.h>
#include <string>
#include <cstring>
#include <set>
#include <map>
#include <unordered_map>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<int,pair<int,int>> piii;
typedef vector<int> vi;
typedef vector<pii> vii;

#define ri(a) scanf("%d", &a)
#define rii(a,b) scanf("%d %d", &a, &b)
#define riii(a,b,c) scanf("%d %d %d", &a, &b, &c)
#define rl(a) scanf("%lld", &a)
#define rll(a,b) scanf("%lld %lld", &a, &b)
#define FOR(i,n,m) for(int i=n; i<m; i++)
#define ROF(i,n,m) for(int i=n; i>m; i--)
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define F first
#define S second

const int INF = 0x3f3f3f3f;
const ll LLINF = 1e18;
const int maxN = 200009; // CAMBIAR ESTE


// GJNM
char S[maxN];

int main(){
	int t;
	ri(t);
	while(t--){
		scanf("%s", S);
		int n = strlen(S);
		int ans = INF;
		int one, two, three;
		one = two = three = -1;
		FOR(i,0,n){
			if ( S[i] == '1' ){
				one = i;
			}
			else if ( S[i] == '2' ){
				two = i;
			}
			else{
				three = i;
			}

			if ( one != -1 && two != -1 && three != -1 ){
				ans = min(ans, max(one,max(two,three)) - min(one,min(two,three))+1);
			}
		}
		if ( ans == INF )
			printf("0\n");
		else
			printf("%d\n", ans);
	}
	return 0;
}