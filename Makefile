CC = gcc
CFLAGS = -Wall -Wno-unused-function -g -Ibuild -Isrc/symbol_table -Isrc/lexer

LDFLAGS = -lfl

FLEX = flex
BISON = bison

SRC_DIR = src
LEXER_DIR = $(SRC_DIR)/lexer
SYMBOL_DIR = $(SRC_DIR)/symbol_table
BUILD_DIR = build
BIN_DIR = bin

LEXER_SRC = $(LEXER_DIR)/cryptolang.l
PARSER_SRC = $(LEXER_DIR)/cryptolang.y
SYMBOL_SRC = $(SYMBOL_DIR)/ts.c
MAIN_SRC = $(SRC_DIR)/main.c

LEXER_GEN = $(BUILD_DIR)/lex.yy.c
PARSER_GEN_C = $(BUILD_DIR)/y.tab.c
PARSER_GEN_H = $(BUILD_DIR)/y.tab.h

LEXER_OBJ = $(BUILD_DIR)/lex.yy.o
PARSER_OBJ = $(BUILD_DIR)/y.tab.o
SYMBOL_OBJ = $(BUILD_DIR)/ts.o
MAIN_OBJ = $(BUILD_DIR)/main.o

TARGET = $(BIN_DIR)/cryptolang

.PHONY: all clean test help directories

all: directories $(TARGET)

directories:
	@mkdir -p $(BUILD_DIR)
	@mkdir -p $(BIN_DIR)

$(TARGET): $(LEXER_OBJ) $(PARSER_OBJ) $(SYMBOL_OBJ) $(MAIN_OBJ)
	@echo "====================================================================="
	@echo " Linking..."
	@echo "====================================================================="
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)
	@echo "✓ Compilation réussie!"
	@echo "✓ Exécutable: $(TARGET)"
	@echo "====================================================================="

$(LEXER_GEN): $(LEXER_SRC)
	@echo "====================================================================="
	@echo " Generating Lexer from $(LEXER_SRC)..."
	@echo "====================================================================="
	$(FLEX) -o $@ $<

$(LEXER_OBJ): $(LEXER_GEN) $(PARSER_GEN_H)
	@echo "Compiling Lexer..."
	$(CC) $(CFLAGS) -I$(BUILD_DIR) -I$(SYMBOL_DIR) -c $< -o $@

$(PARSER_GEN_C) $(PARSER_GEN_H): $(PARSER_SRC)
	@echo "====================================================================="
	@echo " Generating Parser from $(PARSER_SRC)..."
	@echo "====================================================================="
	$(BISON) -d -o $(PARSER_GEN_C) $<

$(PARSER_OBJ): $(PARSER_GEN_C) $(PARSER_GEN_H)
	@echo "Compiling Parser..."
	$(CC) $(CFLAGS) -I$(BUILD_DIR) -I$(SYMBOL_DIR) -c $< -o $@

$(SYMBOL_OBJ): $(SYMBOL_SRC) $(SYMBOL_DIR)/ts.h
	@echo "====================================================================="
	@echo " Compiling Symbol Table..."
	@echo "====================================================================="
	$(CC) $(CFLAGS) -I$(SYMBOL_DIR) -c $< -o $@

$(MAIN_OBJ): $(MAIN_SRC) $(SYMBOL_DIR)/ts.h $(PARSER_GEN_H)
	@echo "====================================================================="
	@echo " Compiling Main..."
	@echo "====================================================================="
	$(CC) $(CFLAGS) -I$(BUILD_DIR) -I$(SYMBOL_DIR) -c $< -o $@

clean:
	@echo "Cleaning build files..."
	rm -rf $(BUILD_DIR) $(BIN_DIR)
	rm -f $(LEXER_DIR)/lex.yy.c
	@echo "✓ Clean complete!"

test: all
	@echo "====================================================================="
	@echo " Running Tests..."
	@echo "====================================================================="
	@if [ -f tests/test1.crypt ]; then \
		echo "Test 1: Basic Program"; \
		./$(TARGET) tests/test1.crypt; \
	else \
		echo "No test files found in tests/"; \
	fi

help:
	@echo "====================================================================="
	@echo " CryptoLang Compiler - Help"
	@echo "====================================================================="
	@echo " Usage:"
	@echo "   make              Compile the compiler"
	@echo "   make clean        Remove all build files"
	@echo "   make test         Run test files"
	@echo "   make help         Show this help message"
	@echo ""
	@echo " Running the compiler:"
	@echo "   ./$(TARGET) program.crypt          Full compilation"
	@echo "   ./$(TARGET) -l program.crypt       Lexer only"
	@echo "   ./$(TARGET) -p program.crypt       Parser only"
	@echo "====================================================================="