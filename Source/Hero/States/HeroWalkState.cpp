#include "HeroWalkState.h"
#include "../../State/StateController.h"
#include "../Graphics/HeroGraphicsComponent.h"
#include "../../Transform/Transformation.h"
#include "../Transitions/IdleTransition.h"
#include "../Actions/WalkAction.h"
#include "../Transitions/JumpTransition.h"
#include "../Transitions/AttackTransition.h"
#include "../Transitions/FallTransition.h"
#include "../Transitions/DeathTransition.h"

HeroWalkState::HeroWalkState(std::shared_ptr<GameObject> owner, std::shared_ptr<StateController> controller) :
	StateBase(owner, controller)
{
	AddAction(std::make_shared<WalkAction>(owner));
	AddTransition(std::make_shared<DeathTransition>(owner, controller));
	AddTransition(std::make_shared<IdleTransition>(owner, controller));
	AddTransition(std::make_shared<JumpTransition>(owner, controller));
	AddTransition(std::make_shared<AttackTransition>(owner, controller));
	AddTransition(std::make_shared<FallTransition>(owner, controller));
}

void HeroWalkState::Start()
{
	_graphics = Owner->GetComponent<HeroGraphicsComponent>();
	StateBase::Start();
}

void HeroWalkState::OnEnter()
{
	_graphics->SetGraphics(AnimationAction::Run);
}