// https://codeforces.com/problemset/problem/766/E
// Cool problem to practice centroid tree, try doing another one easier before this


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
typedef pair<int, int> pii;
typedef pair<int, pair<int, int>> piii;
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
const int MAXN = 1e5; // CAMBIAR ESTE

// GJNM
vector<int> G[MAXN];
int v;

// LCA //
int l;
int timer;
int tin[MAXN], tout[MAXN];
int up[MAXN][25];

void dfs(int v, int p) {
	tin[v] = ++timer;
	up[v][0] = p;
	for (int i = 1; i <= l; ++i)
		up[v][i] = up[up[v][i - 1]][i - 1];

	for (int u : G[v]) {
		if (u != p)
			dfs(u, v);
	}

	tout[v] = ++timer;
}

bool is_ancestor(int u, int v) {
	return tin[u] <= tin[v] && tout[u] >= tout[v];
}

int lca(int u, int v) {
	if (is_ancestor(u, v))
		return u;
	if (is_ancestor(v, u))
		return v;
	for (int i = l; i >= 0; --i) {
		if (!is_ancestor(up[u][i], v))
			u = up[u][i];
	}
	return up[u][0];
}

void preprocess(int root) {
	timer = 0;
	l = ceil(log2(v));
	dfs(root, root);
}
////
int VAL[MAXN];

int height[MAXN];

void dfs_h(int x, int f = -1) {
	height[x] ^= VAL[x];
	for (auto y : G[x]) {
		if (f == y)
			continue;
		height[y] = height[x];
		dfs_h(y, x);
	}
}

int get_d(int x, int y) {
	return (height[x] ^ height[y] ^ VAL[lca(x, y)]);
}


// CENTROID //
bool is_centroid[MAXN];
int sz[MAXN];
int father[MAXN];
vector<int> CT[MAXN];

int dfs_sz(int x, int f = -1) {
	sz[x] = 1;
	for (auto y : G[x]) {
		if (y == f || is_centroid[y])
			continue;
		sz[x] += dfs_sz(y, x);
	}
	return sz[x];
}


int dfs_cd(int x, int cent_sz, int f = -1) {
	for (auto y : G[x]) {
		if (y == f || is_centroid[y])
			continue;
		if (sz[y] > cent_sz / 2)
			return dfs_cd(y, cent_sz, x);
	}
	return x;
}


void cent_descomp(int x, int f = -1) {
	int cent_sz = dfs_sz(x);
	int centroid = dfs_cd(x, cent_sz);
	is_centroid[centroid] = true;
	father[centroid] = f;
	if (f != -1)
		CT[f].pb(centroid);
	for (auto y : G[centroid]) {
		if (is_centroid[y])
			continue;
		cent_descomp(y, centroid);
	}
}
/////
const int NUM_BITS = 20;

int cnt[MAXN][NUM_BITS][2];
vi cnt2[MAXN][NUM_BITS][2];
int HASH[MAXN];

void propagate(int x) {
	int hash = 0;
	for (auto y : CT[x]) {
		FOR(i, 0, NUM_BITS) {
			cnt2[x][i][1].pb(0);
			cnt2[x][i][0].pb(0);
		}
		HASH[y] = hash++;
		propagate(y);
	}
	int f = x, gf = father[x];
	while (gf != -1) {
		int dst = get_d(x, gf) ^ VAL[gf];
		FOR(i, 0, NUM_BITS) {
			if (dst & (1 << i)) {
				cnt[gf][i][1]++;
				cnt2[gf][i][1][HASH[f]]++;
			}
			else {
				cnt[gf][i][0]++;
				cnt2[gf][i][0][HASH[f]]++;
			}
		}
		f = father[f]; gf = father[gf];
	}
}

ll ans[NUM_BITS];

void get_ans(int x) {
	for (auto y : CT[x])
		get_ans(y);

	FOR(b, 0, NUM_BITS) {
		if (VAL[x] & (1 << b))
			ans[b] += cnt[x][b][0] + 1;
		else
			ans[b] += cnt[x][b][1];
	}

	int on[NUM_BITS], off[NUM_BITS];
	FOR(i, 0, NUM_BITS) {
		on[i] = off[i] = 0;
	}
	for (auto y : CT[x]) {
		FOR(b, 0, NUM_BITS) {
			int y_on = cnt2[x][b][1][HASH[y]];
			int y_off = cnt2[x][b][0][HASH[y]];

			ans[b] += y_off * on[b] + y_on * off[b];

			if (VAL[x] & (1 << b)) {
				on[b] += y_off;
				off[b] += y_on;
			}
			else {
				on[b] += y_on;
				off[b] += y_off;
			}
		}
	}
}

int main() {
	ri(v);
	FOR(i, 0, v) {
		ri(VAL[i]);
	}
	FOR(i, 1, v) {
		int x, y;
		rii(x, y); x--, y--;
		G[x].pb(y);
		G[y].pb(x);
	}
	cent_descomp(0);
	dfs_h(0);
	preprocess(0);
	FOR(i, 0, v) {
		if (father[i] == -1) {
			propagate(i);
			get_ans(i);
		}
	}
	ll ret = 0;
	FOR(i, 0, NUM_BITS) {
		ret += ans[i] * (1ll << i);
	}
	printf("%lld\n", ret);

	return 0;
}
