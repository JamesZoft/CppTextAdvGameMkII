#pragma once
#include "Artemis\EntityProcessingSystem.h"
#include "Artemis\ComponentMapper.h"
#include "PositionComponent.h"
#include <map>
#include <vector>
#include "Room.h"
#include "boost/graph/graph_traits.hpp"
#include "boost/graph/adjacency_list.hpp"

struct Edge {};
typedef boost::adjacency_list<boost::listS, boost::vecS, boost::undirectedS, PositionComponent, Edge> MyGraph;

class MovementSystem : public artemis::EntityProcessingSystem
{
	private:
		artemis::ComponentMapper<PositionComponent> currPosMapper;
		artemis::ComponentMapper<PositionComponent> nextPosMapper;
		
		bool pointsAreAdjacent(PositionComponent*, PositionComponent*);
		MyGraph roomGraph;
		std::vector<Room*> rooms;
	public:
		MovementSystem();
		std::vector<PositionComponent*> getAdjacentPositions(PositionComponent*);
		bool moveEntity(artemis::Entity* e, PositionComponent* nextPos);
		PositionComponent* getPositionComponentWithId(const int id);
		std::vector<Room*> getRoomList();
		virtual void initialize() {
			currPosMapper.init(*world);
			nextPosMapper.init(*world);
		};
		
		void processEntity(artemis::Entity* e);
};

