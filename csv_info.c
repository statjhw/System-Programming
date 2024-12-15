#include "csv_utils.h"
#include <stdio.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024

// CSV 파일 정보 출력 함수
void show_csv_info(const char *file_path) {
    FILE *file = fopen(file_path, "r");
    if (!file) {
        perror("File open failed");
        return;
    }

    char line[MAX_LINE_LENGTH];
    int row_count = 0, column_count = 0;

    // 첫 줄 읽어 컬럼 개수 확인
    if (fgets(line, MAX_LINE_LENGTH, file)) {
        row_count++;
        char *token = strtok(line, ",");
        while (token) {
            column_count++;
            token = strtok(NULL, ",");
        }
    }

    // 나머지 줄 개수 카운트
    while (fgets(line, MAX_LINE_LENGTH, file)) {
        row_count++;
    }

    fclose(file);

    printf("CSV File Info:\n");
    printf("  Rows: %d\n", row_count);
    printf("  Columns: %d\n", column_count);
}