# 状態遷移図

## STOP
```text
STOP（停止中）
 ├─ 目標階なし
 │    └→ STOP
 │
 ├─ 目標階 > 現在階
 │    └→ MOVING_UP（上昇中）
 │
 └─ 目標階 < 現在階
      └→ MOVING_DOWN（下降中）
```
## MOVING_UP
```text
MOVING_UP（上昇中）
 └─ 目標階に到達
      └→ DOOR_OPEN（ドア開放中）
```
## MOVING_DOWN
```text
MOVING_DOWN（下降中）
 └─ 目標階に到達
      └→ DOOR_OPEN（ドア開放中）
```
## DOOR_OPEN
```text
DOOR_OPEN（ドア開放中）
 └─ 3秒経過
      └→ STOP（停止中）
```

## 全体の状態遷移
```text
STOP（停止中）
 ├─ 目標階なし
 │    └→ STOP
 │
 ├─ 目標階 > 現在階
 │    └→ MOVING_UP（上昇中）
 │         └─ 目標階に到達
 │              └→ DOOR_OPEN（ドア開放中）
 │                   └─ 3秒経過
 │                        └→ STOP（停止中）
 │
 └─ 目標階 < 現在階
      └→ MOVING_DOWN（下降中）
           └─ 目標階に到達
                └→ DOOR_OPEN（ドア開放中）
                     └─ 3秒経過
                          └→ STOP（停止中）

```
## 状態一覧

* STOP：停止中
* MOVING_UP：上昇中
* MOVING_DOWN：下降中
* DOOR_OPEN：ドア開放中
