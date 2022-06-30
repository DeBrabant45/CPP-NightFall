#include "HeroRigidbody.h"
#include "../../Transform/Transformation.h"
#include "../../Character/CharacterType.h"

HeroRigidbody::HeroRigidbody(std::shared_ptr<GameObject> owner, std::shared_ptr<b2World> world) :
	Rigidbody(owner, world)
{

}

void HeroRigidbody::Start()
{
	auto transform = Owner->GetComponent<Transformation>();
	CreateDefinition(transform->GetPosition());
	AddToWorld();
	CreateShape(transform->GetSize());
	CreateFixtureDefinition((uintptr_t)CharacterType::Hero);
}

void HeroRigidbody::CreateDefinition(Vector2 position)
{
	BodyType = b2_dynamicBody;
	BodyDefinition.type = BodyType;
	BodyDefinition.position.Set(position.x, position.y);
	BodyDefinition.fixedRotation = true;
}

void HeroRigidbody::CreateShape(Vector2 size)
{
	Shape.SetAsBox(size.x / 2.f, size.y / 2.f);
}

void HeroRigidbody::CreateFixtureDefinition(uintptr_t userData)
{
	b2FixtureDef fixtureDefinition;
	fixtureDefinition.shape = &Shape;
	fixtureDefinition.density = 1.f;
	fixtureDefinition.friction = 8.f;
	fixtureDefinition.userData.pointer = userData;
	Body->CreateFixture(&fixtureDefinition);
}

void HeroRigidbody::Update(const float& deltaTime)
{

}