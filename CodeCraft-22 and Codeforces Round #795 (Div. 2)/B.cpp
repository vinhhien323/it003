#include <bits/stdc++.h>
using namespace std;
using i64 = int64_t;
using _ii = pair<int,int>;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while(t--)
	{
		int n; cin >> n;
		vector <_ii> a;
		for(int i = 0; i < n; ++i)
		{
			int x; cin >> x;
			a.push_back({x,i});
		}
		sort(a.begin(),a.end());
		vector <int> ans(n);
		bool check = true;
		for(int i = 0; i < n; ++i)
		{
			int j = i;
			while(j+1 < n && a[j+1].first == a[i].first) ++j;
			if(i == j)
			{
				check =false;
				break;
			}
			vector <int> b;
			for(int z = i; z <= j; ++z) b.push_back(a[z].second);
			for(int z = 0; z < b.size(); ++z)
			{
				int nxt = (z+1) % b.size();
				ans[b[z]] = b[nxt];
			}
			i = j;
		}
		if(check)
		{
			for(auto &i : ans) cout << i+1 << ' ';
			cout << '\n';
		}
		else cout << -1 << '\n';
	}	
}