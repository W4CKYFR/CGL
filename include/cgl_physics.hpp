#pragma once
#include <box2d/box2d.h>
#include "cgl_shape.hpp"

namespace cgl {
	class Physics {
	public:
		class World {
		public:
			World();

			void SetGravity(float x, float y);
			b2WorldId GetWorldID() const { return worldId; }
			
			void PhysicsUpdate();
		private:
			b2WorldId worldId = b2_nullWorldId;
		};
		class Ground {
		public:
			Ground();

			void Create(World& world, float x, float y, float w, float h);
			void MakeGroundRectangle(World& world, cgl::Shape::Rectangle& rect);
			void MakeGroundTriangle(World& world, cgl::Shape::Triangle& tri);
			void MakeGroundCircle(World& world, cgl::Shape::Circle& circ);
			void SetPosition(cgl::Physics::World& world, cgl::Physics::Ground& ground, float x, float y);
			b2BodyId GetGroundId() const { return groundId; }
		private:
			b2BodyId groundId = b2_nullBodyId;
		};
		class Body {
		public:
			Body();

			void MakeDynamicRectangle(World& world, cgl::Shape::Rectangle& rect, float density, float friction, int restitution);
			void MakeDynamicTriangle(World& world, cgl::Shape::Triangle& tri, float density, float friction, int restitution);
			void MakeDynamicCircle(World& world, cgl::Shape::Circle& circ, float density, float friction, int restitution);
			b2BodyId GetBodyId() const { return bodyId;  }
		private:
			b2BodyId bodyId = b2_nullBodyId;
		};
	};
}
