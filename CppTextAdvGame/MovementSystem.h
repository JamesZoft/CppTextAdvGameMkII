#pragma once
#include "Artemis\EntityProcessingSystem.h"
#include "Artemis\ComponentMapper.h"
#include "PositionComponent.h"
#include "MovementComponent.h"
#include <map>
#include <vector>
#include "Room.h"
#include "boost/graph/graph_traits.hpp"
#include "InputMovementComponent.h"
#include "boost/graph/adjacency_list.hpp"
#include "Message.h"

struct Edge {};
typedef boost::adjacency_list<boost::listS, boost::vecS, boost::undirectedS, PositionComponent, Edge> MyGraph;

class MovementSystem : public artemis::EntityProcessingSystem
{
	private:
		artemis::ComponentMapper<PositionComponent> currPosMapper;
		artemis::ComponentMapper<InputMovementComponent> inputMapper;
		
		bool pointsAreAdjacent(PositionComponent*, PositionComponent*);
		MyGraph roomGraph;
		std::vector<Room*> rooms;
	public:
		MovementSystem() {
			addComponentType<MovementComponent>();
			addComponentType<InputMovementComponent>();
		};
		void processEntity(artemis::Entity &e);
		void processEntities(artemis::ImmutableBag<artemis::Entity*> & bag);
		bool checkProcessing();
		void initialize() {
			currPosMapper.init(*world);
			inputMapper.init(*world);
		};
		std::vector<PositionComponent*> getAdjacentPositions(PositionComponent*);
		bool moveEntity(artemis::Entity* e, PositionComponent* nextPos);
		PositionComponent* getPositionComponentWithId(const int id);
		std::vector<Room*> getRoomList();
		Message* listAvailablePositions(artemis::Entity&);
		
		
};

