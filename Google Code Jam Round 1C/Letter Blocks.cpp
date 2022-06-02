#include <bits/stdc++.h>
using namespace std;
using i64 = int64_t;
using _ii = pair<int,int>;
bool Check_only_one(string &s)
{
	for(int i = 1; i < s.size(); ++i) if(s[i] != s[i-1]) return false;
	return true;
}
string Run(vector <string> &a)
{
	int m = a.size();
	vector <int> del(m);
	for(int i = 0; i < m; ++i)
	{
		if(Check_only_one(a[i]))
		{
			for(int j = 0; j < m; ++j)
			{
				if(i == j) continue;
				if(a[j].back() == a[i].front())
				{
					a[j] += a[i];
					del[i] = 1;
					break;
				}
				if(a[i].back() == a[j].front())
				{
					a[j] = a[i] + a[j];
					del[i] = 1;
					break;
				}
			}
		}
	}
	vector <string> b;
	for(int i = 0; i < m; ++i) if(del[i] == 0) b.push_back(a[i]);
	swap(a,b);
	int n = a.size();
	string ans = "";
	string done = "IMPOSSIBLE";
	vector <int> mark(n);
	for(int i = 0; i < n; ++i)
	{
		if(mark[i]) continue;
		mark[i] = 1;
		while(true)
		{
			vector <int> head, tail;
			for(int j = 0; j < n; ++j)
			{
				if(mark[j]) continue;
				if(a[j].back() == a[i].front()) head.push_back(j);
				if(a[j].front() == a[i].back()) tail.push_back(j);
			}
			if(head.empty() && tail.empty()) break;
			if(head.size() >= 2 || tail.size() >= 2) return done;
			if(head.size())
			{
				int x = head[0];
				a[i] = a[x] + a[i];
				mark[x] = 1;
			}
			if(tail.size())
			{
				int x = tail[0];
				a[i] = a[i] + a[x];
				mark[x] = 1;
			}
		}
		ans += a[i];
	}
	vector <int> used(200);
	for(int i = 0; i < ans.size(); ++i)
	{
		if(used[ans[i]]) return done;
		used[ans[i]] = 1;
		int j = i;
		while(j+1 < ans.size() && ans[j+1] == ans[i]) ++j;
		i = j;
	}
	return ans;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int t; cin >> t;
	for(int _i = 1; _i <= t; ++_i)
	{
		cout << "Case #" << _i << ": ";
		int n; cin >> n;
		vector <string> a(n);
		for(auto &i : a) cin >> i;
		vector <int> mark(n);
		vector <string> b;
		for(int i = 0; i < n; ++i)
		{
			if(mark[i]) continue;
			mark[i] = 1;
			if(Check_only_one(a[i]))
			{
				for(int j = i+1; j < n; ++j)
				{
					if(Check_only_one(a[j]) && a[i][0] == a[j][0])
					{
						a[i] += a[j];
						mark[j] = true;
					}
				}
			}
			b.push_back(a[i]);
		}
		string ans = Run(b);
		cout << ans << '\n';
	}
}