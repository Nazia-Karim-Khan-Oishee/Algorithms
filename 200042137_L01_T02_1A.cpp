// #include <bits/stdc++.h>
// #include <list>
// using namespace std;


// int main()
// {


// 	int n,x;
// 	cin>>n;
// 	bool adj_matrix[n][n];
// 	for(int i=0;i<n;i++)
//     {
//         for(int j=0;j<n;j++)
//         {
//             cin>>x;
//             adj_matrix[i][j]=x;
//         }
//     }


//     int indegree[n]={0}, outdegree[n]={0};


// 	for (int i = 0; i < n; i++)
// 	 {
//         for (int j = 0; j < n; j++)
//         {
// 		    int x = adj_matrix[i][j];
// 			outdegree[i] += x;
// 			indegree[j] += x;
// 		}
// 	}
//     sort(outdegree, outdegree+n);
// 	cout<<outdegree[n-1];
//   return 0;
// }

#include<iostream>
#include<vector>
using namespace std;


void dfs(int start,vector<vector<int>>v,vector<bool>&visited){
  visited[start]=true;
  for (int i = 0; i < v[start].size(); i++) {
        if (v[start][i] == 1 && (!visited[i])) {
            dfs(i,v, visited);
        }
    }
}

int main()
{
  int n;
  int count=0;
  cin>>n;
  vector<vector<int>>v;  
  vector<bool>flag(n,false);
  for(int i=0;i<n;i++)
  {
    vector<int>temp(n);
    for(int j=0;j<n;j++)
    {
      cin>>temp[j];
    }
    v.push_back(temp);
  }
  vector<int>nodes;
  for(int i=0;i<n;i++)
  {
    nodes.push_back(i);
  }
  for(int i:nodes)
  {
    if(!flag[i])
    {
      dfs(i,v,flag);
      count++;
    }
  }
  cout<<count;
  
}