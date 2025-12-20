# ============================================================
#   Project: Programmazione-2
#   Structure: src / include / lib / bin / executables
# ============================================================

# --- Compiler and flags ---
CC := clang
CFLAGS_DEBUG 	:= -std=c17 -Wall -Wextra -Wpedantic -O0 -g -fsanitize=address,undefined
CFLAGS_RELEASE 	:= -std=c17 -Wall -Wextra -Wpedantic -O2
INCLUDES 	:= -Iinclude

# --- Main directories ---
SRC_DIR         := src
INC_DIR         := include
LIB_DIR         := lib
BIN_DIR         := bin
BUILD_DIR       := build
EXEC_DIR        := executables

# --- Source and object files ---
SRC             := $(wildcard $(SRC_DIR)/*.c)
OBJ_DEBUG       := $(patsubst $(SRC_DIR)/%.c,$(BUILD_DIR)/debug/%.o,$(SRC))
OBJ_RELEASE     := $(patsubst $(SRC_DIR)/%.c,$(BUILD_DIR)/release/%.o,$(SRC))

# --- Static libraries ---
LIB_DEBUG       := $(LIB_DIR)/libds_debug.a
LIB_RELEASE     := $(LIB_DIR)/libds.a

# --- Executable sources and binaries ---
EXEC_SRC        := $(wildcard $(EXEC_DIR)/*.c)
EXEC_BIN_DEBUG  := $(patsubst $(EXEC_DIR)/%.c,$(BIN_DIR)/debug/%,$(EXEC_SRC))
EXEC_BIN_REL    := $(patsubst $(EXEC_DIR)/%.c,$(BIN_DIR)/release/%,$(EXEC_SRC))

# --- Phony targets ---
.PHONY: all debug release run executables executables-release clean
        # format tidy tidy-fix compile-commands coverage

# ============================================================
#   Library build rules
# ============================================================

all: debug

debug: $(LIB_DEBUG)
release: $(LIB_RELEASE)

# --- Compile source files into object files ---
$(BUILD_DIR)/debug/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS_DEBUG) $(INCLUDES) -c $< -o $@

$(BUILD_DIR)/release/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS_RELEASE) $(INCLUDES) -c $< -o $@

# --- Create static libraries ---
$(LIB_DEBUG): $(OBJ_DEBUG)
	@mkdir -p $(LIB_DIR)
	ar rcs $@ $^

$(LIB_RELEASE): $(OBJ_RELEASE)
	@mkdir -p $(LIB_DIR)
	ar rcs $@ $^

# ============================================================
#   Executables build and run rules
# ============================================================

# --- Build all executables (debug/release) ---
executables: debug $(EXEC_BIN_DEBUG)
executables-release: release $(EXEC_BIN_REL)

# --- Build a single executable (debug) ---
$(BIN_DIR)/debug/%: $(EXEC_DIR)/%.c $(LIB_DEBUG)
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS_DEBUG) $(INCLUDES) $< $(LIB_DEBUG) -o $@

# --- Build a single executable (release) ---
$(BIN_DIR)/release/%: $(EXEC_DIR)/%.c $(LIB_RELEASE)
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS_RELEASE) $(INCLUDES) $< $(LIB_RELEASE) -o $@


# --- Run one executable: make run NAME=<file-without-.c> ---
run: debug
	@if [ -z "$(NAME)" ]; then \
	  echo "Usa: make run NAME=<nome-senza-.c>  (es: make run NAME=list_demo)"; exit 1; \
	fi
	$(MAKE) $(BIN_DIR)/debug/$(NAME)
	./$(BIN_DIR)/debug/$(NAME)

# ============================================================
#   Static analysis / formatting / testing (currently disabled)
# ============================================================

# format:
# 	clang-format -i $(INC_DIR)/*.h $(SRC_DIR)/*.c $(EXEC_DIR)/*.c 2>/dev/null || true
#
# TIDY        	?= clang-tidy
# TIDY_HDR_RE 	?= ^(src/|include/)
# TIDY_STD    	?= -std=c17
# TIDY_COMMON 	:= -quiet -header-filter='$(TIDY_HDR_RE)'
# TIDY_P      	:= $(if $(wildcard $(BUILD_DIR)/compile_commands.json),-p $(BUILD_DIR),)
#
# tidy:
# 	@$(TIDY) $(TIDY_COMMON) $(TIDY_P) $(if $(FILE),$(FILE),$(SRC)) -- $(TIDY_STD) $(INCLUDES)
#
# tidy-fix:
# 	@$(TIDY) -fix $(TIDY_COMMON) $(TIDY_P) $(if $(FILE),$(FILE),$(SRC)) -- $(TIDY_STD) $(INCLUDES)
#
# compile-commands:
# 	@command -v bear >/dev/null 2>&1 || { echo "Install 'bear' first (sudo apt install bear)"; exit 1; }
# 	bear -- make debug
#
# test:
# 	@echo "Tests disabled for now (no files in tests/)."
#
# coverage:
# 	gcovr -r . --exclude 'tests/.*' --html --html-details -o $(BUILD_DIR)/coverage.html
# 	@echo "Coverage report generated in $(BUILD_DIR)/coverage.html"

# ============================================================
#   Clean target
# ============================================================

clean:
	rm -rf build
