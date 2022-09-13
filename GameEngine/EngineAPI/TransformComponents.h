#pragma once

#include "..\Components\ComponentsCommon.h"
namespace arcane::transform {

	DEFINE_TYPED_ID(TransformId);

	class Component final {
	public:
		constexpr explicit Component(TransformId id) : _id{ id } {}
		constexpr Component() : _id{ id::invalid_id } {}
		constexpr TransformId GetId() const { return _id; }
		constexpr bool IsValid() const { return id::IsValid(_id); }

		math::v4 rotation() const;
		math::v3 position() const;
		math::v3 scale() const;
	private:
		TransformId _id;
	};
}