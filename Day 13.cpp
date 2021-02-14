// Day 13
// Question : Shortest Path in Binary Matrix

class Solution
{
public:
	int shortestPathBinaryMatrix(vector<vector<int>> &grid)
	{
		int n = grid.size();
		if (n == 0)
		{
			return 0;
		}
		if (grid[0][0] == 1 || grid[n - 1][n - 1] == 1)
		{
			return -1;
		}
		int dist[n][n];
		bool vis[n][n];
		memset(vis, false, sizeof(vis));
		memset(dist, 0, sizeof(dist));
		queue<pair<int, int>> q;
		q.push({0, 0});
		dist[0][0] = 1;
		while (!q.empty())
		{
			int x = q.front().first;
			int y = q.front().second;

			q.pop();
			if (x == n - 1 && y == n - 1)
			{
				return dist[n - 1][n - 1];
			}
			if (x + 1 < n && grid[x + 1][y] == 0 && !vis[x + 1][y])
			{
				q.push({x + 1, y});
				dist[x + 1][y] = dist[x][y] + 1;
				vis[x + 1][y] = true;
			}
			if (y + 1 < n && grid[x][y + 1] == 0 && !vis[x][y + 1])
			{
				q.push({x, y + 1});
				dist[x][y + 1] = dist[x][y] + 1;
				vis[x][y + 1] = true;
			}
			if (x - 1 >= 0 && grid[x - 1][y] == 0 && !vis[x - 1][y])
			{
				q.push({x - 1, y});
				dist[x - 1][y] = dist[x][y] + 1;
				vis[x - 1][y] = true;
			}
			if (y - 1 >= 0 && grid[x][y - 1] == 0 && !vis[x][y - 1])
			{
				q.push({x, y - 1});
				dist[x][y - 1] = dist[x][y] + 1;
				vis[x][y - 1] = true;
			}
			if (x + 1 < n && y + 1 < n && grid[x + 1][y + 1] == 0 && !vis[x + 1][y + 1])
			{
				q.push({x + 1, y + 1});
				dist[x + 1][y + 1] = dist[x][y] + 1;
				vis[x + 1][y + 1] = true;
			}
			if (x + 1 < n && y - 1 >= 0 && grid[x + 1][y - 1] == 0 && !vis[x + 1][y - 1])
			{
				q.push({x + 1, y - 1});
				dist[x + 1][y - 1] = dist[x][y] + 1;
				vis[x + 1][y - 1] = true;
			}
			if (x - 1 >= 0 && y - 1 >= 0 && grid[x - 1][y - 1] == 0 && !vis[x - 1][y - 1])
			{
				q.push({x - 1, y - 1});
				dist[x - 1][y - 1] = dist[x][y] + 1;
				vis[x - 1][y - 1] = true;
			}
			if (x - 1 >= 0 && y + 1 < n && grid[x - 1][y + 1] == 0 && !vis[x - 1][y + 1])
			{
				q.push({x - 1, y + 1});
				dist[x - 1][y + 1] = dist[x][y] + 1;
				vis[x - 1][y + 1] = true;
			}
		}
		return -1;
	}
};