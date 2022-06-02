#include <bits/stdc++.h>
using namespace std;
using i64 = int64_t;
using _ii = pair<i64,i64>;
const int N = 3e5+7;
i64 seg_min[N<<2], seg_max[N<<2], inf = 1e18;
void Make(int pos, int L, int R, vector <i64> &val)
{
	if(L == R)
	{
		seg_min[pos] = val[L];
		seg_max[pos] = val[L];
		return;
	}
	int mid = (L+R) >> 1;
	Make(pos<<1,L,mid,val);
	Make(pos<<1|1,mid+1,R,val);
	seg_min[pos] = min(seg_min[pos<<1],seg_min[pos<<1|1]);
	seg_max[pos] = max(seg_max[pos<<1],seg_max[pos<<1|1]);
}
_ii Get(int pos, int L, int R, int x, int y)
{
	if(y < L || x > R) return {inf,-inf};
	if(x <= L && R <= y) return make_pair(seg_min[pos],seg_max[pos]);
	int mid = (L+R) >> 1;
	_ii u = Get(pos<<1,L,mid,x,y);
	_ii v = Get(pos<<1|1,mid+1,R,x,y);
	return make_pair(min(u.first,v.first),max(u.second,v.second));
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while(t--)
	{
		int n; cin >> n;
		vector <i64> a(n+1);
		for(int i = 1; i <= n; ++i) cin >> a[i];
		vector <i64> prefix(n+1);
		for(int i = 1; i <= n; ++i) prefix[i] = prefix[i-1] + a[i];
		Make(1,0,n,prefix);
		stack <int> A;
		vector <i64> val(n+1);
		for(int i = 1; i <= n; ++i)
		{
			while(A.size() && a[A.top()] <= a[i]) A.pop();
			i64 L = A.size() ? A.top() : 0;
			_ii u = Get(1,0,n,L,i-1);
			val[i] = prefix[i] - u.first;
			A.push(i);
		}
		while(A.size()) A.pop();
		bool ans = true;
		for(int i = n; i >= 1; --i)
		{
			while(A.size() && a[A.top()] <= a[i]) A.pop();
			i64 R = A.size() ? A.top()-1 : n;
			_ii u = Get(1,0,n,i,R);
			val[i] = val[i] + (u.second - prefix[i]);
			val[i] -= a[i];
			if(val[i] > 0)
			{
				ans = false;
				break;
			}
			A.push(i);
		}
		if(ans) cout << "YES" << '\n';
		else cout << "NO" << '\n';
	}	
}