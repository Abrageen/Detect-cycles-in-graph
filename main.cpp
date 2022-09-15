#include <iostream>

using namespace std;

int cycle(int from, int to, int graph[][100], int fin, int n)
{
    int flag=0;
    if(to==fin)
        return 1;
    for(int i=0; i<n ; i++)
    {
        if(graph[to][i])
            flag=cycle(to,i,graph,fin,n);
    }
    if(flag==1) return 1;
    else return 0;
}

check(int graph[][100],int n)
{
    for(int i=0 ; i<n ; i++)
    {
        for(int j=0 ; j<n ; j++)
        {
            if(graph[i][j]==1 && i!=j)
            {
                if(cycle(i,j,graph,i,n))
                    return 1;
            }
        }
    }
    return 0;
}

int main()
{
    int n, graph[100][100];
    cin>>n;
	for(int i=0;i<n;i++)
	    for(int j=0;j<n;j++)
	        graph[i][j]=0;

	// Input Edges
	int t;
	cin>>t;
	int x,y;
	for(int i=0;i<t;i++){
		cin>>x>>y;
		graph[x-1][y-1]=1;
	}
	/*for(int i=0;i<n;i++)
	    for(int j=0;j<n;j++)
	        cout<<graph[i][j]<<"  ";*/
	int flag=check(graph,n);
	cout<<flag;
    return 0;
}
