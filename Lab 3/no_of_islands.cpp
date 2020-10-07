#include<bits/stdc++.h>

using namespace std;

class disjointSet
{
    public:
    int count=0;

    int findParent(int x,int parent[])
    {
        if (parent[x] == x)
        {
            return x;
        }
        return parent[x] = findParent(parent[x],parent);
    }

    void unionSet(int x, int y,int parent[])
    {
        int subsetx = findParent(x,parent);
        int subsety = findParent(y,parent);

        if (subsetx != subsety)
        {
            parent[subsetx] = subsety;
            (count)--;
        }
    }

    void setCount(int num)
    {
        count = num;
    }

    int count_island()
    {
        return count;
    }

};

int noOfIslands(int grid[][20],int x,int y)
{
    if(x == 0 || y == 0)
        return 0;

    int row = x;
    int col = y;

    int count = 0;

    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
        {
            if(grid[i][j]==1)
                count++;
        }
    }

    int n = row*col;
    int parent[n];

    for(int i=0;i<n;i++)
    {
        parent[i]=i;
    }

    disjointSet setp;
    setp.setCount(count);


    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
        {
            if(grid[i][j]==1)
            {
                if(i> 0 && grid[i-1][j]==1)
                    setp.unionSet(row*i+j, row*(i-1)+j,parent);

                if(i<row-1 && grid[i+1][j]==1)
                    setp.unionSet(row*i+j, row*(i+1)+j,parent);

                if (j > 0 && grid[i][j - 1])
                     setp.unionSet(row * i + j, row * i + j - 1,parent);

                if (j < col - 1 && grid[i][j + 1])
                    setp.unionSet(row * i + j, row* i + j + 1,parent);

                if(i+1<row && j+1<col && grid[i+1][j+1]==1)
                    setp.unionSet(row*i+j, row*(i+1)+(j+1),parent);

                if(i+1<row && j-1>0 &&  grid[i+1][j-1]==1)
                    setp.unionSet(row*i+j, row*(i+1)+(j-1),parent);

                if (i-1 >0&& j+1<col && grid[i-1][j+1]==1)
                     setp.unionSet(row * i + j, row * (i-1) + j +1,parent);

                if (i-1>0 && j-1>0 && grid[i-1][j-1]==1)
                    setp.unionSet(row * i + j, row* (i-1) + j - 1,parent);

            }
        }
    }
    //cout<<row<<" "<<col<<" "<<count<<endl;
   return setp.count_island();

}


int main()
{
    int no_of_row,no_of_col;
    cout<<"Enter no of rows: "<<endl;
    cin>>no_of_row;
    cout<<"Enter no of columns: "<<endl;
    cin>>no_of_col;

    int grid[no_of_row][20];

    cout<<"Grid is : "<<endl;

    for(int i=0;i<no_of_row;i++)
    {
        for(int j=0;j<no_of_col;j++)
        {
            cin>>grid[i][j];
        }
    }

    int islands = noOfIslands(grid,no_of_row,no_of_col);
    cout <<"No of islands: "<<islands<<endl;
}
