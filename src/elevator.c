#include <stdio.h>
#include "elevator.h"

#define TARGET_NOT_SET 0 // 未設定を表す定数

// エレベーターのデータを初期化する関数
void Elevator_Init(ElevatorData* elevator) {
	elevator->current_floor = 1;
	elevator->target_floor = TARGET_NOT_SET;
	elevator->current_state = STOP;
	elevator->move_timer = 0;
	elevator->door_timer = 0;
}

// エレベーターの目標階を設定する関数
void Elevator_SetTargetFloor(ElevatorData* elevator, int target_floor) {

	// 無効な階数が設定された場合は何もしない
	if (target_floor < 1 || target_floor > 5) {
		return;
	}
	
	// 目標階数が現在の階数と同じ場合は何もしない
	if (elevator->current_floor == target_floor) {
		return;
	}

	// 現在階と異なる場合のみ目標階数を設定
	elevator->target_floor = target_floor;

}

// エレベーターの状態を更新する関数
void Elevator_Update(ElevatorData* elevator) {

	switch (elevator->current_state) {
	case STOP:
		if (elevator->target_floor == TARGET_NOT_SET) {
			// 目標階が未設定の場合は何もしない
			return;
		}
		if (elevator->target_floor > elevator->current_floor) {
			elevator->current_state = MOVING_UP;

		}
		else {
			elevator->current_state = MOVING_DOWN;
		}
		break;

	case MOVING_UP:
		
		elevator->move_timer++;

		if (elevator->move_timer >= 10) {
			// 1秒経過したら階数を上げる
			elevator->current_floor++;
			// 移動タイマーを初期化
			elevator->move_timer = 0;

			// 目標階に到達したらドアを開ける
			if (elevator->current_floor == elevator->target_floor) {
				elevator->current_state = DOOR_OPEN;
				// ドアタイマーを初期化
				elevator->door_timer = 0;
			}
		}
		break;

	case MOVING_DOWN:

		elevator->move_timer++;

		if (elevator->move_timer >= 10) {
			// 1秒経過したら階数を下げる
			elevator->current_floor--;
			// 移動タイマーを初期化
			elevator->move_timer = 0;

			// 目標階に到達したらドアを開ける
			if (elevator->current_floor == elevator->target_floor) {
				elevator->current_state = DOOR_OPEN;
				// ドアタイマーを初期化
				elevator->door_timer = 0;
			}
		}
		break;

	case DOOR_OPEN:

		// ドアが開いている状態では、ドアタイマーをカウントアップする
		elevator->door_timer++;

		// ドアが開いてから3秒経過したらドアを閉める
		if (elevator->door_timer >= 30) {
			// 目標階を未設定に戻す
			elevator->target_floor = TARGET_NOT_SET;

			// ドアタイマーを初期化
			elevator->door_timer = 0;

			// ドアを閉めて停止状態に戻す
			elevator->current_state = STOP;
		}
		break;

	default:
		break;
	}

}