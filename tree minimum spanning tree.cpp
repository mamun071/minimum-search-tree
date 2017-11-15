///kruskal
#include<bits/stdc++.h>
using namespace std;
#define mx 100001
struct edge
{
    int u,v,w;
    bool operator<(const edge& p)const
    {
        return w<p.w;
    }
}get;

vector<edge>vec;
int par[mx];

int setfind(int n)
{
    if(par[n]==n)
        return n;
    else
        return par[n]=setfind(par[n]);
}

int mst(int n)
{
    sort(vec.begin(),vec.end());
    for(int i=1;i<n;i++)
        par[i]=1;
    int s=0,count=0;
    for(int i=0;i<vec.size();i++)
    {
        int u=setfind(vec[i].u);
        int v=setfind(vec[i].v);
        if(u!=v)
        {
            par[u]=v;
            count++;
            s+=vec[i].w;
            if(count==n-1)
                break;
        }
    }
    return s;
}

main()
{
    int n,m,u,v,w;
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        cin>>u>>v>>w;
        get.u=u;
        get.v=v;
        get.w=w;
        vec.push_back(get);
    }
    cout<<mst(n)<<endl;

}
