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
		int n,k; cin >> n >> k;
		string s; cin >> s;
		vector <int> pos;
		bool x = (s[0] == '1');
		bool y = (s[n-1] == '1');
		for(int i = 1; i < n-1; ++i)
		{
			if(s[i] == '1') pos.push_back(i);
		}
		i64 ans = 0;
		for(int i = 1; i < n; ++i)
		{
			int x = s[i-1] - '0';
			int y = s[i] - '0';
			ans += (x*10+y);
		}
		vector <bool> mark(n);
		if(k > 0 && pos.size() > 0 && y == false && abs(pos.back()-(n-1)) <= k)
		{
			y = true;
			mark[pos.back()] = true;
			k -= abs(pos.back()-(n-1));
			ans -= 10;
		}
		if(k > 0 && x == true && y == false && n-1 <= k)
		{
			x = false;
			y = true;
			k -= abs(n-1);
			ans -= 9;
		}
		for(auto &i : pos)
		{
			if(x == true || k == 0) break;
			if(mark[i]) continue;
			if(i <= k)
			{
				x = true;
				k -= i;
				ans--;
			}
		}
		cout << ans << '\n';
	}	
}