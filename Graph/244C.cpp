//Author- Ankit Kumar Mishra
//Round 244 Problem C
//Checkposts    
    
   #include <bits/stdc++.h>
    using namespace std;
    vector <int> adj1[100005];
    vector <int> adj2[100005];
    long long int cost[100005];
    bool vis[100005];
    #define mod 1000000007
    vector <vector <int> >ar;
    stack <int> s;
    vector <int> temp;
    int n,m;
    long long int dfs(int u)
    {
    	vis[u]=true;
    	for(int i=0;i<adj1[u].size();i++)
    	{
    		if(!vis[adj1[u][i]])
    			dfs(adj1[u][i]);
    	}
    	s.push(u);
    	return 0;
    }
    long long int dfs2(int u)
    {
    	vis[u]=true;
    	temp.push_back(u);
    	for(int i=0;i<adj2[u].size();i++)
    	{
    		if(!vis[adj2[u][i]])
    			dfs2(adj2[u][i]);
    	}
    	return 0;
    }
    int main()
    {
    	ios_base::sync_with_stdio(false);
    	cin.tie(NULL);
    	cin>>n;
    	for(int i=1;i<=n;i++)
    	{
    		cin>>cost[i];
    	}
    	cin>>m;
    	for(int i=1;i<=m;i++)
    	{
    		int u,v;
    		cin>>u>>v;
    		adj1[u].push_back(v);
    		adj2[v].push_back(u);
    	}
    	memset(vis,false,sizeof(vis));
    	for(int i=1;i<=n;i++)
    	{
    		if(!vis[i])
    			dfs(i);
    	}
    	memset(vis,false,sizeof(vis));
    	while(!s.empty())
    	{
    		int u=s.top();
    		s.pop();
    		temp.clear();
    		if(!vis[u])
    		dfs2(u);
    	    ar.push_back(temp);
    	}
    	long long int ans2=1;long long int ans1=0;
    	for(int i=0;i<ar.size();i++)
    	{
    		long long int mincost=INT_MAX;long long int num=0;
    		for(int j=0;j<ar[i].size();j++)
    		{
    			if(cost[ar[i][j]]<mincost)
    			{
    				mincost=cost[ar[i][j]];
    				num=1;
    			}
    			else if(cost[ar[i][j]]==mincost)
    			{
    				mincost=cost[ar[i][j]];
    				num++;
    			}
    		}
    		if(ar[i].size()>0)
    		{
    		ans2=((ans2%mod)*(num%mod))%mod;
    		ans1+=mincost;
    	    }
    	}
    	cout<<ans1<<" "<<ans2<<endl;
    }
