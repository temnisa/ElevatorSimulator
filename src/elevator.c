#include <stdio.h>
#include "elevator.h"

#define TARGET_NOT_SET 0 // 未設定を表す定数

// エレベーターのデータを初期化する関数
void init_elevator(ElevatorData* elevator) {
	elevator->current_floor = 1;
	elevator->target_floor = TARGET_NOT_SET;
	elevator->current_state = STOP;
	elevator->move_timer = 0;
	elevator->door_timer = 0;
}
