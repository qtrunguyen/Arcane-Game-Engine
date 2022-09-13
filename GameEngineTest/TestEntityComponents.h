#pragma once
#include "Test.h"
#include "..\GameEngine\Components\Entity.h"
#include "..\GameEngine\Components\Transform.h"

#include <iostream>
#include <ctime>

using namespace arcane;

class EngineTest : public Test {
public:
	bool initialize() override {
		srand((u32)time(nullptr));
		return true;
	}
	void run() override {
		do {
			for (u32 i{ 0 }; i < 10000; ++i) {
				//CreateRandomEntities();
				//RemoveRandomEntities();
				_num_entities = (u32)_entities.size();
			}
			PrintResults();
		} while (getchar() != 'q');
	}
	void shutdown() override {

	}
private:
	void CreateRandomEntities() {
		u32 count = rand() % 20;
		if (_entities.empty()) count = 1000;
		transform::InitInfo transform_info{};
		game_entity::EntityInfo entity_info{
			&transform_info
		};
		while (count > 0) {
			++_added;
			game_entity::Entity entity{ game_entity::CreateGameEntity(entity_info) };
			assert(entity.IsValid() && id::IsValid(entity.GetId()));
			_entities.push_back(entity);
			assert(game_entity::IsAlive(entity));
			--count;
		}
	}

	void RemoveRandomEntities() {
		u32 count = rand() % 20;
		if (_entities.size() < 1000) return;
		while (count > 0) {
			const u32 index{ (u32)rand() % (u32)_entities.size() };
			const game_entity::Entity entity{ _entities[index] };
			assert(entity.IsValid() && id::IsValid(entity.GetId()));
			if (entity.IsValid()) {
				game_entity::RemoveGameEntity(entity);
				_entities.erase(_entities.begin() + index);
				assert(!game_entity::IsAlive(entity));
				++_removed;
			}
			--count;
		}
	}

	void PrintResults() {
		std::cout << "Entities added: " << _added << "\n";
		std::cout << "Entites removed " << _removed << "\n";
	}

	utl::vector<game_entity::Entity> _entities;
	u32 _added{ 0 };
	u32 _removed{ 0 };
	u32 _num_entities{ 0 };
};