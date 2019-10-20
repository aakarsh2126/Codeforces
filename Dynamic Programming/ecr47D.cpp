    //Author-Ankit Kumar Mishra
    //Problem D
    //Relatively Prime Graph
    
    #include <bits/stdc++.h>
    using namespace std;
    int main()
    {
    	ios_base::sync_with_stdio(false);cin.tie(NULL);
    	vector <pair<int,int> >ar;
        int n,m;
        cin>>n>>m;int c=0;int flag=0;
        for(int i=1;i<=n;i++)
        {
        	for(int j=i+1;j<=n;j++)
        	{
        		if(__gcd(i,j)==1)
        			ar.push_back(make_pair(i,j));
        		if(ar.size()>=m)
        			{
        				flag=1;
        				break;
        			}
        	}
        	if(flag)
        		break;
        }
        if(ar.size()<m||(n-1>m))
        	cout<<"Impossible\n";
        else
        {
        	cout<<"Possible\n";
        	for(int i=0;i<ar.size();i++)
        	{
        		cout<<ar[i].first<<" "<<ar[i].second<<endl;
        	}
        }
        return 0;
    }
