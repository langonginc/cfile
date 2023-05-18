#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <climits>
#include <algorithm>
#include <cstring>
using namespace std;
const int inf = 5e4 + 5;
int t, n, k, a[5][inf], f1[5], f2[5];

namespace k3
{
	int n, k, a[5][inf], but[inf];
	int vmax = 0, vmin = INT_MAX, pmaxx, pmaxy, pminx, pminy;
	int temp[5];
	
	class LinePoint
	{
		public:
			int color, val;
			bool operator < (const LinePoint &x) const
			{
				return val < x.val;
			}
			LinePoint () {}
			LinePoint (int _color, int _val)
			{
				color = _color, val = _val;
			}
	};
	
	vector <LinePoint> line;
	
	inline int posCalc (int x)
	{
		if ((x + 3) % 3 == 0)
		{
			return 3;
		}
		return (x + 3) % 3;
	}
	
	void rotate (int col, int offset)
	{
		for (int i = 1; i <= 3; i ++)
		{
			temp[i] = a[posCalc (i + offset)][col];
		}
	}
	
	bool check (int mid, int maxLine)
	{
		// printf ("Check: mid = %d, maxLine = %d\n", mid, maxLine);
		for (int j = 1; j <= n; j ++)
		{
			if (j == pminy)
			{
				rotate (j, pminx - 1);
				if (temp[maxLine] < vmax - mid)
				{
					return false;
				}
				line.push_back (LinePoint (j, temp[maxLine ^ 1]));
			}
			else if (j == pmaxy)
			{
				rotate (j, pmaxx - maxLine);
				if (temp[1] > vmin + mid)
				{
					return false;
				}
				line.push_back (LinePoint (j, temp[maxLine ^ 1]));
			}
			else
			{
				int flag = false;
				for (int to = 1; to <= 3; to ++)
				{
					rotate (j, to);
					if (temp[1] > vmin + mid)
					{
						continue;
					}
					if (temp[maxLine] < vmax - mid)
					{
						continue;
					}
					line.push_back (LinePoint (j, temp[maxLine ^ 1]));
					flag = true;
				}
				if (flag == false) return false;
			}
		}
		return true;
	}
	
	int findans (int res)
	{
		int ans = INT_MAX;
		// printf ("Erfen Res: %d\n", res);
												
		sort (line.begin(), line.end());
		int cl = 0, cr = 0, count = 0, lineSize = line.size ();
		
		// for (int i = 0; i < lineSize; i ++)
		// {
			// printf ("[%d] Color %d, Value %d\n", i, line[i].color, line[i].val);
		// }
		
		memset (but, 0, sizeof (but));
		while (cl <= cr && cr < lineSize)
		{
			// printf ("[%d, %d]\n", cl, cr);
			if (count >= n)
			{
				ans = min (ans, max (res, line[cr - 1].val - line[cl].val));
				but[line[cl].color] --;
				if (but[line[cl].color] == 0) count --;
//				printf ("CL: Color %d, but[color]=%d, count=%d\n", line[cl].color, but[line[cl].color], count);
				cl ++;
			}
			else
			{
				if (but[line[cr].color] == 0) count ++;
				but[line[cr].color] ++;
//				printf ("CR: Color %d, but[color]=%d, count=%d\n", line[cr].color, but[line[cr].color], count);
				cr ++;
			}
			if (count == n)
			{
				ans = min (ans, max (res, line[cr - 1].val - line[cl].val));				
			}
		}
		// printf ("Find %d\n", ans);
		return ans;
	}
	
	void start (int t)
	{
		while (t --)
		{
			k = 3;
			scanf ("%d", &n);
			vmax = 0, vmin = INT_MAX;
	        for (int i = 1; i <= k; i ++)
	        {
	            for (int j = 1; j <= n; j ++)
	            {
	                scanf ("%d", &a[i][j]);
	                if (a[i][j] > vmax)
	                {
	                	vmax = a[i][j], pmaxx = i, pmaxy = j;
					}
					if (a[i][j] < vmin)
					{
						vmin = a[i][j], pminx = i, pminy = j;
					}
	            }
	        }
	        if (vmin == vmax)
	        {
	        	printf ("0\n");
	        	continue;
			}
			
			// printf ("MAX: (%d, %d), MIN: (%d, %d)\n", pmaxx, pmaxy, pminx, pminy);
			
//			if (pmaxy == pminy)
//			{
//				printf ("Emm.\n");
//				exit (0);
//			}
	        
	        //er fen
	        int ans = INT_MAX;
	        for (int maxLine = 2; maxLine <= 3; maxLine ++)
	        {
	        	int left = 0, right = vmax - vmin, mid = 0, res = INT_MAX;
		        while (left <= right)
		        {
		        	line.clear();
		        	mid = (left + right) >> 1;
		        	if (check (mid, maxLine))
		        	{
		        		right = mid - 1;
					}
					else
					{
						res = mid;
						left = mid + 1;
					}
					ans = min (ans, findans (mid));
				}
			}
	        printf ("%d\n", ans);
		}
	}
}

int main ()
{
    scanf ("%d%d", &t, &k);
    if (k == 1)
    {
	    while (t --)
	    {
	        scanf ("%d", &n);
	        for (int i = 1; i <= k; i ++)
	        {
	            f1[i] = 0, f2[i] = 2147483647;
	            for (int j = 1; j <= n; j ++)
	            {
	                scanf ("%d", &a[i][j]);
	                f1[i] = max (f1[i], a[i][j]);
	                f2[i] = min (f2[i], a[i][j]);
	            }
	        }
	        int ans = 0;
	        for (int i = 1; i <= k; i ++)
	        {
	            ans = max (ans, f1[i] - f2[i]);
	        }
	        printf ("%d\n", ans);
	    }
	}
	if (k == 2)
	{
		while (t --)
		{
			scanf ("%d", &n);
	        for (int i = 1; i <= k; i ++)
	        {
	            f1[i] = 0, f2[i] = 2147483647;
	            for (int j = 1; j <= n; j ++)
	            {
	                scanf ("%d", &a[i][j]);
	            }
	        }
	        for (int j = 1; j <= n; j ++)
	        {
	        	if (a[1][j] < a[2][j]) swap (a[1][j], a[2][j]);
			}
			for (int i = 1; i <= k; i ++)
			{
				for (int j = 1; j <= n; j ++)
				{
	                f1[i] = max (f1[i], a[i][j]);
	                f2[i] = min (f2[i], a[i][j]);
				}
			}
	        int ans = 0;
	        for (int i = 1; i <= k; i ++)
	        {
	            ans = max (ans, f1[i] - f2[i]);
	        }
	        printf ("%d\n", ans);
		}
	}
	if (k == 3)
	{
		k3::start (t);
	}
    return 0;
}
