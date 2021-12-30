#ifndef MYTOOL_H
#define MYTOOL_H

#include <vector>
#include <map>
#include <unordered_map>

using namespace std;


int sum(vector<int> & nums,int l,int r);
int max(vector<int> & nums,int l,int r,int sub);

//BFS
int Dijkstra(const vector<vector<pair<int,int> > >  & G,int st,int ed);
//DFS
int DijkstraDFS(const vector<vector<pair<int,int> > >  & G,int st,int ed);

int findShortestNode(const vector<vector<pair<int,int> > >  & G,const vector<bool> & vis,int st);


int F(vector<int> & result,int n);

int getN(const vector<int> & result,int n);

void printVector(const vector<int> & v);


bool com(int a,int b);

int coinChanges(vector<unordered_map<int,int>> & result ,vector<int>& coins, int amount);

int coinChanges(unordered_map<int,int> & result ,vector<int>& coins, int amount);

int getMaxStu(vector<vector<bool>> seat,vector<unordered_map<long long,int>> & caches,int m,int n);

bool getSubState(int i,int j,const vector<vector<bool>> & dp);
#endif