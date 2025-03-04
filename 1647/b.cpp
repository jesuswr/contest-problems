#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

int qwert;

#define FOR(i,n,m) for(int i = n; i < (int)m; i++)
#define ROF(i,n,m) for(int i = n; i > (int)m; i--)
#define ms(obj,val) memset(obj,val,sizeof(obj))
#define ri(a) qwert = scanf("%d", &a)
#define rii(a,b) ri(a), ri(b)
#define lri(a) qwert = scanf("%lld", &a)
#define lrii(a,b) lri(a), lri(b)
#define all(x) x.begin(),x.end()
#define sz(x) (int)(x).size()
#define pb push_back
#define S second
#define F first

const int INF = 0x3f3f3f3f;
const ll INFLL = 1e18;
const int MOD = 1e9 + 7;
const int MAXN = 200 + 5;

void fastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

int N, M;
int A[MAXN][MAXN];
void solve() {
    rii(N, M);
    ms(A, 0);
    FOR(i, 1, N + 1) FOR(j, 1, M + 1) {
        qwert = scanf("%1d", &A[i][j]);
    }
    FOR(i, 1, N + 1) FOR(j, 1, M + 1) {
        if (A[i][j] + A[i + 1][j] + A[i][j + 1] + A[i + 1][j + 1] == 3) {
            printf("NO\n");
            return;
        }
    }
    printf("YES\n");
}


int main() {
    int t; ri(t);
    while (t--) solve();
    return 0;
}
