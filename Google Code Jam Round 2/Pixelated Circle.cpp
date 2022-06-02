#include <bits/stdc++.h>
using namespace std;
using i64 = int64_t;
using _ii = pair<int,int>;
int gg = 0;
void Google()
{
	cout << "Case #" << ++gg << ": ";
}
double Round(double val)
{
	if(val - floor(val) == 0.5)
	{
		if(val >= 0) return floor(val);
		else return ceil(val);
	}
	else return round(val);
}
void Check(vector <vector<int>> &pixel)
{
	for(auto &i : pixel)
	{
		for(auto &j :i) cout << j << ' ';
		cout << '\n';
	}
	cout << '\n';
}
void draw_circle_perimeter(vector <vector<int>> &pixel, int r, int R)
{ 
	function <void(int,int)> set_pixel_to_black;
	set_pixel_to_black = [&](int x, int y)
	{
		x += R;
		y += R;
		pixel[x][y] = 1;
	};
 	for(int x = -r; x <= r; ++x)
  	{
    	int y = Round(sqrt(r * r - x * x));
    	set_pixel_to_black(x, y);
    	set_pixel_to_black(x, -y);
    	set_pixel_to_black(y, x);
    	set_pixel_to_black(-y, x);
    	//Check(pixel);
    }
}
int draw_circle_filled(int r)
{
	vector <vector<int>> pixel(r*3,vector<int>(r*3));
	function <void(int,int)> set_pixel_to_black;
	set_pixel_to_black = [&](int x, int y)
	{
		x += r;
		y += r;
		pixel[x][y] = 1;
	};
  	for(int x = -r; x <= r; ++x)
    {
    	for(int y = -r; y <= r; ++y)
    	{
    		if (Round(sqrt(x * x + y * y)) <= r) set_pixel_to_black(x, y);
    	}
    }
    int cnt = 0;
    for(auto &i : pixel)
    {
    	for(auto &j : i) cnt += j;
    }
	//Check(pixel);
	return cnt;
}
int draw_circle_filled_wrong(int r)
{
	vector <vector<int>> pixel(r*3,vector<int>(r*3));
  	for(int i = 0; i <= r; ++i)
  	{
  		draw_circle_perimeter(pixel,i,r);
  	}
  	int cnt = 0;
    for(auto &i : pixel)
    {
    	for(auto &j : i) cnt += j;
    }
	//Check(pixel);
	return cnt;
}
int main()
{
	//freopen("test.txt","w",stdout);
	//cerr << Round(sqrt(8)) << '\n';
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while(t--)
	{
		Google();
		int r; cin >> r;
		int a = draw_circle_filled(r);
		int b = draw_circle_filled_wrong(r);
		cout << abs(a-b) << '\n';
	}
}