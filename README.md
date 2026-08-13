# エレベーター制御シミュレーター

## 概要
C言語で作成したエレベーター制御シミュレータです。
状態遷移（State Machine）を用いてエレベーターの動作を制御し、コンソール画面上で現在階・目標階・状態を確認できます。
組み込みソフトウェア開発で重要となる「状態管理」「タイマー制御」「モジュール分割」を意識して設計・実装しました。

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

## 開発プロセス

1. 要求仕様の整理
2. ソフトウェア構成・データ・インターフェース設計
3. 状態遷移・処理フロー設計
4. C言語による実装
5. テストケース作成・実施
6. 設計レビュー

## プロジェクト構成

```text
ElevatorSimulator/
├─ src/
｜	 ├─ display.c
｜	 ├─ display.h
｜	 ├─ elevator.c
｜	 ├─ elevator.h
｜   ├─ input.c
｜   ├─ input.h
｜	 └─ main.c
├─ docs/
｜	 ├─ data_design.md
｜	 ├─ design_review.md
｜	 ├─ implementation_plan.md
｜	 ├─ interface_design.md
｜	 ├─ main_flow.md
｜	 ├─ module_design.md
│   ├─ requirements.md
│   ├─ software_architecture.md
│   ├─ state_diagram.md
│   └─ test_cases.md
└─ README.md
```

## 設計資料

| ファイル名                 | 内容                         |
|----------------------------|------------------------------|
| requirements.md            | 要求仕様書                   |
| software_architecture.md   | ソフトウェア構成設計         |
| data_design.md             | データ設計                   |
| interface_design.md        | インターフェース設計         |
| module_design.md           | モジュール設計               |
| state_diagram.md           | 状態遷移設計                 |
| main_flow.md               | Mainモジュールの処理フロー   |
| implementation_plan.md     | 実装計画                     |
| test_cases.md              | テストケース・実施結果       |
| design_review.md           | 設計レビュー記録             |

## 実行例

```text
現在の階数: 1
目標の階数: 未設定
現在の状態: STOP
--------------------
目標階を入力してください: 5

現在の階数: 1
目標の階数: 5
現在の状態: MOVING_UP

現在の階数: 2
目標の階数: 5
現在の状態: MOVING_UP

...

現在の階数: 5
目標の階数: 5
現在の状態: DOOR_OPEN


```
## テスト結果

| テストケース | 結果 |
|---|---|
| TC-001 上昇動作	| OK |
| TC-002 下降動作	| OK |
| TC-003 同一階指定 | OK |
| TC-004 範囲外入力後の再入力 | OK |
| TC-005 文字入力 | OK |

全5ケース成功

## 今後の拡張予定

* Inputモジュールの実装・分離
* Displayモジュールの実装・分離
* Getterによるエレベーター情報の取得

## 将来的な拡張

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
