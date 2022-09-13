#include "Entity.h"
#include "Transform.h"
namespace arcane::game_entity {
	
	namespace { 
		utl::vector<transform::Component> tranforms;
		utl::vector<id::generation_type> generations;
		utl::deque<EntityId> free_ids;
	}

	Entity CreateGameEntity(const EntityInfo& info) {
		assert(info.Transform); //Make sure that all entities has transform component
		if (!info.Transform) return Entity{};

		EntityId id;
		if (free_ids.size() > id::min_deleted_elements) {
			id = free_ids.front();
			assert(!IsAlive(Entity{ id }));
			free_ids.pop_front();
			id = EntityId{ id::generation_type(id) };
			++generations[id::Index(id)];
		}
		else {
			id = EntityId{ (id::id_type)generations.size() };
			generations.push_back(0);

			//Resize component
			//Using emplace_back() instead of resize() to keep the number of memory allocations stay low
			tranforms.emplace_back();
		}
		const Entity new_entity{ id };
		const id::id_type index{ id::Index(id) };
		
		//Create transform component
		assert(!tranforms[index].IsValid());
		tranforms[index] = transform::CreateTranform(*info.Transform, new_entity);

		return new_entity;
	}
	void RemoveGameEntity(Entity e) {
		const EntityId id{ e.GetId() };
		const id::id_type index{ id::Index(id) };
		assert(IsAlive(e));
		if (IsAlive(e)) {
			transform::RemoveTransform(tranforms[index]);
			tranforms[index] = {};
			free_ids.push_back(id);
		}
	}
	bool IsAlive(Entity e) {
		assert(e.IsValid());
		const EntityId id{ e.GetId() };
		const id::id_type index{ id::Index(id) };
		assert(index < generations.size());
		assert(generations[index] == id::Generation(id));
		return(generations[index] == id::Generation(id)) && tranforms[index].IsValid();
	}

	transform::Component Entity::Transform() const {
		assert(IsAlive(*this));
		const id::id_type index{ id::Index(_id) };
		return tranforms[index];
	}

}