#pragma once
#include <memory>
#include "../../State/StateBase.h"
#include "../Combat/HeroAttackComponent.h"

class HeroGraphicsComponent;
class HeroAttackComponent;
class GameObject;

class HeroAttackState : public StateBase
{
private:
	std::shared_ptr<HeroGraphicsComponent> _graphics{};
	std::shared_ptr<HeroAttackComponent> _attack{};
	float _attackTimer{ 25.f };

public:
	HeroAttackState(std::shared_ptr<GameObject> owner, std::shared_ptr<StateController> _controller);
	virtual void Start() override;
	virtual void OnEnter() override;
	virtual void OnUpdate() override;
};