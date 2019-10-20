// Ankit Kumar Mishra
// problem 358D
// Alyona and Strings 

    #include <bits/stdc++.h>
    using namespace std;
    string st1,st2;
    int n,m,K;
    int dp[1003][1003][12];
    int maxans=0;
    int calc(int i,int j,int k)
    {
    	if(k>K)
    		return INT_MIN;
    	if((i>=m||j>=n)&&(k<K||k>K))
    		return INT_MIN;
    	if((i>=m||j>=n)&&k==K)
    		return 0;
    	if(dp[i][j][k]!=-1)
    		return dp[i][j][k];
    	dp[i][j][k]=0;
    	if(st1[i]==st2[j])
    	{
    		int l=0;
    		while((i+l<m)&&(j+l<n)&&st1[i+l]==st2[l+j])
    			{
    				dp[i][j][k]=max(dp[i][j][k],l+1+calc(i+l+1,j+l+1,k+1));
    				l++;
    			}
    	}
    	dp[i][j][k]=max(dp[i][j][k],max(calc(i+1,j,k),calc(i,j+1,k)));
        return dp[i][j][k];
    }
    int main()
    {
    	ios_base::sync_with_stdio(false);
    	cin.tie(NULL);
    	cin>>m>>n>>K;
    	cin>>st1;
    	cin>>st2;
    	if(st1==st2)
    		cout<<m<<endl;
    	else
    	{
    	memset(dp,-1,sizeof(dp));
    	cout<<calc(0,0,0)<<endl;
        }
    }
