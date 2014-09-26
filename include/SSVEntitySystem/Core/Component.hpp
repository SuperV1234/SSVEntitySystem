// Copyright (c) 2013-2014 Vittorio Romeo
// License: Academic Free License ("AFL") v. 3.0
// AFL License page: http://opensource.org/licenses/AFL-3.0

#ifndef SSES_COMPONENT
#define SSES_COMPONENT

namespace sses
{
	class Component
	{
		friend Entity;

		private:
			Entity* entity{nullptr};

			inline virtual void update(FT) { }
			inline virtual void draw() { }

		public:
			inline Component() noexcept = default;

			inline Component(const Component&) = delete;
			inline Component& operator=(const Component&) = delete;

			inline virtual ~Component() { }

			inline auto& getEntity() const noexcept
			{
				SSVU_ASSERT(entity != nullptr);
				return *entity;
			}
			inline auto& getManager() const noexcept;
	};
}

#endif
