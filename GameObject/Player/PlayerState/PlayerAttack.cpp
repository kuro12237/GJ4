#include "PlayerAttack.h"

void PlayerAttack::Init() {}

void PlayerAttack::Update(Player *ins) {
	//変更
ins->GetGameObject().lock()->ChangeModel(0);

}
