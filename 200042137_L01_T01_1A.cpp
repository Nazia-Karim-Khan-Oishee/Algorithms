#include <bits/stdc++.h>
#include <list>
using namespace std;


int main()
{
	int n,x;
	cin>>n;
	bool adj_matrix[n][n];
	for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>x;
            adj_matrix[i][j]=x;
        }
    }

    int indegree[n]={0}, outdegree[n]={0};

	for (int i = 0; i < n; i++)
	 {
        for (int j = 0; j < n; j++)
        {
		    int x = adj_matrix[i][j];
			outdegree[i] += x;
			indegree[j] += x;
		}
	}
      int celebrity=-1;
	for (int i = 0; i < n; i++)
    {
		if (indegree[i] == n && outdegree[i] == 1)
        {
          celebrity=i;
        }

    }
    if(celebrity!=-1)
    {

	cout<<"Person "<<celebrity<<" is the celebrity";
        return 0;
}
cout<<"There is no celebrity.";
return 0;
    }



