#ifndef CSV_UTILS_H
#define CSV_UTILS_H

// CSV 파일 정보 출력
void show_csv_info(const char *file_path);

// CSV 파일 랜덤 분할 (사용자가 지정한 수의 파일로 분할)
void split_csv_random(const char *input_csv, const char **output_files, int num_files);

#endif


