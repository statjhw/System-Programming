
# **CSV Utils**

`csv_utils`는 CSV 파일 처리를 위한 간단한 라이브러리입니다. 이 라이브러리는 CSV 파일 정보를 출력하고, 데이터를 여러 파일로 랜덤하게 분할하는 기능을 제공합니다.

---

## **기능**

- **CSV 파일 정보 출력 (`show_csv_info`)**  
  - CSV 파일의 행(row)과 열(column) 개수를 출력합니다.

- **CSV 파일 랜덤 분할 (`split_csv_random`)**  
  - 주어진 CSV 파일을 지정된 개수의 파일로 랜덤하게 분할합니다.

---

## **파일 구조**

```plaintext
project/
├── csv_utils.h           # 헤더 파일 (공통)
├── csv_info.c            # show_csv_info 함수 구현
├── csv_split.c           # split_csv_random 함수 구현
├── test_static.c         # 정적 링크 테스트
├── test_runtime.c        # 런타임 동적 링크 테스트
├── Makefile              # 빌드 및 실행을 위한 Makefile
└── README.md             # 프로젝트 설명 파일
```

---

## **빌드 방법**
1. 모든 파일 빌드
```bash
make
```

- 정적 라이브러리(libcsvutils.a), 동적 라이브러리(libcsvutils.so), 테스트 실행 파일(test_static, test_runtime) 생성.

2. 파일 삭제
```bash
make clean
```

- 빌드 과정에서 생성된 모든 파일(*.o, *.a, *.so, 실행 파일 등`)을 삭제합니다.

---

## **실행 방법**

정적 라이브러리 테스트
```bash
./test_static
```

동적 라이브러리 테스트
```bash
./test_runtime
```


