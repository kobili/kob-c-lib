build:
	gcc -o main main.c array.c hashing.c string.c

test:
	rm -rf tests/bin;
	mkdir tests/bin;
	gcc -o tests/bin/test_array tests/test_array.c array.c;
	./tests/bin/test_array;
	gcc -o tests/bin/test_string tests/test_string.c string.c
	./tests/bin/test_string;
