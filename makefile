test: carg-parse.c carg-parse.h test.c
	@echo "BUILDING"
	@clang ./test.c ./carg-parse.c -o ./test
	@echo "DONE"
