// Day 7
// Question : Shortest Distance to a Character

class Solution
{
public:
	vector<int> shortestToChar(string s, char c)
	{
		int n = s.length();
		vector<int> res(n);
		for (int i = 0; i < n; i++)
		{
			int j = i, k = i;
			while (j >= 0 && k < n)
			{
				if (s[j] == c)
				{
					res[i] = (i - j);
					break;
				}
				if (s[k] == c)
				{
					res[i] = (k - i);
					break;
				}
				if (j > 0)
				{
					j--;
				}
				if (k < n - 1)
				{
					k++;
				}
			}
		}
		return res;
	}
};