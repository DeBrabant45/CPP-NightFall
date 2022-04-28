#include "Level.h"
#include <raymath.h>
#include <iostream>
#include <box2d/box2d.h>
#include "../Ground/GroundType.h"
#include "../Component/IComponent.h"
#include "../Character/CharacterType.h"

Level::Level()
{
	_world = std::make_shared<b2World>(b2Vec2(0.f, 129.8f));
	_hero = _characterFactory.Create(CharacterType::Hero, _world, Vector2{ 100.f, 266.f });
	_hellHound = _characterFactory.Create(CharacterType::Hellhound, _world, Vector2{ 200.f, 266.f });
	_grounds =
	{
		_groundFactory.Create(GroundType::Hazard, _world, Vector2{ 600.f, 41.f }, Vector2{ 0.f, 300.f}),
		_groundFactory.Create(GroundType::Walkable, _world, Vector2{ 300.f, 41.f }, Vector2{ 190.f, 300.f}),
		_groundFactory.Create(GroundType::Hazard, _world, Vector2{ 100.f, 41.f }, Vector2{ 390.f, 300.f}),
		_groundFactory.Create(GroundType::Walkable, _world, Vector2{ 300.f, 41.f }, Vector2{ 590.f, 300.f}),
	};
}

void Level::Start()
{
	_hero->Start();
	_hellHound->Start();
	for (auto ground : _grounds)
	{
		ground->Start();
	}
	_mainCamera.SetTarget(_hero);
}

void Level::Update(const float& deltaTime)
{
	_world->Step(deltaTime, 8, 2);
	_mainCamera.Update(deltaTime);
	BeginMode2D(_mainCamera.GetCamera());
	DrawMapToWorld();
	for (auto ground : _grounds)
	{
		ground->Update(deltaTime);
	}
	_hero->Update(deltaTime);
	_hellHound->Update(deltaTime);
	DrawRectangle(0.f, 320.f, 5000.f, 60.f, BLACK);
	EndMode2D();
}

void Level::DrawMapToWorld()
{
	DrawTextureEx(_texture, _worldPosition, 0.0f, _scale, WHITE);
}