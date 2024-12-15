#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>

int main() {
    char input_csv[256];
    int num_files;

    printf("Enter the input CSV file path: ");
    scanf("%s", input_csv);

    printf("Enter the number of files to split into: ");
    scanf("%d", &num_files);

    if (num_files <= 0) {
        fprintf(stderr, "Error: Number of files must be greater than 0.\n");
        return 1;
    }

    // 동적 라이브러리 핸들
    void *handle;
    void (*show_csv_info)(const char *);
    void (*split_csv_random)(const char *, const char **, int);
    char *error;

    // 라이브러리 로드
    handle = dlopen("./libcsvutils.so", RTLD_LAZY);
    if (!handle) {
        fprintf(stderr, "Error loading library: %s\n", dlerror());
        exit(1);
    }

    // show_csv_info 함수 로드
    *(void **)(&show_csv_info) = dlsym(handle, "show_csv_info");
    if ((error = dlerror()) != NULL) {
        fprintf(stderr, "Error loading show_csv_info: %s\n", error);
        dlclose(handle);
        exit(1);
    }

    // split_csv_random 함수 로드
    *(void **)(&split_csv_random) = dlsym(handle, "split_csv_random");
    if ((error = dlerror()) != NULL) {
        fprintf(stderr, "Error loading split_csv_random: %s\n", error);
        dlclose(handle);
        exit(1);
    }

    // 출력 파일 이름 자동 생성
    char **output_files = malloc(num_files * sizeof(char *));
    for (int i = 0; i < num_files; i++) {
        output_files[i] = malloc(256 * sizeof(char));
        snprintf(output_files[i], 256, "part%d.csv", i + 1);
    }

    // show_csv_info 호출
    show_csv_info(input_csv);

    // split_csv_random 호출
    split_csv_random(input_csv, (const char **)output_files, num_files);

    // 메모리 해제
    for (int i = 0; i < num_files; i++) {
        free(output_files[i]);
    }
    free(output_files);

    // 라이브러리 닫기
    if (dlclose(handle) < 0) {
        fprintf(stderr, "Error closing library: %s\n", dlerror());
        exit(1);
    }

    return 0;
}



