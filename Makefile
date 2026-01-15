CC = gcc
CFLAGS = -Wall -Wextra -g
LEX = flex

SRC_DIR = src
BUILD_DIR = build
TEST_DIR = tests

LEXER_SRC = $(SRC_DIR)/lexer/cryptolang.l
LEXER_C = $(BUILD_DIR)/lexer.c

TS_SRC = $(SRC_DIR)/symbol_table/ts.c
MAIN_SRC = $(SRC_DIR)/main.c

CRYPTOLANG = $(BUILD_DIR)/cryptolang
TEST_TS = $(BUILD_DIR)/test_ts
TEST_SEM = $(BUILD_DIR)/test_semantic

all: $(CRYPTOLANG) tests

$(LEXER_C): $(LEXER_SRC)
	@mkdir -p $(BUILD_DIR)
	$(LEX) -o $@ $<

$(CRYPTOLANG): $(LEXER_C) $(TS_SRC) $(MAIN_SRC)
	$(CC) $(CFLAGS) -I $(SRC_DIR)/lexer $(LEXER_C) $(TS_SRC) $(MAIN_SRC) -o $@

$(TEST_TS): $(TEST_DIR)/test_ts.c $(TS_SRC) $(LEXER_C)
	$(CC) $(CFLAGS) -I $(SRC_DIR)/lexer -I $(SRC_DIR)/symbol_table \
	    $(TEST_DIR)/test_ts.c $(TS_SRC) $(LEXER_C) -o $@

$(TEST_SEM): $(TEST_DIR)/test_semantic.c $(TS_SRC) $(LEXER_C)
	$(CC) $(CFLAGS) -I $(SRC_DIR)/lexer -I $(SRC_DIR)/symbol_table \
	    $(TEST_DIR)/test_semantic.c $(TS_SRC) $(LEXER_C) -o $@

tests: $(TEST_TS) $(TEST_SEM)

clean:
	rm -rf $(BUILD_DIR)