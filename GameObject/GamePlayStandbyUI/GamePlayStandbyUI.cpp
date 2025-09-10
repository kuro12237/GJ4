#include "GamePlayStandbyUI.h"

void GamePlayStandbyUI::Init()
{
	// 4つのUI要素（3, 2, 1, GO）を生成
	StandbyUI_.resize(4);
	StandbyUI_[0] = std::make_shared<number_3>();
	StandbyUI_[1] = std::make_shared<number_2>();
	StandbyUI_[2] = std::make_shared<number_1>();
	StandbyUI_[3] = std::make_shared<number_GO>();

	// 全てのUI要素に共通の設定を適用
	for (auto& ui : StandbyUI_) {
		ui->Init();
		ui->SetScale(scale_);
		ui->SetTranslate(pos_); 
		ui->SetVisible(false);  
	}

	//StandbyUI_[3]->SetScale{(GO_Scale)};
	StandbyUI_[3]->SetScale(GO_Scale);
}

void GamePlayStandbyUI::Start(std::function<void()> on_finished)
{
	if (currentState_ != State::Idle) return;

	onFinishedCallback_ = on_finished;
	stateTimer_ = 0.0f;
	currentUiIndex_ = 0; // 最初のUIは「3」 (インデックス0)
	currentState_ = State::Countdown;

	// 最初のUIのアニメーションを開始
	StandbyUI_[currentUiIndex_]->StartAnimation(0.8f, 1.2f, DURATION_PER_NUMBER);
}

void GamePlayStandbyUI::Update()
{
	// カウントダウン中でなければ何もしない
	if (currentState_ != State::Countdown) {
		return;
	}

	// 全てのUI要素のUpdateを呼び出す（アニメーション計算のため）
	for (auto& ui : StandbyUI_) {
		ui->Update();
	}

	const float DELTA_TIME_60FPS = 1.0f / 60.0f;
	stateTimer_ += DELTA_TIME_60FPS;

	// 1秒経過したら、次の数字へ
	if (stateTimer_ >= DURATION_PER_NUMBER) {
		stateTimer_ = 0.0f; // タイマーリセット

		// 今のUIを非表示にする
		StandbyUI_[currentUiIndex_]->SetVisible(false);

		// 次のUIへインデックスを進める
		currentUiIndex_++;

		// もし最後のUI("GO")も終わったら
		if (currentUiIndex_ >= StandbyUI_.size()) {
			currentState_ = State::Finished;
			if (onFinishedCallback_) {
				onFinishedCallback_(); // ゲームスタート処理を呼び出す
			}
		}
		//まだ表示するUIが残っているなら
		else {
			// 次のUIのアニメーションを開始
			StandbyUI_[currentUiIndex_]->StartAnimation(0.8f, 1.2f, DURATION_PER_NUMBER);
		}
	}
}

void GamePlayStandbyUI::Draw2d()
{
	// 全てのUI要素の描画処理を呼ぶ
	// 表示状態(isVisible_)は各UIが持っているので、表示すべきものだけが描画される
	for (auto& ui : StandbyUI_) {
		ui->Draw();
	}
}