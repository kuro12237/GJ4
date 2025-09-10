#pragma once
#include "CLEYERA.h" // エンジンの基本ヘッダ
#include "IGamePlayStandbyUI.h"
#include "number_3.h"
#include "number_2.h"
#include "number_1.h"
#include "number_GO.h"
#include <vector>
#include <memory>
#include <functional>

class GamePlayStandbyUI
{
public:
	GamePlayStandbyUI() {};
	~GamePlayStandbyUI() {};

	void Init();
	void Update();
	void Draw2d();

	// カウントダウンシーケンスを開始する
	void Start(std::function<void()> on_finished);

	// シーケンスが完了したかどうかを返す
	bool IsFinished() const { return currentState_ == State::Finished; }

private:
	enum class State {
		Idle,       // 開始待ち
		Countdown,  // カウントダウン実行中
		Finished    // 全て完了
	};

	State currentState_ = State::Idle;

	// ▼▼▼▼▼ SelectUIの構造をここに取り入れる ▼▼▼▼▼
	// UI要素を保持するベクター
	std::vector<std::shared_ptr<IGamePlayStandbyUI>> StandbyUI_;

	// UIの座標とスケールを管理する変数
	Math::Vector::Vec3 pos_ = { 1280.0f / 2.0f, 720.0f / 2.0f }; // 画面中央
	Math::Vector::Vec3 scale_ = { 1.0f, 1.0f };

	Math::Vector::Vec3 GO_Scale = { 4.f,4.f };


	int currentUiIndex_ = -1; // 現在表示中のUIのインデックス
	float stateTimer_ = 0.0f; // 経過時間を計るタイマー
	const float DURATION_PER_NUMBER = 1.0f; // 1つの数字を表示する時間

	std::function<void()> onFinishedCallback_;
};