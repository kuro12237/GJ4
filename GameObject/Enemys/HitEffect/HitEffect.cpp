#include "HitEffect.h"

void HitEnemyEffect::Init() {

  // 4
  int random = RandomGenerator::GetInt(0, 3);

  float randS = RandomGenerator::GetFloat(0.2f, 0.3f);
  Math::Vector::Vec3 randScale = {randS, randS, 1.0f};
  scale_ = randScale;
  float randT = RandomGenerator::GetFloat(-0.8f, 0.8f);
  translate_ += {randT, randT, 0.0f};
  float randR = RandomGenerator::GetFloat(-0.3f, 0.3f);
  rotate_.z = randR;
  EffectModelSelector(random);

}

void HitEnemyEffect::Update() {

  timer_ += 1.0f / 60.0f;

  float scale = this->LerpEase(scale_.x, 0.0f, timer_);
  scale_ = {scale, scale, 1.0f};

  gameObject_->ColorData().color_ = RandomColorHSV();
  if (timer_ >= timerMax_) {
    SetMode(OBJ_MODE::REMOVE);
  }
}

Math::Vector::Vec4 HitEnemyEffect::RandomColorHSV() {

  float h = RandomGenerator::GetFloat(0.0f, 1.0f);
  float s = 0.8f; // 彩度高め
  float v = 0.9f; // 明るめ

  int i = int(h * 6.0f);
  float f = h * 6.0f - i;
  float p = v * (1.0f - s);
  float q = v * (1.0f - f * s);
  float t = v * (1.0f - (1.0f - f) * s);

  float r, g, b;
  switch (i % 6) {
  case 0:
    r = v;
    g = t;
    b = p;
    break;
  case 1:
    r = q;
    g = v;
    b = p;
    break;
  case 2:
    r = p;
    g = v;
    b = t;
    break;
  case 3:
    r = p;
    g = q;
    b = v;
    break;
  case 4:
    r = t;
    g = p;
    b = v;
    break;
  case 5:
    r = v;
    g = p;
    b = q;
    break;
  }

  return {r, g, b, 1.0f};
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
