// Day 23
// Question : Search a 2D Matrix II

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.size()==0||matrix[0].size()==0)
        {
            return false;
        }
        int n=matrix.size(),m=matrix[0].size(),i=0,j=m-1;
        while(i<n&&j>=0)
        {
            int x=matrix[i][j];
            if(x==target)
            {
                return true;
            }
            if(target<x)
            {
                j--;
            }
            if(target>x)
            {
                i++;
            }
        }
        return false;
    }
};