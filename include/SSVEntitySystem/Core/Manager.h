// Copyright (c) 2013 Vittorio Romeo
// License: Academic Free License ("AFL") v. 3.0
// AFL License page: http://opensource.org/licenses/AFL-3.0

#ifndef SSES_MANAGER
#define SSES_MANAGER

#include <string>
#include <vector>
#include <unordered_map>
#include <memory>
#include "SSVEntitySystem/Utils/Utils.h"
#include "SSVEntitySystem/Core/Component.h"
#include "SSVEntitySystem/Utils/Repository.h"
#include <google/dense_hash_set>

namespace sses
{
	class Entity;

	class Manager
	{
		friend class Entity;
		friend class Component;

		private:
			std::vector<std::unique_ptr<Entity>> entities;
			std::vector<Entity*> toAdd, toSort;
			std::unordered_map<std::string, std::vector<Entity*>> groupedEntities;

		public:
			Manager() = default;
			Manager(const Manager&) = delete; // non construction-copyable
			Manager& operator=(const Manager&) = delete; // non copyable

			void clear();
			void update(float mFrameTime);
			void draw();

			Entity& createEntity(const std::string& mId = "");

			// Getters
			inline std::vector<std::unique_ptr<Entity>>& getEntities()			{ return entities; }
			inline std::vector<Entity*>& getEntities(const std::string& mId)	{ return groupedEntities[mId]; }
			inline bool hasEntity(const std::string& mId)						{ return groupedEntities[mId].size() > 0; }
			inline unsigned int getEntityCount(const std::string& mId)			{ return groupedEntities[mId].size(); }
	};
}

#endif
