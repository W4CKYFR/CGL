#include "cgl_physics.hpp"
#include <box2d/box2d.h>
#include <math.h>

constexpr float PIXELS_PER_METER = 100.0f;

namespace cgl {
	Physics::World::World() {
		b2WorldDef worldDef = b2DefaultWorldDef();

		worldId = b2CreateWorld(&worldDef);
	}

	void Physics::World::SetGravity(float x, float y) {
		b2World_SetGravity(worldId, { x ,y });
	}

	void Physics::World::PhysicsUpdate() {
		float timeStep = 1.0f / 60.0f;
		int subSteps = 4;

		b2World_Step(worldId, timeStep, subSteps);
	}

	Physics::Ground::Ground() {}

	void Physics::Ground::Create(World& world, float x, float y, float w, float h) {
		b2BodyDef def = b2DefaultBodyDef();
		def.position = { x, y };
		def.type = b2_staticBody;

		groundId = b2CreateBody(world.GetWorldID(), &def);

		b2Polygon box = b2MakeBox(w, h);
		b2ShapeDef shapeDef = b2DefaultShapeDef();
		b2CreatePolygonShape(groundId, &shapeDef, &box);
	}

	void Physics::Ground::MakeGroundRectangle(World& world, cgl::Shape::Rectangle& rect) {
		auto points = rect.GetPoints();
		b2Polygon poly; 
		poly.vertices[0] = { points[0].x, points[0].y };
		poly.vertices[1] = { points[1].x, points[1].y };
		poly.vertices[2] = { points[2].x, points[2].y };
		poly.vertices[3] = { points[3].x, points[3].y };
		poly.count = 4;

		b2BodyDef def = b2DefaultBodyDef();
		def.type = b2_staticBody;
		def.position = { 0, 0 };

		groundId = b2CreateBody(world.GetWorldID(), &def);

		b2ShapeDef shapeDef = b2DefaultShapeDef();
		b2CreatePolygonShape(groundId, &shapeDef, &poly);
	}

	void Physics::Ground::MakeGroundTriangle(World& world, cgl::Shape::Triangle& tri) {
		auto points = tri.GetPoints();
		b2Polygon poly;
		poly.vertices[0] = { points[0].x, points[0].y };
		poly.vertices[1] = { points[1].x, points[1].y };
		poly.vertices[2] = { points[2].x, points[2].y };
		poly.count = 3;

		b2BodyDef def = b2DefaultBodyDef();
		def.type = b2_staticBody;
		def.position = { 0, 0 };

		groundId = b2CreateBody(world.GetWorldID(), &def);

		b2ShapeDef shapeDef = b2DefaultShapeDef();
		b2CreatePolygonShape(groundId, &shapeDef, &poly);
	}

	void Physics::Ground::MakeGroundCircle(World& world, cgl::Shape::Circle& circ) {
		b2BodyDef def = b2DefaultBodyDef();
		def.type = b2_staticBody;
		def.position = { (float)circ.GetCenterX(), (float)circ.GetCenterY() };

		groundId = b2CreateBody(world.GetWorldID(), &def);

		b2Circle circle;
		circle.radius = (float)circ.GetRadius();

		b2ShapeDef shapeDef = b2DefaultShapeDef();
		b2CreateCircleShape(groundId, &shapeDef, &circle);
	}

	void Physics::Ground::SetPosition(World& world, Ground& ground, float x, float y) {
		b2Transform xf = b2Body_GetTransform(ground.groundId); 
		xf.p.x = x; 
		xf.p.y = y;

		b2Body_SetTransform(ground.groundId, xf.p, xf.q); 
	}

	Physics::Body::Body() {}

	void Physics::Body::MakeDynamicRectangle(World& world, cgl::Shape::Rectangle& rect, float density, float friction, int restitution) {
		auto points = rect.GetPoints();
		auto center = rect.GetCenter();

		b2Polygon poly;
		for (int i = 0; i < 4; i++) {
			poly.vertices[i] = { (points[i].x - center.x) / PIXELS_PER_METER, (points[i].y - center.y) / PIXELS_PER_METER };
		}
		poly.count = 4;

		b2BodyDef def = b2DefaultBodyDef();
		def.type = b2_dynamicBody;
		def.position = { center.x / PIXELS_PER_METER, center.y / PIXELS_PER_METER };

		bodyId = b2CreateBody(world.GetWorldID(), &def);

		b2ShapeDef shapeDef = b2DefaultShapeDef();
		shapeDef.density = density;
		shapeDef.material.friction = friction;
		shapeDef.material.restitution = restitution;

		b2CreatePolygonShape(bodyId, &shapeDef, &poly);
	}


	void Physics::Body::MakeDynamicTriangle(World& world, cgl::Shape::Triangle& tri, float density, float friction, int restitution) {
		auto points = tri.GetPoints();

		b2Polygon poly;
		for (int i = 0; i < 3; i++) {
			poly.vertices[i] = { points[i].x / PIXELS_PER_METER, points[i].y / PIXELS_PER_METER };
		}

		auto center = tri.GetCenter();
		b2BodyDef def = b2DefaultBodyDef();
		def.type = b2_dynamicBody;
		def.position = { center.x / PIXELS_PER_METER, center.y / PIXELS_PER_METER };

		bodyId = b2CreateBody(world.GetWorldID(), &def);

		b2ShapeDef shapeDef = b2DefaultShapeDef();
		shapeDef.density = density;
		shapeDef.material.friction = friction;
		shapeDef.material.restitution = restitution;
		b2CreatePolygonShape(bodyId, &shapeDef, &poly);
	}

	void Physics::Body::MakeDynamicCircle(World& world, cgl::Shape::Circle& circ, float density, float friction, int restitution) {
		float x = circ.GetCenterX() / PIXELS_PER_METER;
		float y = circ.GetCenterY() / PIXELS_PER_METER;
		float r = circ.GetRadius() / PIXELS_PER_METER;

		b2Circle circleShape;
		circleShape.radius = r;

		b2BodyDef def = b2DefaultBodyDef();
		def.type = b2_dynamicBody;
		def.position = { x, y };

		bodyId = b2CreateBody(world.GetWorldID(), &def);

		b2ShapeDef shapeDef = b2DefaultShapeDef();
		shapeDef.density = density;
		shapeDef.material.friction = friction;
		shapeDef.material.restitution = restitution;

		b2CreateCircleShape(bodyId, &shapeDef, &circleShape);
	}
}