#pragma once

class GameManager {
public:
    // このクラスの唯一のインスタンスを取得する
    static GameManager* GetInstance();

    // ゲーム終了をリクエストする
    void RequestQuit() { isQuitRequested_ = true; }

    // ゲームが終了をリクエストされているか確認する
    bool IsQuitRequested() const { return isQuitRequested_; }

private:
    // シングルトンにするため、コンストラクタなどをprivateにする
    GameManager() = default;
    ~GameManager() = default;
    GameManager(const GameManager&) = delete;
    GameManager& operator=(const GameManager&) = delete;

    bool isQuitRequested_ = false;
};