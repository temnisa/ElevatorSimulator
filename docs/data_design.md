# データ設計書

## 1. Elevator構造体

### 目的

エレベーターの状態を管理する。

---

## 管理データ一覧

| 項目名          | 内容       |
| ------------ | -------- |
| currentFloor | 現在階      |
| targetFloor  | 目標階      |
| state        | 現在状態     |
| doorTimer    | ドア開放時間管理 |
| moveTimer    | 移動時間管理   |

---

## currentFloor

### 説明

現在エレベーターが存在する階。

### 範囲

1～5

### 初期値

1

---

## targetFloor

### 説明

利用者が指定した行先階。

### 範囲

1～5

### 初期値

1

---

## state

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

## doorTimer

### 説明

ドア開放時間を管理するタイマー。

### 単位

秒

### 初期値

0

### 用途

DOOR_OPEN状態で使用する。

---

## moveTimer

### 説明

移動時間を管理するタイマー。

### 単位

秒

### 初期値

0

### 用途

MOVING_UPおよびMOVING_DOWN状態で使用する。

---

## 状態とデータの関係

### STOP

使用データ

* currentFloor
* targetFloor
* state

---

### MOVING_UP

使用データ

* currentFloor
* targetFloor
* state
* moveTimer

---

### MOVING_DOWN

使用データ

* currentFloor
* targetFloor
* state
* moveTimer

---

### DOOR_OPEN

使用データ

* state
* doorTimer

---

## タイマー仕様

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
