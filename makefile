test: carg-parse.c carg-parse.h test.c
	@echo "BUILDING"
	@clang ./test.c ./carg-parse.c -o ./test
	@echo "DONE"

stress:
	@make test
	@echo "STRESSING - if you see any errors / segfaults / fuckups please revert changes or open an issue"
	@./stress.sh
