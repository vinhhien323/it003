#include <bits/stdc++.h>
using namespace std;
using i64 = int64_t;
using _ii = pair<int,int>;
void Solve()
{
	int n; cin >> n;
	int k; cin >> k;
	i64 sum = 0, sum_sqr = 0;
	vector <i64> a(n);
	for(auto &i : a)
	{
		cin >> i;
		sum += i;
		sum_sqr += (i*i);
	}
	i64 sum_prd = sum*sum - sum_sqr;
	sum *= 2;
	vector <i64> ans;
	if(sum == 0)
	{
		if(sum_prd == 0) ans.resize(k,0);
	}
	else
	{
		if(sum_prd % sum == 0)
		{
			ans.resize(k,0);
			ans[0] = -sum_prd/sum;
		}
	}
	if(ans.empty()) cout << "IMPOSSIBLE" << '\n';
	else
	{
		for(auto &i : ans) cout << i << ' ';
		cout << '\n';
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int t; cin >> t;
	for(int _i = 1; _i <= t; ++_i)
	{
		cout << "Case #" << _i << ": ";
		Solve();
	}
}