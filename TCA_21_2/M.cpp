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
#include <array>

using namespace std;

typedef long long ll;
typedef long double ld;
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
const int MAXN = 1e4; // CAMBIAR ESTE

// GJNM
ll N, M, K, T;
pii BAD[MAXN];

int main() {
    rll(N, M), rll(K, T);
    FOR(i, 0, K) {
        rii(BAD[i].F, BAD[i].S);
    }
    sort(BAD, BAD + K);

    while (T--) {
        int a, b; rii(a, b);
        pii aux = {a, b};
        auto it = lower_bound(BAD, BAD + K, aux);
        if (*it == aux) {
            printf("Waste\n");
        }
        else {
            int i = it - BAD;
            ll tot = M * (a - 1) + b - i;
            if (tot % 3 == 0)
                printf("Grapes\n");
            else if (tot % 3 == 1)
                printf("Carrots\n");
            else
                printf("Kiwis\n");
        }
    }


    return 0;
}