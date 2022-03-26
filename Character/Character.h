#pragma once
#ifndef CHARACTER_H
#define CHARACTER_H
#include <memory>
#include <vector>
#include "../GameObject/IGameObject.h"
#include "ICharacterComponent.h"
#include "CharacterState.h"

class ICharacterComponent;

class Character : public IGameObject
{

private:
	std::vector<std::shared_ptr<ICharacterComponent>> _components{};
	CharacterState _currentState{ CharacterState::Idle };
	Vector2 _worldPosition{ 0.f, 0.f };
	float _lookDirection{ 1.f };

public:
	Vector2 Velocity{ 0.f, 0.f };
	bool IsGrounded{ false };

private:
	void SetState();
	void SetLookDirection();

public:
	Character(std::vector<std::shared_ptr<ICharacterComponent>> components);
	virtual void Update(const float& deltaTime) override;
	virtual const Vector2& GetPosition() override { return _worldPosition; }
	void SetWorldPosition(Vector2& position);
	float GetLookDirection() const { return _lookDirection; }
	CharacterState GetCurrentState() const { return _currentState; }
};
#endif