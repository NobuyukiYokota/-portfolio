#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct {
    char name[20];
    int score;
} Student;

Student list[MAX];
int count = 0;

void menu() {
    printf("\n1.登録\n2.表示\n3.平均\n4.保存\n5.終了\n");
}

int main() {
    int choice;

    while (1) {
        menu();
        printf("選択: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (count >= MAX) { printf("登録できません\n"); break; }
                printf("名前: "); scanf("%s", list[count].name);
                printf("点数: "); scanf("%d", &list[count].score);
                count++; printf("登録しました\n");
                break;

            case 2:
                if (count == 0) { printf("登録されていません\n"); break; }
                for (int i = 0; i < count; i++)
                    printf("名前: %s, 点数: %d\n", list[i].name, list[i].score);
                break;

            case 3:
                if (count == 0) { printf("登録されていません\n"); break; }
                {
                    int sum = 0;
                    for (int i = 0; i < count; i++) sum += list[i].score;
                    printf("平均点: %.2f\n", (double)sum / count);
                }
                break;

            case 4:
                {
                    FILE *fp = fopen("students.txt", "w");
                    if (fp == NULL) { printf("保存失敗\n"); break; }
                    for (int i = 0; i < count; i++)
                        fprintf(fp, "%s %d\n", list[i].name, list[i].score);
                    fclose(fp); printf("保存しました\n");
                }
                break;

            case 5: return 0;

            default: printf("無効です\n");
        }
    }
}