#include "Transform.h"
#include "Entity.h"

namespace arcane::transform {
	namespace {
		utl::vector<math::v3> positions;
		utl::vector<math::v4> rotations;
		utl::vector<math::v3> scales;
	} //anonymous namespace

	Component CreateTranform(const InitInfo& info, game_entity::Entity entity) {
		assert(entity.IsValid());
		const id::id_type entity_index{ id::Index(entity.GetId()) };

		if (positions.size() > entity_index) {
			rotations[entity_index] = math::v4(info.rotation);
			positions[entity_index] = math::v3(info.position);
			scales[entity_index] = math::v3(info.scale);

		}
		else {
			assert(positions.size() == entity_index);
			rotations.emplace_back(info.rotation);
			positions.emplace_back(info.position);
			scales.emplace_back(info.scale);
		}

		return Component(TransformId{ (id::id_type)positions.size() - 1 });
	}
	void RemoveTransform(Component c) {
		assert(c.IsValid());
	}

	math::v4 Component::rotation() const {
		assert(IsValid());
		return rotations[id::Index(_id)];
	}
	math::v3 Component::position() const {
		assert(IsValid());
		return positions[id::Index(_id)];
	}
	math::v3 Component::scale() const {
		assert(IsValid());
		return scales[id::Index(_id)];
	}
}

