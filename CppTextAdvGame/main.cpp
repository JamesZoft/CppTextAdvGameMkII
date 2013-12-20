#include "Game.h"
#ifdef _MSC_VER
#pragma comment (lib, "ArtemisCpp.lib")
#endif
#include "boost/graph/graph_traits.hpp"
#include "boost/graph/adjacency_list.hpp"
#include "boost/graph/depth_first_search.hpp"

typedef boost::adjacency_list<boost::listS, boost::vecS, boost::undirectedS> MyGraph;
typedef boost::graph_traits<MyGraph>::vertex_descriptor MyVertex;

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
	boost::add_edge(0, 1, g);
	boost::add_edge(0, 2, g);
	boost::add_edge(1, 2, g);
	boost::add_edge(1, 3, g);
	MyVisitor vis;
	MyGraph::adjacency_iterator neighbourIt, neighbourEnd;
	boost::tie(neighbourIt, neighbourEnd) = boost::adjacent_vertices(1, g);
	for (; neighbourIt != neighbourEnd; ++neighbourIt){
		auto vertexID = *neighbourIt; // dereference vertexIt, get the ID
		MyVertex & vertex = g[vertexID];
		std::cout << vertexID << std::endl;
	}
	std::string s;
	std::cin >> s;
	return 0;
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