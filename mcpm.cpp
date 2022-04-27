#include "matching.h"
#include "mcpm_graph.h"
#include "graph.h"
#include "mcpm.h"
#include <bits/stdc++.h>
using namespace std;

pair<MCPM_GRAPH, vector<double> > CreateRandomGraph()
{
	//random seed
	int x;
	cin >> x;
	srand( x );

	int n = 50;

	MCPM_GRAPH G(n);
	vector<double> cost;
	for(int i = 0; i < n; i++)
		for(int j = i+1; j < n; j++)
			if(rand()%10 == 0)
			{
				G.AddEdge(i, j);
				cost.push_back(rand()%1000);
			}

	return make_pair(G, cost);
}



pair<MCPM_GRAPH, vector<double> > ReadWeightedGraph(int n,vector<vector<float>> conf)
{
	int m = conf.size();
	MCPM_GRAPH G(n);
	vector<double> cost(m);
	for(int i = 0; i < m; i++)
	{
		int u = (int)conf[i][0], v=(int)conf[i][1];
		double c=conf[i][2];

		G.AddEdge(u, v);
		cost[G.GetEdgeIndex(u, v)] = c;
	}

	return make_pair(G, cost);
}

vector<vector<int>> MinimumCostPerfectMatchingExecution(int n,vector<vector<float>> &conf,vector<int> &odd_vertices)
{
	MCPM_GRAPH G;
	vector<double> cost;
	
	//Read the graph
	pair<MCPM_GRAPH, vector<double> > p = ReadWeightedGraph(n,conf);
	G = p.first;
	cost = p.second;

	//Create a Matching instance passing the graph
	Matching M(G);

	//Pass the costs to solve the problem
	pair< list<int>, double > solution = M.SolveMinimumCostPerfectMatching(cost);

	list<int> match_list = solution.first;
	double obj = solution.second;

	cout << "Optimal matching cost: " << obj << endl;
	//cout << "Edges in the matching:" << endl;

	vector<vector<int>> matching(n/2,vector<int>(2,0));
	int i=0;
	for(list<int>::iterator it = match_list.begin(); it != match_list.end(); it++)
	{
		pair<int, int> e = G.GetEdge( *it );
		matching[i][0] = odd_vertices[e.first], matching[i][1]=odd_vertices[e.second];
		//cout << e.first << " " << e.second << endl;
		i++;
	}
	return matching;
}


/*int main(int argc, char* argv[])
{
	vector<vector<float>> conf = {
								{0,1,2.236},
								{0,2,3.6},
								{0,3,3},
								{1,2,1.414},
								{1,3,1.414},
								{2,3,2}};

	try
	{
		MinimumCostPerfectMatchingExecution(4,conf);
	}
	catch(const char * msg)
	{
		cout << msg << endl;
		return 1;
	}

	return 0;
}*/


vector<vector<int>> MinimumCostPerfectMatching(Graph &G, vector<int> odd_vertices)
{
	int n = odd_vertices.size(), m = (n*(n-1))/2;
	vector<vector<float>> config(m,vector<float>(3,0));
	int l = 0;
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			config[l][0]=i;
			config[l][1]=j;
			float x1 = G.vertices[odd_vertices[i]].x, y1 = G.vertices[odd_vertices[i]].y;
			float x2 = G.vertices[odd_vertices[j]].x, y2 = G.vertices[odd_vertices[j]].y;
			//cout<<x1<<" "<<y1<<" "<<x2<<" "<<y2<<" "<<endl;
			config[l][2]=G.dist(x1,y1,x2,y2);
			l++;
		}
	}
	vector<vector<int>> matching = MinimumCostPerfectMatchingExecution(n,config,odd_vertices);

	for(int i=0;i<matching.size();i++){
		cout<<matching[i][0]<<" "<<matching[i][1]<<endl;
	}
	return matching;
}



