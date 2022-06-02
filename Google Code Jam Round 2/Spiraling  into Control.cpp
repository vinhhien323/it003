#include <bits/stdc++.h>
using namespace std;
using i64 = int64_t;
using _ii = pair<int,int>;
int gg = 0;
void Google()
{
	cout << "Case #" << ++gg << ": ";
}
vector <vector<int>> Create(int n)
{
	vector <vector<int>> a(n);
	for(auto &i : a) i.resize(n);
	auto Fill_left = [&](int x, int y, int &val)
	{
		int i;
		for(i = y; i < n; ++i)
		{
			if(i != y && a[x][i] > 0) break;
			a[x][i] = val;
			++val;
		}
		val--;
		return _ii(x,i-1);
	};
	auto Fill_right = [&](int x, int y, int &val)
	{
		int i;
		for(i = y; i >= 0; --i)
		{
			if(i != y && a[x][i] > 0) break;
			a[x][i] = val;
			++val;
		}
		val--;
		return _ii(x,i+1);
	};
	auto Fill_down = [&](int x, int y, int &val)
	{
		int i;
		for(i = x; i < n; ++i)
		{
			if(i != x && a[i][y] > 0) break;
			a[i][y] = val;
			++val;
		}
		val--;
		return _ii(i-1,y);
	};
	auto Fill_up = [&](int x, int y, int &val)
	{
		int i;
		for(i = x; i >= 0; --i)
		{
			if(i != x && a[i][y] > 0) break;
			a[i][y] = val;
			++val;
		}
		val--;
		return _ii(i+1,y);
	};
	int val = 1;
	_ii pos = {0,0};
	while(true)
	{
		pos = Fill_left(pos.first,pos.second,val);
		if(val == n*n) break;
		pos = Fill_down(pos.first,pos.second,val);
		if(val == n*n) break;
		pos = Fill_right(pos.first,pos.second,val);
		if(val == n*n) break;
		pos = Fill_up(pos.first,pos.second,val);
		if(val == n*n) break;
	}
	return a;
}
struct Node
{
	int x,y,k;
};	
vector <_ii> Solve(vector<vector<int>> &a, int n, int k)
{
	map<int,_ii> loca;
	for(int i = 0; i < n; ++i)
	{
		for(int j = 0; j < n; ++j)
		{
			loca[a[i][j]] = _ii(i,j);
		}
	}
	vector <_ii> ans;
	vector <vector<int>> dp(n*n+1,vector<int>(k+1));
	vector <vector<_ii>> trace(n*n+1,vector<_ii>(k+1));
	int dx[] = {0,0,-1,1};
	int dy[] = {-1,1,0,0};
	auto nxt_jump = [&](_ii pos)
	{
		for(int i = 0; i < 4; ++i)
		{
			int new_x = pos.first + dx[i];
			int new_y = pos.second + dy[i];
			if(new_x < 0 || new_x >= n || new_y < 0 || new_y >= n) continue;
			if(a[new_x][new_y] > a[pos.first][pos.second]+1) return _ii(new_x,new_y);
		}
		return _ii(-1,-1);
	};
	auto nxt_normal = [&](_ii pos)
	{
		for(int i = 0; i < 4; ++i)
		{
			int new_x = pos.first + dx[i];
			int new_y = pos.second + dy[i];
			if(new_x < 0 || new_x >= n || new_y < 0 || new_y >= n) continue;
			if(a[new_x][new_y] == a[pos.first][pos.second]+1) return _ii(new_x,new_y);
		}
		return _ii(-1,-1);
	};
	queue <Node> A;
	A.push({0,0,0});
	while(A.size())
	{
		Node h = A.front();
		A.pop();
		_ii pos = nxt_normal({h.x,h.y});
		if(h.k >= k) continue;
		//cerr << h.x << ' ' << h.y << ' ' << h.k << '\n';
		for(int j = 0; j < 2; ++j)
		{
			if(pos.first != -1 && dp[a[pos.first][pos.second]][h.k+1] == 0)
			{
				trace[a[pos.first][pos.second]][h.k+1] = _ii(h.x,h.y);
				dp[a[pos.first][pos.second]][h.k+1] = 1;
				A.push({pos.first,pos.second,h.k+1});
			}
			pos = nxt_jump({h.x,h.y});
		}
	}
	if(dp[n*n][k])
	{
		_ii pos = {n/2,n/2};
		while(pos != _ii(0,0))
		{
			_ii pre_pos = trace[a[pos.first][pos.second]][k];
			if(nxt_jump(pre_pos) == pos) ans.push_back({a[pre_pos.first][pre_pos.second],a[pos.first][pos.second]});
			pos = pre_pos;
			k--;
		}
		reverse(ans.begin(),ans.end());
	}
	else ans.push_back({-1,-1});
	return ans;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while(t--)
	{
		Google();
		int n,k; cin >> n >> k;
		auto a = Create(n);
		auto ans = Solve(a,n,k);
		if(ans[0] != _ii(-1,-1))
		{
			cout << ans.size() << '\n';
			for(auto &i : ans) cout << i.first << ' ' << i.second << '\n';
		}
		else cout << "IMPOSSIBLE" << '\n';
	}
}