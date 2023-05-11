test: carg-parse.c carg-parse.h test.c
	@echo "BUILDING"
	@clang ./test.c ./carg-parse.c -o ./test
	@echo "DONE"

stress:
	@make test
	@echo "STRESSING - if you see any errors / segfaults / fuckups please revert changes or open an issue"
	./test
	./test -a -a
	./test --a
	./test -
	./test a b c d -a a -b b -c c -d d
