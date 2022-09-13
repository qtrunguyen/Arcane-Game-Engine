#pragma once
#include "..\Components\ComponentsCommon.h"
#include "TransformComponents.h"
namespace arcane::game_entity {
	DEFINE_TYPED_ID(EntityId);
	class Entity {
	public:
		constexpr explicit Entity(EntityId id) : _id{ id } {}
		constexpr Entity() : _id{ id::invalid_id }{}
		constexpr EntityId GetId() const { return _id; }
		constexpr bool IsValid() const {return id::IsValid(_id); }

		transform::Component Transform() const;
	private:
		EntityId _id;
	};
}