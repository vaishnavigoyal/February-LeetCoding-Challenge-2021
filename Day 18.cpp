// Day 18
// Question : Arithmetic Slices

class Solution
{
public:
	int numberOfArithmeticSlices(vector<int> &A)
	{
		if (A.size() < 3)
		{
			return 0;
		}
		int res = 0;
		for (int i = 0; i < A.size() - 2; i++)
		{
			int diff = A[i + 1] - A[i];
			for (int j = i + 2; j < A.size(); j++)
			{
				int k = 0;
				for (k = i + 1; k <= j; k++)
				{
					if ((A[k] - A[k - 1]) != diff)
					{
						break;
					}
				}

				if (k > j)
				{
					res++;
				}
			}
		}
		return res;
	}
};