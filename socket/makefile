.PHONY:all
all:TIME_CLI SELECT_TEST
TIME_CLI:time_cli.c
	gcc -o $@ $^

SELECT_TEST: select_test.c
	gcc -o $@ $^

.PHONY:clean
 clean:
	rm -f TIME_CLI SELECT_TEST
