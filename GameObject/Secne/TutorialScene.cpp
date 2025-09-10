#include "TutorialScene.h"

void TutorialScene::Init(){
	// 最初にトランジションの初期化を行う
	BlackScreenTransition::GetInstance()->Init();

	shouldTransition = false;

	

	TutorialSceneUI_ = std::make_unique<TutorialSceneUI>();
	TutorialSceneUI_->Init();

	TutorialSceneUI_->SetTranslate(Background_pos);
	TutorialSceneUI_->SetScale(Background_Scale);

	BlackScreenTransition::GetInstance()->StartFadeIn(2.0f, [this]() {
		
		});
}

void TutorialScene::Update(CLEYERA::Manager::SceneManager* ins){

	auto input = CLEYERA::Manager::InputManager::GetInstance();
	auto sceneManager = CLEYERA::Manager::SceneManager::GetInstance();
	// シーン遷移が必要な場合
	if (shouldTransition) {
		// フェードアウトを開始
		BlackScreenTransition::GetInstance()->StartFadeOut(1.0f, [=]() {
			sceneManager->ChangeScene("TitleScene");
			return;
			});
	}
	// 毎フレーム、トランジション（フェード処理）の更新を呼び出す
	BlackScreenTransition::GetInstance()->Update();

	//各シーンで呼び出す
	if (BlackScreenTransition::GetInstance()->isOverReturn()) {
		return;
	}

#ifdef _DEBUG

	if (ImGui::TreeNode("Cler")) {
		ImGui::DragFloat2("Background_Scale", &Background_Scale.x);
		ImGui::DragFloat2("Background_pos", &this->Background_pos.x, 1.f, -1000.0f, 1000.0f);

		ImGui::TreePop();
	}

#endif	_DEBUG

	TutorialSceneUI_->SetTranslate(Background_pos);
	TutorialSceneUI_->SetScale(Background_Scale);

	TutorialSceneUI_->Update();

	// フェード中はプレイヤーの入力を受け付けないようにする
	if (BlackScreenTransition::GetInstance()->IsActive()) {
		return; // ここで処理を中断
	}

	if (input->PushBotton(XINPUT_GAMEPAD_A)) {
		shouldTransition = true;
	}

}

void TutorialScene::Draw2d(){
	TutorialSceneUI_->Draw();
	BlackScreenTransition::GetInstance()->Draw2D();
}
