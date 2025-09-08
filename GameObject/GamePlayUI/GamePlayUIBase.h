#pragma once
#include "CLEYERA/CLEYERA.h"

class GamePlayUIBase : public SpriteComponent {
public:
  GamePlayUIBase() {};
  ~GamePlayUIBase() {};

  virtual void Init() = 0;

  virtual void Update() = 0;

private:
};
