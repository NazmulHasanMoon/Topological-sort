#include<bits/stdc++.h>
using namespace std;
#define sz 101
vector<int>v[sz];
vector<pair<int,pair<int,int>>>top;
int st,ed,c[sz],t(0);
void dfs(int s)
{
    st=++t;
    c[s]=1;
    vector<int>::iterator it;
    for(it=v[s].begin();it!=v[s].end();it++)
    {
        if(!c[*it])
            dfs(*it);
    }
    ed=++t;
    top.push_back({s,{st,ed}});
}
bool comp(pair<int,pair<int,int>>x,pair<int,pair<int,int>>y)
{
    if(x.second.second>=y.second.second)
        return 1;
    else
        return 0;
}
int main()
{
    int n,e;
    cin>>n>>e;
    for(int i=0;i<e;i++)
    {
        int x,y;
        cin>>x>>y;
        v[x].push_back(y);
    }
    for(int i=1;i<=n;i++){
        if(!c[i])
            dfs(i);
    }
    sort(top.begin(),top.end(),comp);
    cout<<endl;
    for(auto i: top)
        cout<<i.first<<' ';
    return 0;
}
