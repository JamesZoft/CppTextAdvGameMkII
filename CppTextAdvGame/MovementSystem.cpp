#include "MovementSystem.h"
#include "Artemis\Entity.h"
#include "Artemis\ComponentType.h"

#include <iostream>
#include <utility>
#include <algorithm>
#include <vector>

#include "boost/graph/graph_traits.hpp"
#include "boost/graph/adjacency_list.hpp"

MovementSystem::MovementSystem()
{
	addComponentType<PositionComponent>();
	using namespace boost;
	//create an -undirected- graph type, using vectors as the underlying containers
	//and an adjacency_list as the basic representation
	typedef adjacency_list<vecS, vecS, undirectedS> UndirectedGraph;
	typedef boost::graph_traits<UndirectedGraph>::vertex_descriptor MyVertex;


	//Our set of edges, which basically are just converted into ints (0-4)
	enum { A, B, C, D, E, N };
	const char *name = "ABCDE";

	//An edge is just a connection between two vertitices. Our verticies above
	//are an enum, and are just used as integers, so our edges just become
	//a std::pair<int, int>
	typedef std::pair<int, int> Edge;
}

void MovementSystem::processEntity(artemis::Entity &e)
{
	PositionComponent &currPos = *currPosMapper.get(e);
	PositionComponent &nextPos = *nextPosMapper.get(e);
	if (currPos.uniqueRoomId != nullptr && nextPos.uniqueRoomId != nullptr)
	{
		moveEntity(e, currPos, nextPos);
	}
}

bool MovementSystem::moveEntity(artemis::Entity &e, PositionComponent &currPos, PositionComponent &nextPos)
{
	//if (roomGraph.pointsAreDirectlyConnected(currPos, nextPos))
	//{
	//	e.removeComponent<PositionComponent>();
	//	e.addComponent(&nextPos);
	//}
	return false;
}