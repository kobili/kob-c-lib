build:
	gcc -o main main.c array.c

test:
	gcc -o test_array_int tests/test_array_int.c array.c;
	gcc -o test_array_struct tests/test_array_struct.c array.c;
