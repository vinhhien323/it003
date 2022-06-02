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
		vector <int> a(n);
		int cnt = 0;
		for(auto &i : a)
		{
			cin >> i;
			if(i % 2 == 1) ++cnt;
		}
		cout << min(cnt,n-cnt) << '\n';
	}
}