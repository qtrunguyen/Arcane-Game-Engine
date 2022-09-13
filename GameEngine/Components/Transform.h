#pragma once
#include "ComponentsCommon.h"

namespace arcane::transform {

	struct InitInfo {
		f32 position[3]{};
		f32 rotation[4]{};
		f32 scale[3]{1.f, 1.f, 1.f};
	};
	Component CreateTranform(const InitInfo& info, game_entity::Entity entity);
	void RemoveTransform(Component c);
}