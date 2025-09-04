#pragma once
#include "CLEYERA/CLEYERA.h"

/// <summary>
/// カメラ
/// </summary>
class PlayerCamera : public CLEYERA::Component::CameraCompornent {
public:
  PlayerCamera() {};
  ~PlayerCamera() {};

  void Init() override;

  void Update() override;

private:
};
