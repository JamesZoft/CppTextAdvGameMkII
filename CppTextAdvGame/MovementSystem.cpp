#include "MovementSystem.h"
#include "Artemis\Entity.h"
#include "Artemis\ComponentType.h"

#include <iostream>
#include <utility>
#include <algorithm>
#include <vector>

#include "boost/graph/adjacency_list.hpp"
#include "boost/graph/depth_first_search.hpp"
#include "Room.h"
#include <vector>

typedef boost::graph_traits<MyGraph>::vertex_descriptor MyVertex;

typedef MyGraph::vertex_descriptor VertexID;
typedef MyGraph::edge_descriptor EdgeID;

MovementSystem::MovementSystem()
{
	std::vector<VertexID> ids;
	for (int i = 0; i < 4; i++)
	{
		VertexID vID = boost::add_vertex(roomGraph);
		ids.push_back(vID);
	}
	EdgeID edge;
	bool ok;
	boost::tie(edge, ok) = boost::add_edge(ids[0], ids[1], roomGraph);
	boost::tie(edge, ok) = boost::add_edge(ids[1], ids[3], roomGraph);
	boost::tie(edge, ok) = boost::add_edge(ids[2], ids[3], roomGraph);
	boost::tie(edge, ok) = boost::add_edge(ids[3], ids[0], roomGraph);
}

void MovementSystem::processEntity(artemis::Entity &e)
{
	PositionComponent &currPos = *currPosMapper.get(e);
	PositionComponent &nextPos = *nextPosMapper.get(e);
	moveEntity(e, currPos, nextPos);
}

bool MovementSystem::moveEntity(artemis::Entity &e, const PositionComponent &nextPos)
{
	if (pointsAreAdjacent(e.getComponent<PositionComponent>(), nextPos))
	{
		e.removeComponent<PositionComponent>();
		e.addComponent(&nextPos);
	}
	return false;
}

std::vector<PositionComponent*> MovementSystem::getAdjacentPositions(int id)
{
	MyGraph::vertex_iterator vertexIt, vertexEnd;
	boost::tie(vertexIt, vertexEnd) = boost::vertices(roomGraph);
	VertexID vertexID;
	for (; vertexIt != vertexEnd; ++vertexIt){
		vertexID = *vertexIt; // dereference vertexIt, get the ID
		PositionComponent & vertex = roomGraph[vertexID];
		if (vertex.getUniqueRoomId() == id){
			break;
		} // Gotcha
	}

	std::vector<PositionComponent*> rooms;

	MyGraph::adjacency_iterator neighbourIt, neighbourEnd;
	boost::tie(neighbourIt, neighbourEnd) = boost::adjacent_vertices(vertexID, roomGraph);
	for (; neighbourIt != neighbourEnd; ++neighbourIt){
		VertexID vertexID = *neighbourIt; // dereference vertexIt, get the ID
		PositionComponent & vertex = roomGraph[vertexID];
		rooms.push_back(&vertex);
	}
	return rooms;
}

bool MovementSystem::pointsAreAdjacent(PositionComponent p1, PositionComponent p2)
{
	std::vector<PositionComponent*> adjacentRooms = getAdjacentPositions(p1.getUniqueRoomId());
	for (PositionComponent* pc : adjacentRooms)
	{
		if (*pc == p2)
			return true;
	}
	return false;
}
