#include <stdio.h>
#include <stdlib.h>
#include "csv_utils.h"

int main() {
    char input_csv[256];
    int num_files;

    // 입력 파일 경로와 분할 파일 수 입력 받기
    printf("Enter the input CSV file path: ");
    scanf("%s", input_csv);

    printf("Enter the number of files to split into: ");
    scanf("%d", &num_files);

    if (num_files <= 0) {
        fprintf(stderr, "Error: Number of files must be greater than 0.\n");
        return 1;
    }

    // 출력 파일 이름 자동 생성
    char **output_files = malloc(num_files * sizeof(char *));
    for (int i = 0; i < num_files; i++) {
        output_files[i] = malloc(256 * sizeof(char));
        snprintf(output_files[i], 256, "part%d.csv", i + 1);
    }

    // CSV 파일 정보 출력
    show_csv_info(input_csv);

    // CSV 파일 랜덤 분할
    split_csv_random(input_csv, (const char **)output_files, num_files);

    // 메모리 해제
    for (int i = 0; i < num_files; i++) {
        free(output_files[i]);
    }
    free(output_files);

    return 0;
}