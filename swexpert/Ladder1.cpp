#include <stdio.h>
int main(void) {
	for (int z = 1; z <= 10; z++) {
		int n;
		scanf("%d", &n);
		int map[102][102] = { { 0, }, };
		int x, y;
		for (int i = 1; i <= 100; i++) {
			for (int j = 1; j <= 100; j++) {
				scanf("%d", &map[i][j]);
				if (map[i][j] == 2)//X지점의 좌표를 기록
				{
					x = i;
					y = j;
				}
			}
		}

		for (int i = 99; i >= 0; i--) {//맨 아래층부터 한칸씩 위로 올라간다
			if (map[i][y + 1] == 1) {//오른쪽에 길이 있으면 갈 수 있을 떄 까지 오른쪽으로 이동
				while (true) {
					y++;
					if (map[i][y + 1] != 1)
						break;
				}
			}
			else if (map[i][y - 1] == 1) {//왼쪽에 길이 있으면 갈 수 있을 떄 까지 왼쪽으로 이동
				while (true) {
					y--;
					if (map[i][y - 1] != 1)
						break;
				}
			}
		}
		printf("#%d %d\n", z, y - 1);
	}
	return 0;
}