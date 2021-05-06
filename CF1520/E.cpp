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
#include <assert.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<int, pair<int, int>> piii;
typedef vector<int> vi;
typedef vector<pii> vii;

int dadsadasda;

#define ri(a) dadsadasda=scanf("%d", &a)
#define rii(a,b) dadsadasda=scanf("%d %d", &a, &b)
#define riii(a,b,c) dadsadasda=scanf("%d %d %d", &a, &b, &c)
#define rl(a) dadsadasda=scanf("%lld", &a)
#define rll(a,b) dadsadasda=scanf("%lld %lld", &a, &b)
#define FOR(i,n,m) for(int i=n; i<m; i++)
#define ROF(i,n,m) for(int i=n; i>m; i--)
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define F first
#define S second
#define ALL(s) s.begin(),s.end()
#define SZ(s) (int)s.size()

const int INF = 0x3f3f3f3f;
const ll LLINF = 1e18;
const int MAXN = 1e5; // CAMBIAR ESTE

// GJNM
int N, M;
string S;

void solve() {
    ri(N); M = 0;
    cin >> S;
    map<int, int> mp;
    int mv_left = 0;
    ll ans = 0;
    FOR(i, 0, N) {
        if (S[i] == '*') {
            if (i - M > 0) {
                mp[i - M]++;
                ans += i - M;
                mv_left++;
            }
            M++;
        }
    }
    ll aux_ans = ans;
    FOR(i, 1, N - M + 1) {
        aux_ans = ans - mv_left + (M - mv_left);
        mv_left -= mp[i];
        ans = min(ans, aux_ans);
    }
    printf("%lld\n", ans);
}



int main() {
    int t; ri(t);
    while (t--) {
        solve();
    }

    return 0;
}