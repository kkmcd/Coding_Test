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
				if (map[i][j] == 2)//X������ ��ǥ�� ���
				{
					x = i;
					y = j;
				}
			}
		}

		for (int i = 99; i >= 0; i--) {//�� �Ʒ������� ��ĭ�� ���� �ö󰣴�
			if (map[i][y + 1] == 1) {//�����ʿ� ���� ������ �� �� ���� �� ���� ���������� �̵�
				while (true) {
					y++;
					if (map[i][y + 1] != 1)
						break;
				}
			}
			else if (map[i][y - 1] == 1) {//���ʿ� ���� ������ �� �� ���� �� ���� �������� �̵�
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