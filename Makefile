build:
	gcc -o main main.c array.c hashing.c string.c

test:
	rm -rf tests/bin;
	mkdir tests/bin;
	gcc -o tests/bin/test_array_int tests/test_array_int.c array.c;
	gcc -o tests/bin/test_array_struct tests/test_array_struct.c array.c;
	gcc -o tests/bin/test_string tests/test_string.c string.c
