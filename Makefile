# Compilation parameters.
CC = gcc
CC_OUT = miniC
CC_FLAGS = -lfl -o $(CC_OUT) -I header/ -g
CC_SRC = src/main.c src/sem.c src/codegen.c $(LEX_OUT) $(SYN_OUT)

# Lexical parameters.
LEX_GEN = flex
LEX_SRC = src/lex.l
LEX_OUT = src/lex.c
LEX_FLAGS = -o $(LEX_OUT)

# Sintactical parameters.
SYN_GEN = bison
SYN_SRC = src/syn.y
SYN_OUT = src/syn.c
SYN_GRAMMAR = test/grammar.txt
SYN_HEADER = header/tokens.h
SYN_FLAGS = -o $(SYN_OUT) --header=$(SYN_HEADER) --report=states --report-file=$(SYN_GRAMMAR)

## -------------------------------------- ##

$(CC_OUT): $(CC_SRC)
	@$(CC) $(CC_FLAGS) $(CC_SRC)

$(LEX_OUT): $(LEX_SRC)
	@$(LEX_GEN) $(LEX_FLAGS) $(LEX_SRC)

$(SYN_OUT) $(SYN_HEADER): $(SYN_SRC)
	@$(SYN_GEN) $(SYN_FLAGS) $(SYN_SRC)

## -------------------------------------- ##

.PHONY: clean test memcheck debug

TEST_SCRIPT = test/test.sh
MEMTEST_SCRIPT = test/memtest.sh

clean:
	@rm $(CC_OUT) $(LEX_OUT) $(SYN_OUT) $(SYN_HEADER) $(SYN_GRAMMAR)

test: $(TEST_SCRIPT) $(CC_OUT)
	@./$(TEST_SCRIPT)

memtest: $(MEMTEST_SCRIPT) $(CC_OUT)
	@./$(MEMTEST_SCRIPT)

debug: $(CC_SRC)
	@$(CC) $(CC_FLAGS) -Wall $(CC_SRC)