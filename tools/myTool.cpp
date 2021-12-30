#include "myTool.h"
#include <iostream>

int sum(vector<int> & nums,int l,int r){
    int temp = 0;
    for(int i =l;i<=r;i++){
        temp += nums[i];
    }
    return temp;
};
int max(vector<int> & nums,int l,int r,int sub){
    int temp = - 0x7fffffff - 1;
    for(int i =l;i<=r;i++){
        temp = temp > nums[i]-sub? temp:nums[i]-sub;
    }
    return temp;
};
int Dijkstra(const vector<vector<pair<int,int> > >  & G,int st,int ed){
    vector<int> d(G.size(),0x7fffffff);
    vector<int> c(G.size(),-0x7fffffff-1);
    vector<bool> vis(G.size(),false);

    d[st] = G[st][st].first;
    c[st] = G[st][st].second;


    //依次遍历每一个节点
    for(int i =0;i<G.size();i++){
        int u = -1,min_d = 0x7fffffff;
        //寻找到未访问节点中距离最近的
        for(int j=0;j<G.size();j++){
            if(!vis[j] && d[j]<min_d){
                u=j;
                min_d = d[j];
            }
        }
        if(u==-1) return -1;    //剩余的顶点和起点不连通
        vis[u] =true;
        for(int v=0;v<G.size();v++){

            if(vis[v]==false && G[u][v].first != -1){
                if(d[u] + G[u][v].first < d[v]){
                    d[v] = d[u] + G[u][v].first;
                    c[v] = c[u] + G[u][v].second;
                }else if(d[u] + G[u][v].first == d[v]){
                    if(c[v] > c[u]+G[u][v].second){
                        c[v] = c[u] + G[u][v].second;
                    }
                }
            }
        }
    }

    return c[ed];
}
//理解偏差了，Dijkstra 只能是BFS，书上说能练习DFS指的是后期遍历
int DijkstraDFS(const vector<vector<pair<int,int> > >  & G,int st,int ed){
    vector<int> d(G.size(),0x7fffffff);
    vector<int> c(G.size(),-0x7fffffff-1);
    vector<bool> vis(G.size(),false);

    d[st] = G[st][st].first;
    c[st] = G[st][st].second;


    //依次遍历每一个节点
    for(int i =0;i<G.size();i++){
        int u = -1,min_d = 0x7fffffff;
        //寻找到未访问节点中距离最近的
        for(int j=0;j<G.size();j++){
            if(!vis[j] && d[j]<min_d){
                u=j;
                min_d = d[j];
            }
        }
        if(u==-1) return -1;    //剩余的顶点和起点不连通
        vis[u] =true;

        while (true){
            int v = findShortestNode(G,vis,u);
            if(v==-1||v==st) break;
            if(d[u] + G[u][v].first < d[v]){
                d[v] = d[u] + G[u][v].first;
                c[v] = c[u] + G[u][v].second;
            }else if(d[u] + G[u][v].first == d[v]){
                if(c[v] > c[u]+G[u][v].second){
                    c[v] = c[u] + G[u][v].second;
                }
            }
            u=v;
        }
    }

    return c[ed];
}
int findShortestNode(const vector<vector<pair<int,int> > >  & G,const vector<bool> & vis,int st){
    int result = -1,min_d = 0x7fffffff;
    for(int i = 0;i<G.size();i++){
        if(!vis[i] && G[st][i].first> 0 && min_d > G[st][i].first){
            result = i;
            min_d = G[st][i].first;
        }
    }
    return result;
}


int F(vector<int> & result,int n){
    if(n ==0 || n == 1)
        return 1;
    if(result[n]==-1)
        result[n] = F(result,n-1)+F(result,n-2);
    return result[n];
        
}

int getN(const vector<int> & result,int n){
    if(result[n]==-1){
        return 0;
    }
    return result[n];
}


