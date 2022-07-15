// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
// UNASSIGNED is used for empty cells in sudoku grid 
#define UNASSIGNED 0  

// N is used for the size of Sudoku grid.  
// Size will be NxN  
#define N 9  


 // } Driver Code Ends
class Solution 
{
    public:
    //Function to find a solved Sudoku. 
    
    bool usedRow(int grid[N][N], int row, int num)
    {
        for(int i=0;i<N;i++)
        {
            if(grid[row][i]==num)
                return true;
        }
        return false;
    }
    bool usedCol(int grid[N][N], int col, int num)
    {
        for(int i=0;i<N;i++)
        {
            if(grid[i][col]==num)
                return true;
        }
        return false;
    }
    bool usedBox(int grid[N][N], int row, int col, int num)
    {
        for(int i=row;i<row+3;i++)
        {
            for(int j=col;j<col+3;j++)
            {
                if(grid[i][j]==num)
                return true;
            }
        }
        return false;
    }
    
    bool isSafe(int grid[N][N], int row, int col, int num)
    {
        return (!usedRow(grid, row, num) and !usedCol(grid, col, num) and !usedBox(grid, row-(row%3), col-(col%3), num));
    }
    
    bool fun(int grid[N][N], int x, int y)
    {
        if(x==N)
            return true;
        if(grid[x][y])
        {
            if(y==N-1)
            {
                if(fun(grid, x+1, 0))
                {
                    return true;
                }
            }
            else 
            {
                if(fun(grid, x, y+1))
                {
                    return true;
                }
            }
        }
        else
        {
            for(int i=1;i<=9;i++)
            {
                if(isSafe(grid, x, y, i))
                {
                    grid[x][y] = i;
                    if(y==N-1)
                    {
                        if(fun(grid, x+1, 0))
                        {
                            return true;
                        }
                    }
                    else 
                    {
                        if(fun(grid, x, y+1))
                        {
                            return true;
                        }
                    }
                    grid[x][y] = 0;
                }
            }
        }
        return false;
    }
    
    bool SolveSudoku(int grid[N][N])  
    { 
        // Your code here
        return fun(grid, 0, 0);
    }
    
    //Function to print grids of the Sudoku.
    void printGrid (int grid[N][N]) 
    {
        // Your code here 
        for(int i=0;i<N;i++)
        {
            for(int j=0;j<N;j++)
            {
                cout<<grid[i][j]<<" ";
            }
            // cout<<endl;
        }
    }
};

// { Driver Code Starts.

int main() {
	int t;
	cin>>t;
	while(t--)
	{
		int grid[N][N];
		
		for(int i=0;i<9;i++)
		    for(int j=0;j<9;j++)
		        cin>>grid[i][j];
		        
		Solution ob;
		
		if (ob.SolveSudoku(grid) == true)  
            ob.printGrid(grid);  
        else
            cout << "No solution exists";  
        
        cout<<endl;
	}
	
	return 0;
}  // } Driver Code Ends