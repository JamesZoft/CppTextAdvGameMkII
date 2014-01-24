#include "MovementSystem.h"
#include "Artemis\Entity.h"
#include "Artemis\ComponentType.h"

#include "Console.h"
#include <iostream>
#include <utility>
#include "cpp-utils-master\stringutils.hpp"
#include <algorithm>
#include <vector>
#include "Message.h"

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


void MovementSystem::processEntity(artemis::Entity& e)
{
	std::string input = inputMapper.get(e)->getInput();

	if (inputMapper.get(e) != nullptr)
	{
		PositionComponent* nextPos = getPositionComponentWithId(inputMapper.get(e)->getInput());
		moveEntity(&e, nextPos);
	}
	else //The entity is not moveable via input
	{
		//Get the position that the AI computation has decided the NPC will be if/when npc movement is implemented
	}
	
}

Message* MovementSystem::listAvailablePositions(artemis::Entity &player)
{
	auto adjPositions = getAdjacentPositions(player.getComponent<PositionComponent>());
	Message* m = new Message();
	for (auto pc : adjPositions)
	{
		m->message += "- " + util::string::from<int>(pc->getUniqueRoomId()) + "\n";
	}
	return m;
}

void MovementSystem::processEntities(artemis::ImmutableBag<artemis::Entity*> & bag)
{
	for (int i = 0; i < bag.getCount; i++)
	{
		processEntity(*bag.get(i));
	}
}

bool MovementSystem::checkProcessing()
{
	return true;
}

bool MovementSystem::moveEntity(artemis::Entity* e, PositionComponent* nextPos)
{
	if (pointsAreAdjacent(e->getComponent<PositionComponent>(), nextPos))
	{
		e->removeComponent<PositionComponent>();
		e->addComponent(nextPos);
	}
	return false;
}

std::vector<Room*> MovementSystem::getRoomList()
{
	return rooms;
}

PositionComponent* MovementSystem::getPositionComponentWithId(const int id)
{
	MyGraph::vertex_iterator vertexIt, vertexEnd;
	boost::tie(vertexIt, vertexEnd) = boost::vertices(roomGraph);
	VertexID vertexID;
	for (; vertexIt != vertexEnd; ++vertexIt){
		vertexID = *vertexIt; // dereference vertexIt, get the ID
		PositionComponent* vertex = &(roomGraph[vertexID]);
		if ((*vertex).getUniqueRoomId() == id){
			return vertex;
		} // Gotcha
	}
	return nullptr;
}

std::vector<PositionComponent*> MovementSystem::getAdjacentPositions(PositionComponent* pc)
{
	MyGraph::vertex_iterator vertexIt, vertexEnd;
	boost::tie(vertexIt, vertexEnd) = boost::vertices(roomGraph);
	VertexID vertexID;
	for (; vertexIt != vertexEnd; ++vertexIt){
		vertexID = *vertexIt; // dereference vertexIt, get the ID
		PositionComponent & vertex = roomGraph[vertexID];
		if (vertex.getUniqueRoomId() == pc->getUniqueRoomId()){
			break;
		} // Gotcha
	}

	std::vector<PositionComponent*> adjPositions;

	MyGraph::adjacency_iterator neighbourIt, neighbourEnd;
	boost::tie(neighbourIt, neighbourEnd) = boost::adjacent_vertices(vertexID, roomGraph);
	for (; neighbourIt != neighbourEnd; ++neighbourIt){
		VertexID vertexID = *neighbourIt; // dereference vertexIt, get the ID
		PositionComponent & vertex = roomGraph[vertexID];
		adjPositions.push_back(&vertex);
	}
	return adjPositions;
}

bool MovementSystem::pointsAreAdjacent(PositionComponent* p1, PositionComponent* p2)
{
	std::vector<PositionComponent*> adjacentRooms = getAdjacentPositions(p1);
	for (PositionComponent* pc : adjacentRooms)
	{
		if (pc == p2)
			return true;
	}
	return false;
}
