#include "Game.h"
#ifdef _MSC_VER
#pragma comment (lib, "ArtemisCpp.lib")
#endif
#include "boost/graph/graph_traits.hpp"
#include "boost/graph/adjacency_list.hpp"
#include "boost/graph/depth_first_search.hpp"
#include "boost/graph/astar_search.hpp"
#include "Room.h"
#include <vector>

struct Edge {};
typedef boost::adjacency_list<boost::listS, boost::vecS, boost::undirectedS, Room, Edge> MyGraph;
typedef boost::graph_traits<MyGraph>::vertex_descriptor MyVertex;

typedef MyGraph::vertex_descriptor VertexID;
typedef MyGraph::edge_descriptor   EdgeID;

class MyVisitor : public boost::default_dfs_visitor
{
public:
	void discover_vertex(MyVertex v, const MyGraph& g) const
	{
		std::cerr << v << std::endl;
		return;
	}
};

int main()
{
	MyGraph g;
	std::vector<VertexID> ids;
	for (int i = 0; i < 4; i++)
	{
		VertexID vID = boost::add_vertex(g);
		ids.push_back(vID);
		g[vID].setName("name" + i);
	}
	EdgeID edge;
	bool ok;
	boost::tie(edge, ok) = boost::add_edge(ids[0], ids[1], g); 
	boost::tie(edge, ok) = boost::add_edge(ids[1], ids[3], g);
	boost::tie(edge, ok) = boost::add_edge(ids[2], ids[3], g);
	boost::tie(edge, ok) = boost::add_edge(ids[3], ids[0], g);
}
/*
int main()
{
	//Game* game = new Game();
	//game->play();


	
	//create an -undirected- graph type, using vectors as the underlying containers
	//and an adjacency_list as the basic representation
	


	//Our set of edges, which basically are just converted into ints (0-4)
	enum { A, B, C, D, E, N };
	const char *name = "ABCDE";

	//An edge is just a connection between two vertitices. Our verticies above
	//are an enum, and are just used as integers, so our edges just become
	//a std::pair<int, int>
	typedef std::pair<int, int> Edge;
}*/