void printVector(const vector<int> & v){
    for(int i =0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
}

bool com(int a,int b){
    return a<b;
};

int coinChanges(vector<unordered_map<int,int>> & result ,vector<int>& coins, int amount){
    if(amount==0) return 0;
    if(amount <0) return -1;
    int needCnt = 0x7fffffff,temp=0;
    // for(int item: coins){
    //     if(amount-item < 0 ) continue;
    //     temp = coinChanges(result,coins,amount-item) + 1;
    //     if(temp ==0 ) continue;
    //     if(temp<needCnt) needCnt = temp;
    // }

    for(int i =0;i<coins.size();i++){
        if(amount-coins[i] < 0 ) continue;
        auto iter = result[i].find(amount);
        if(iter != result[i].end()) {
            temp = iter->second;
        }
        else {
            temp = coinChanges(result,coins,amount-coins[i]) + 1;
            result[i][amount] = temp;
        }
        if(temp ==0 ) continue;
        if(temp<needCnt) needCnt = temp;
    }
    return needCnt==0x7fffffff?-1:needCnt;
}

int coinChanges(unordered_map<int,int> & result ,vector<int>& coins, int amount){
    if(amount==0) return 0;
    if(amount <0) return -1;
    int needCnt = 0x7fffffff,temp=0;
    // for(int item: coins){
    //     if(amount-item < 0 ) continue;
    //     temp = coinChanges(result,coins,amount-item) + 1;
    //     if(temp ==0 ) continue;
    //     if(temp<needCnt) needCnt = temp;
    // }

    auto iter = result.find(amount);
    if(iter != result.end()) {
        needCnt = iter->second;
    }else{
        for(int i =0;i<coins.size();i++){
            if(amount-coins[i] < 0 ) continue;
            temp = coinChanges(result,coins,amount-coins[i]) + 1;
            if(temp ==0 ) continue;
            if(temp<needCnt) needCnt = temp;
        }
        result[amount] = needCnt;
    }
    return needCnt==0x7fffffff?-1:needCnt;
}

int getMaxStu(vector<vector<bool>> seat,vector<unordered_map<long long,int>> & caches,int m,int n){
    int max_stu = 0,i=0,j=0,a=0,b=0;
    long long index=0;
    bool flag = false;
    while (a<m){
        b=0;
        while (b<n){
            index = (index<<1) +seat[a][b];
            if(!flag && seat[a][b]){
                flag = true;
                i=a;j=b;
            }
            b++;
        }
        a++;
    }

    if(!flag) return 0;

    auto iter = caches[0].find(index);
    if(iter!=caches[0].end()){
        a = iter->second;
    }else{

        vector<vector<bool>> notseat(seat);
        
        notseat[i][j] = false;
        a = getMaxStu(notseat,caches,m,n);
        caches[0][index] = a;
    }

    iter = caches[1].find(index);
    if(iter!=caches[0].end()){
        b=iter->second;
    }else{
        vector<vector<bool>> canseat(seat);
        canseat[i][j]= false;
        if(j-1>=0){
            canseat[i][j-1]=false;
            if(i-1>=0) canseat[i-1][j-1]=false;
            if(i+1<m) canseat[i+1][j-1]=false;
        }
        if(j+1<n){
            canseat[i][j+1]=false;
            if(i-1>=0) canseat[i-1][j+1]=false;
            if(i+1<m) canseat[i+1][j+1]=false;
        }
        b=getMaxStu(canseat,caches,m,n)+1;
        caches[1][index] = b;
        // b++;
    }

    // vector<vector<bool>> canseat(seat);
    // canseat[i][j]= false;

    // if(j-1>=0){
    //     canseat[i][j-1]=false;
    //     if(i-1>=0) canseat[i-1][j-1]=false;
    //     if(i+1<m) canseat[i+1][j-1]=false;
    // }
    // if(j+1<n){
    //     canseat[i][j+1]=false;
    //     if(i-1>=0) canseat[i-1][j+1]=false;
    //     if(i+1<m) canseat[i+1][j+1]=false;
    // }
    // b =getMaxStu(canseat,caches,m,n)+1;

    cout<<a<<"\t"<<b<<endl;
    return max(a,b);
}


bool getSubState(int i,int j,const vector<vector<bool>> & dp){
    if(j-i<=1) return true;
    return dp[i+1][j-1];
}