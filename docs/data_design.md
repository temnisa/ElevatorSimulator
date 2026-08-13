# データ設計書

## 1. Elevator構造体

### 目的

エレベーターの状態を管理する。

---

## 2. 管理データ一覧

| 項目名        | 内容       |
| --------------| -----------|
| current_floor | 現在階      |
| target_floor  | 目標階      |
| current_state | 現在状態     |
| door_timer    | ドア開放時間管理 |
| move_timer    | 移動時間管理   |

---

## 3. 定数

### TARGET_NOT_SET

説明

目標階が未設定であることを表す定数。

値

0

用途

目標階が設定されていない状態を表す。

---

## 4. ElevatorState（列挙型）

### 目的

エレベーターの動作状態を管理する。

| 状態 | 説明 |
|------|------|
| STOP | 停止状態 |
| MOVING_UP | 上昇中 |
| MOVING_DOWN | 下降中 |
| DOOR_OPEN | ドア開放中 |

---

## 5. 各メンバーの詳細

### current_floor

### 説明

現在エレベーターが存在する階。

### 範囲

1～5

### 初期値

1

---

### target_floor

### 説明

利用者が指定した行先階。

### 範囲

1～5

### 初期値

TARGET_NOT_SET（0）

---

### current_state

### 説明

現在の動作状態。

### 値

* STOP
* MOVING_UP
* MOVING_DOWN
* DOOR_OPEN

### 初期値

STOP

---

### door_timer

### 説明

ドア開放時間を管理するタイマー。

### 単位

100ms（10カウントで1秒）

### 初期値

0

### 用途

DOOR_OPEN状態で使用する。

---

### move_timer

### 説明

移動時間を管理するタイマー。

### 単位

100ms（10カウントで1秒）

### 初期値

0

### 用途

MOVING_UPおよびMOVING_DOWN状態で使用する。

---

## 6. 状態とデータの関係

### STOP

使用データ

* current_floor
* target_floor
* current_state

---

### MOVING_UP

使用データ

* current_floor
* target_floor
* current_state
* move_timer

---

### MOVING_DOWN

使用データ

* current_floor
* target_floor
* current_state
* move_timer

---

### DOOR_OPEN

使用データ

* current_state
* door_timer
* target_floor

---

## 7. タイマー仕様

### 移動時間

* 1階移動するごとに1秒経過

例

1F → 2F

所要時間：1秒

---

### ドア開放時間

到着後

* 3秒間ドア開放

その後STOP状態へ遷移する。
