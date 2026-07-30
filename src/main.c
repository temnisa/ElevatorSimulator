#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "elevator.h"

int main() {
	// エレベーターのデータを初期化
	ElevatorData elevator;

	// エレベーターを初期化
	Elevator_Init(&elevator);

	
	while (1) {
		
		// 最初に画面をクリア
		system("cls");
		printf("--------------------\n");

		// エレベーターの現在の状態を表示
		printf("現在の階数: %d\n", elevator.current_floor);

		// 目標階が未設定の場合は「未設定」と表示
		if (elevator.target_floor == TARGET_NOT_SET) {
			printf("目標の階数: 未設定\n");
		}
		else {
			printf("目標の階数: %d\n", elevator.target_floor);
		}
		printf("現在の状態: %s\n", Elevator_GetStateName(elevator.current_state));
		printf("--------------------\n");
		
		// 状態がSTOPなら目標階を入力
		if (elevator.current_state == STOP) {

			// 入力用の一時変数を宣言
			int target_floor = 0;
			char str[BUFFER_SIZE];
			char* end;

			// 目標階を入力
			printf("目標階を入力してください: ");
			scanf_s("%99s", str, BUFFER_SIZE);

			// 入力されたのが数字かどうかをチェック
			long value = strtol(str, &end, 10);

			printf("\n");

			// 入力された階数が有効かどうかをチェック
			if (*end != '\0') {
				printf("無効な入力です。\n");
				Sleep(1000);
				continue;
			}

			target_floor = (int)value;

			// 目標階が有効な範囲かどうかをチェック
			if (target_floor < 1 || target_floor > 5) {
				printf("無効な階数です。1～5の範囲で入力してください。\n");
				Sleep(1000);
				continue;
			}

			Elevator_SetTargetFloor(&elevator, target_floor);
		}

		Elevator_Update(&elevator);
		
		// 100ms待機
		Sleep(100);

	}
}