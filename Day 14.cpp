// Day 14
// Question : Is Graph Bipartite?

class Solution
{
public:
	bool vis[101];
	int col[101];

	bool dfs(int node, int c, vector<vector<int>> &graph)
	{
		vis[node] = true;
		col[node] = c;

		for (int child : graph[node])
		{
			if (!vis[child])
			{
				if (dfs(child, c ^ 1, graph) == false)
				{
					return false;
				}
			}
			else
			{
				if (col[child] == c)
				{
					return false;
				}
			}
		}
		return true;
	}

	bool isBipartite(vector<vector<int>> &graph)
	{

		memset(vis, false, sizeof(vis));
		memset(col, 0, sizeof(col));
		for (int i = 0; i < graph.size(); i++)
		{
			if (!vis[i])
			{
				if (!dfs(i, 0, graph))
				{
					return false;
				}
			}
		}
		return true;
	}
};