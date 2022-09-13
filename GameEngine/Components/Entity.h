#pragma once
#include "ComponentsCommon.h"

namespace arcane {

	#define INIT_INFO(component) namespace component{ struct InitInfo; }
	INIT_INFO(transform);
	#undef INIT_INFO

	namespace game_entity {
		struct EntityInfo {
			transform::InitInfo* Transform{ nullptr };
		};

		Entity CreateGameEntity(const EntityInfo& info);
		void RemoveGameEntity(Entity id);
		bool IsAlive(Entity id);
	}
}