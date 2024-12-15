#include "csv_utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_LINE_LENGTH 1024

// CSV 파일 랜덤 분할 함수
void split_csv_random(const char *input_csv, const char **output_files, int num_files) {
    if (num_files <= 0) {
        printf("Error: Number of output files must be greater than 0.\n");
        return;
    }

    FILE *in = fopen(input_csv, "r");
    if (!in) {
        perror("Input file open failed");
        return;
    }

    FILE **outs = malloc(num_files * sizeof(FILE *));
    for (int i = 0; i < num_files; i++) {
        outs[i] = fopen(output_files[i], "w");
        if (!outs[i]) {
            perror("Output file open failed");
            for (int j = 0; j < i; j++) {
                fclose(outs[j]);
            }
            free(outs);
            fclose(in);
            return;
        }
    }

    srand((unsigned int)time(NULL)); // 랜덤 시드 설정
    char line[MAX_LINE_LENGTH];
    int is_header = 1;

    // CSV 파일 읽기
    while (fgets(line, MAX_LINE_LENGTH, in)) {
        if (is_header) {
            // 헤더는 모든 파일에 작성
            for (int i = 0; i < num_files; i++) {
                fprintf(outs[i], "%s", line);
            }
            is_header = 0;
            continue;
        }

        // 랜덤하게 파일에 분할
        int rand_file = rand() % num_files;
        fprintf(outs[rand_file], "%s", line);
    }

    // 파일 닫기
    fclose(in);
    for (int i = 0; i < num_files; i++) {
        fclose(outs[i]);
    }
    free(outs);

    printf("CSV file split into %d files completed.\n", num_files);
}