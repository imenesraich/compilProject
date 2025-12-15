CC = gcc
CFLAGS = -Wall -Wextra -g
LEX = flex

SRC_DIR = src
BUILD_DIR = build
TEST_DIR = tests

LEXER_SRC = $(SRC_DIR)/lexer/cryptolang.l
LEXER_C = $(BUILD_DIR)/lexer.c

TS_SRC = $(SRC_DIR)/symbol_table/ts.c
TS_HDR = $(SRC_DIR)/symbol_table/ts.h

MAIN_SRC = $(SRC_DIR)/main.c

CRYPTOLANG = $(BUILD_DIR)/cryptolang
TEST_TS = $(BUILD_DIR)/test_ts
TEST_SEM = $(BUILD_DIR)/test_semantic

all: $(CRYPTOLANG)

$(LEXER_C): $(LEXER_SRC)
	@mkdir -p $(BUILD_DIR)
	$(LEX) -o $@ $<

$(CRYPTOLANG): $(LEXER_C) $(TS_SRC) $(MAIN_SRC)
	$(CC) $(CFLAGS) $^ -o $@

$(TEST_TS): $(TEST_DIR)/test_ts.c $(TS_SRC)
	$(CC) $(CFLAGS) $^ -o $@

$(TEST_SEM): $(TEST_DIR)/test_semantic.c $(TS_SRC)
	$(CC) $(CFLAGS) $^ -o $@

tests: $(TEST_TS) $(TEST_SEM)

clean:
	rm -rf $(BUILD_DIR)