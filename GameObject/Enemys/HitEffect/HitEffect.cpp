#include "HitEffect.h"

void HitEnemyEffect::Init() {

  // 4
  int random = RandomGenerator::GetInt(0, 3);
  EffectModelSelector(random);
}

void HitEnemyEffect::Update() {}

void HitEnemyEffect::EffectModelSelector(const int &num) {

  filePathMap_[EffectName::Sokai_Jp] = {"Resources/Model/Enemy/Effect/sokaiJp",
                                        "sokaiJp"};
  filePathMap_[EffectName::sokai] = {"Resources/Model/Enemy/Effect/sokai",
                                        "sokai"};
  filePathMap_[EffectName::Miwaku] = {"Resources/Model/Enemy/Effect/miwaku",
                                        "miwaku"};
  filePathMap_[EffectName::NamaAsi] = {"Resources/Model/Enemy/Effect/NAMAasi",
                                        "NAMAasi"};

  //auto path = filePathMap_[static_cast<EffectName>(num)];
  auto path = filePathMap_[EffectName::Miwaku];

  uint32_t modelHandle = modelManager_->LoadModel(
      path.directory_, path.name_);
  this->SetModelHandle(modelHandle);

}
