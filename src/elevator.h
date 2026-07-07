#ifndef _ELEVATOR_H_
#define _ELEVATOR_H_

// エレベーターの状態を表す列挙型
typedef enum {
	STOP,			//0
	MOVING_UP,		//1
	MOVING_DOWN,	//2
	DOOR_OPEN,		//3
} ElevatorState;

// エレベーターのデータを定義
typedef struct {
	int current_floor;				// 現在の階数
	int target_floor;				// 目標の階数
	ElevatorState current_state;	// 現在の状態

	// タイマー関連の変数
	// タイマーは100ms周期なので move_timer = 10 で1秒 door_timer = 30で3秒になる
	int move_timer;					// 移動タイマー							
	int door_timer;					// ドアタイマー
} ElevatorData;

// エレベーターのデータを初期化する関数
void init_elevator(ElevatorData* elevator);

// エレベーターの目標階数を設定する関数
void set_target_floor(ElevatorData* elevator, int target_floor);

// エレベーターの状態を更新する関数
// この関数は、状態遷移およびタイマー更新を行う
void update_elevator(ElevatorData* elevator);

// エレベーターの現在階数を取得する関数
int get_current_floor(ElevatorData* elevator);

// エレベーターの現在状態を取得する関数
ElevatorState get_current_state(ElevatorData* elevator);

// エレベーターの目標階数を取得する関数
int get_target_floor(ElevatorData* elevator);


#endif 
