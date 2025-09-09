#include "HitEffect.h"

void HitEnemyEffect::Init() {

  // 4
  int random = RandomGenerator::GetInt(0, 3);

  float randS = RandomGenerator::GetFloat(0.2f, 0.3f);
  Math::Vector::Vec3 randScale = {randS, randS, 1.0f};
  scale_ = randScale;
  float randT = RandomGenerator::GetFloat(-0.8f, 0.8f);
   translate_+= {randT, randT, 0.0f};
   float randR = RandomGenerator::GetFloat(-0.3f, 0.3f);
  rotate_.z = randR;
  EffectModelSelector(random);
}

void HitEnemyEffect::Update() {

  timer_ += 1.0f / 60.0f;

  float scale = this->LerpEase(scale_.x, 0.0f, timer_);
  scale_ = {scale, scale, 1.0f};

  if (timer_ >= timerMax_) {
    SetMode(OBJ_MODE::REMOVE);
  }
}

void HitEnemyEffect::EffectModelSelector(const int &num) {

  filePathMap_[EffectName::Sokai_Jp] = {"Resources/Model/Enemy/Effect/soukaiJp",
                                        "sokaiJp"};
  filePathMap_[EffectName::sokai] = {"Resources/Model/Enemy/Effect/sokai",
                                     "sokai"};
  filePathMap_[EffectName::Miwaku] = {"Resources/Model/Enemy/Effect/miwaku",
                                      "miwaku"};
  filePathMap_[EffectName::NamaAsi] = {"Resources/Model/Enemy/Effect/NAMAasi",
                                       "NAMAasi"};

  auto path = filePathMap_[static_cast<EffectName>(num)];
  // auto path = filePathMap_[EffectName::Miwaku];

  uint32_t modelHandle = modelManager_->LoadModel(path.directory_, path.name_);
  this->SetModelHandle(modelHandle);
}
