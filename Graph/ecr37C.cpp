//Author- Ankit Kumar Mishra
//Problem ECR 37C
//Swap Adjacent Elements

    #include <bits/stdc++.h>
    using namespace std;
    int main()
    {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;int ar[n+4];
    string st,st1;
    int arr[n+4];
    for(int i=1;i<=n;i++)
    {
    cin>>ar[i];
    }
    cin>>st;
    st=" "+st;
    for(int i=1;i<=n;i++)
    {
    if(ar[i]>i)
    {
    string str=st.substr(i,ar[i]-i);
    if(str.find("0")!=string::npos)
    {
    cout<<"NO"<<endl;
    return 0;
    }
    str=st.substr(i);
    if(str.find("0")!=string::npos)
    {i=i+str.find("0")-1;}
    else
    {
    cout<<"YES"<<endl;
    return 0;
    }
    }
    if(ar[i]<i)
    {
    string str=st.substr(ar[i],i-ar[i]);
    if(str.find("0")!=string::npos)
    {
    cout<<"NO"<<endl;
    return 0;
    }
    }
    }
    cout<<"YES"<<endl;
    }
