#include "TitleLogo.h"
#include "CLEYERA.h"

void TitleLog::Init() {
	//„Çø„Ç§„Éà„É´„É≠„Ç¥„ÅØ‰∫å„Å§
	TitleLogo_.resize(2);

	//HOTLIMIT(„Çø„Ç§„Éà„É´„É≠„Ç¥‰∏ä)
	TitleLogo_[0] = std::make_shared<TitleLogo_HOT>();
	TitleLogo_[0]->SetName(VAR_NAME(TitleLogo_HOT));
	//WHITEBREATH(„Çø„Ç§„Éà„É´„É≠„Ç¥‰∏ã)
	TitleLogo_[1] = std::make_shared<TitleLogo_WHITE>();
	TitleLogo_[1]->SetName(VAR_NAME(TitleLogo_WHITE));

	for (auto Logo : TitleLogo_) {
		
		Logo->SetScale({ Scale });
		Logo->Init();
	}

	TitleLogo_[0]->SetTranslate({ HOT_pos });

	TitleLogo_[1]->SetTranslate({ WHITE_pos });

}

void TitleLog::Update()
{
	for (auto Logo : TitleLogo_) {
		Logo->Update();
	//	Logo->SetScale({ Scale });
	}
	//TitleLogo_[0]->SetTranslate( HOT_pos);
	//TitleLogo_[1]->SetTranslate(WHITE_pos);

#ifdef _DEBUG

	if (ImGui::TreeNode("Log")) {

		
		ImGui::DragFloat2("size", &Scale.x);
		
		ImGui::DragFloat2("HOT_pos", &this->HOT_pos.x, 1.f, -1000.0f, 1000.0f);
		ImGui::DragFloat2("WHITE_pos", &this->WHITE_pos.x, 1.f, -1000.0f, 1000.0f);


		ImGui::TreePop();

	}

#endif // _DEBUG
}

void TitleLog::Draw2D()
{
	for (auto Logo : TitleLogo_) {
		Logo->Draw();
	}
}

void TitleLog::SceneEnd(){
	
}



void TitleLog::StartOpeningAnimation(float distance, float duration)
{
	if (TitleLogo_.size() < 2) { return; }

	// 0î‘ñ⁄(è„ÉçÉS)Ç∆1î‘ñ⁄(â∫ÉçÉS)ÇÃÉAÉjÉÅÅ[ÉVÉáÉìÇäJén
	// è„ÇÃÉçÉSÇÕè„Ç…à⁄ìÆ
	Math::Vector::Vec2 hot_start = HOT_pos;
	Math::Vector::Vec2 hot_end = { HOT_pos.x, HOT_pos.y - distance };
	TitleLogo_[0]->StartAnimation(hot_start, hot_end, duration);

	// â∫ÇÃÉçÉSÇÕâ∫Ç…à⁄ìÆ
	Math::Vector::Vec2 white_start = WHITE_pos;
	Math::Vector::Vec2 white_end = { WHITE_pos.x, WHITE_pos.y + distance };
	TitleLogo_[1]->StartAnimation(white_start, white_end, duration);
}

bool TitleLog::IsAnimating() const
{
	if (TitleLogo_.size() < 2) { return false; }

	// Ç«ÇøÇÁÇ©ÇÃÉçÉSÇ™ÉAÉjÉÅÅ[ÉVÉáÉìíÜÇ»ÇÁtrueÇï‘Ç∑
	return TitleLogo_[0]->IsAnimating() || TitleLogo_[1]->IsAnimating();
}

void TitleLog::SetAllAlphas(float alpha){
	for (auto& logo : TitleLogo_) {
		logo->SetAlpha(alpha);
	}
}
