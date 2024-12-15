all: libcsvutils.a libcsvutils.so test_static test_runtime

# csv_info.c에서 오브젝트 파일 생성
csv_info.o: csv_info.c csv_utils.h
	gcc -Wall -fPIC -c csv_info.c -o csv_info.o

# csv_split.c에서 오브젝트 파일 생성
csv_split.o: csv_split.c csv_utils.h
	gcc -Wall -fPIC -c csv_split.c -o csv_split.o

# 정적 라이브러리 생성
libcsvutils.a: csv_info.o csv_split.o
	ar rcs libcsvutils.a csv_info.o csv_split.o

# 동적 라이브러리 생성
libcsvutils.so: csv_info.o csv_split.o
	gcc -shared -o libcsvutils.so csv_info.o csv_split.o

# 정적 링크 테스트 실행 파일 생성
test_static: test_static.c libcsvutils.a
	gcc -static test_static.c -L. -lcsvutils -o test_static

# 런타임 링크 테스트 실행 파일 생성
test_runtime: test_runtime.c libcsvutils.so
	gcc test_runtime.c -ldl -o test_runtime

# 생성된 파일 정리
clean:
	rm -f csv_info.o csv_split.o libcsvutils.a libcsvutils.so test_static test_runtime