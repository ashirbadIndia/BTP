#include "mcpm_graph.h"

MCPM_GRAPH::MCPM_GRAPH(int n, const list< pair<int, int> > & edges):
	n(n),
	m(edges.size()),
	adjMat(n, vector<bool>(n, false)),
	adjList(n),
	edges(),
	edgeIndex(n, vector<int>(n, -1))
{
	for(list< pair<int, int> >::const_iterator it = edges.begin(); it != edges.end(); it++)
	{
		int u = (*it).first;
		int v = (*it).second;

		AddEdge(u, v);
	}
}

pair<int, int> MCPM_GRAPH::GetEdge(int e) const
{
	if(e > (int)edges.size())
		throw "Error: edge does not exist";

	return edges[e];
}

int MCPM_GRAPH::GetEdgeIndex(int u, int v) const
{
	if( u > n or
		v > n )
		throw "Error: vertex does not exist";

	if(edgeIndex[u][v] == -1)
		throw "Error: edge does not exist";

	return edgeIndex[u][v];
}

void MCPM_GRAPH::AddVertex()
{
	for(int i = 0; i < n; i++)
	{
		adjMat[i].push_back(false);
		edgeIndex[i].push_back(-1);
	}
	n++;
	adjMat.push_back( vector<bool>(n, false) );
	edgeIndex.push_back( vector<int>(n, -1) );
	adjList.push_back( list<int>() );
}

void MCPM_GRAPH::AddEdge(int u, int v)
{
	if( u > n or
		v > n )
		throw "Error: vertex does not exist";

	if(adjMat[u][v]) return;

	adjMat[u][v] = adjMat[v][u] = true;
	adjList[u].push_back(v);
	adjList[v].push_back(u);

	edges.push_back(pair<int, int>(u, v));
	edgeIndex[u][v] = edgeIndex[v][u] = m++;
}

const list<int> & MCPM_GRAPH::AdjList(int v) const
{
	if(v > n)
		throw "Error: vertex does not exist";

	return adjList[v];
}

const vector< vector<bool> > & MCPM_GRAPH::AdjMat() const
{
	return adjMat;
}

