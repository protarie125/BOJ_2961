#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <limits>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <tuple>
#include <utility>
#include <vector>

using namespace std;

using ll = long long;
using vb = vector<bool>;
using vvb = vector<vb>;
using vi = vector<int>;
using vvi = vector<vi>;
using vl = vector<ll>;
using vvl = vector<vl>;
using pii = pair<int, int>;
using vii = vector<pii>;
using pll = pair<ll, ll>;
using vll = vector<pll>;

int n;
vll kh;
ll ans = numeric_limits<ll>::max();

vb used;
vll now;

void solve() {
	if (0 < now.size()) {
		auto shi = ll{ 1 };
		auto sse = ll{ 0 };
		for (const auto& [a, b] : now) {
			shi *= a;
			sse += b;
		}

		ans = min(ans, abs(shi - sse));

		if (n == now.size()) {
			return;
		}
	}

	for (auto i = 0; i < n; ++i) {
		if (used[i]) {
			continue;
		}

		now.push_back(kh[i]);
		used[i] = true;

		solve();

		now.pop_back();
		used[i] = false;
	}
}

int main() {
	ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	cin >> n;

	kh = vll(n);
	for (auto&& [a, b] : kh) {
		cin >> a >> b;
	}

	used = vb(n, false);
	now = vll{};
	now.reserve(n);

	solve();

	cout << ans;

	return 0;
}