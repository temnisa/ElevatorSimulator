# Elevator Control Simulator

## 概要

エレベーター制御を模擬したコンソールアプリケーションです。

組み込みソフトウェア開発を想定し、状態遷移による制御を実装しています。

## 開発目的

組み込みソフトウェア開発に必要な以下のスキルを習得することを目的として開発しました。

* C言語
* 状態遷移設計
* モジュール分割
* テスト設計
* Git/GitHub運用

## システム仕様

* 5階建てエレベーター
* 1台構成
* コンソール操作
* 行先階指定
* 上昇・下降制御
* ドア開閉制御

## 状態一覧

* STOP
* MOVING_UP
* MOVING_DOWN
* DOOR_OPEN

## プロジェクト構成

```text
ElevatorSimulator/
├─ src/
├─ docs/
│   ├─ requirements.md
│   ├─ state_diagram.md
│   ├─ test_cases.md
│   └─ module_design.md
└─ README.md
```

## 設計資料

| ファイル             | 内容       |
| ---------------- | -------- |
| requirements.md  | 要求仕様書    |
| state_diagram.md | 状態遷移図    |
| test_cases.md    | テストケース   |
| module_design.md | モジュール設計書 |

## 実行例

```text
現在階：1F

行先を入力してください
> 4

移動中...
2F
3F
4F

到着しました
```

## 今後の拡張予定

* 複数階予約
* 外部呼び出しボタン
* 優先順位制御
* 緊急停止機能
* 複数台制御

## 開発環境

* Language : C
* IDE : Visual Studio 2026
* OS : Windows 11
* Compiler : MSVC
* Version Control : Git
* Repository : GitHub

```
```
