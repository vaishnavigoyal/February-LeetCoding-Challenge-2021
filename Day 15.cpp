// Day 15
// Question : The K Weakest Rows in a Matrix

class Solution
{
public:
	vector<int> kWeakestRows(vector<vector<int>> &mat, int k)
	{
		priority_queue<pair<int, int>> pq;
		for (int i = 0; i < mat.size(); i++)
		{
			int x = 0;
			for (int j = 0; j < mat[i].size(); j++)
			{
				if (mat[i][j] == 1)
				{
					x++;
				}
				else
				{
					break;
				}
			}
			pq.push({x, i});
			if (pq.size() > k)
			{
				pq.pop();
			}
		}
		vector<int> res;
		while (!pq.empty())
		{
			res.push_back(pq.top().second);
			pq.pop();
		}
		reverse(res.begin(), res.end());
		return res;
	}
};