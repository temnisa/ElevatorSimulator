#include <stdio.h>
#include <windows.h>
#include "elevator.h"

int main() {
	// エレベーターのデータを初期化
	ElevatorData elevator;

	// エレベーターを初期化
	Elevator_Init(&elevator);

	
	while (1) {
		
		// エレベーターの現在の状態を表示
		printf("--------------------\n");
		printf("現在階: %d\n", elevator.current_floor);
		printf("目標階: %d\n", elevator.target_floor);
		printf("状態  : %s\n", Elevator_GetStateName(elevator.current_state));
		printf("--------------------\n");
		
		// 状態がSTOPなら目標階を入力
		if (elevator.current_state == STOP) {
			// 入力用の一時変数を宣言
			int target_floor;

			// 目標階を入力
			printf("目標階を入力してください: ");
			scanf_s("%d", &target_floor);
			printf("\n");
			Elevator_SetTargetFloor(&elevator, target_floor);
		}

		Elevator_Update(&elevator);
		
		// 100ms待機
		Sleep(100);

	}
}