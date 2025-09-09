#pragma once
#include "CLEYERA.h"

class Player;
class IPlayerState {
public:
  IPlayerState() {};
  virtual ~IPlayerState() {};

  virtual void Init() = 0;

  virtual void Update(Player *ins = nullptr) = 0;
  void SetPosition(Math::Vector::Vec3 *pos) { translate_ = pos; }
  void SetForce(Math::Vector::Vec3 *pos) { force_ = pos; }

private:
protected:
  void Control();

  float widthMinMax_ = 9.0f;
  float heightMinMax_ = 3.0f;

  float speed_ = 0.0f;

  float zCenter_ = 0.0f;

 
  Math::Vector::Vec3 *translate_ = nullptr;
  Math::Vector::Vec3 *force_ = nullptr;


  void ChangeModel(uint32_t handle);
};
