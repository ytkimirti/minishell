NAME = miniparser
BONUS_NAME =

# NOTE: Add -Werror here before pushing to intra
CFLAGS = -MD -Wall -Wextra -Ilibft -g
LDFLAGS = -Llibft
LDLIBS = -lft

# NOTE: You have to have libcriterion.a file in your LIBRARY_PATH and criterion.h file in C_INCLUDE_PATH
# If you installed them with homebrew, add them to these env variables in your shell config
TESTFLAGS = -lcriterion

CC = gcc
SHELL = /bin/sh

SRC_DIR = src
OBJ_DIR = obj
TEST_DIR = tests

ENTRY_SRCS = $(SRC_DIR)/main.c

BONUS_ENTRY_SRCS =

# NOTE: Write there with your hand when you are done!
# SRCS = src/summer.c
# You SHALL NOT include main
# SRCS := $(wildcard $(SRC_DIR)/*.c)
SRCS = $(SRC_DIR)/tokenizer.c \
		$(SRC_DIR)/tokenize_word.c \
		$(SRC_DIR)/tokenize_space.c \
		$(SRC_DIR)/tokenize_var.c \

TEST_UTILS_SRCS = $(TEST_DIR)/test_utils.c
TEST_SRCS = $(TEST_DIR)/test_tokenize_word.c \
			$(TEST_DIR)/test_tokenizer.c

TEST_UTILS_OBJS = $(patsubst $(TEST_DIR)/%.c, $(TEST_DIR)/obj/%.o, $(TEST_UTILS_SRCS))

BONUS_ENTRY_OBJS = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(BONUS_ENTRY_SRCS))
ENTRY_OBJS = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(ENTRY_SRCS))
OBJS = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRCS))
TEST_BINS = $(patsubst $(TEST_DIR)/%.c, $(TEST_DIR)/bin/%, $(TEST_SRCS))

INPUTS_DIR = tests/inputs

all: $(NAME)
bonus: $(BONUS_NAME)

$(BONUS_NAME): $(OBJS) $(BONUS_ENTRY_OBJS) libft/libft.a
	$(CC) $(LDFLAGS) $(LDLIBS) $(OBJS) $(BONUS_ENTRY_OBJS) -o $@

$(NAME): $(OBJS) $(ENTRY_OBJS) libft/libft.a
	$(CC) $(LDFLAGS) $(LDLIBS) $(OBJS) $(ENTRY_OBJS) -o $@

libft/libft.a:
	make -C libft

$(OBJ_DIR):
	mkdir $(OBJ_DIR)

$(TEST_DIR)/bin:
	mkdir $(TEST_DIR)/bin

$(TEST_DIR)/obj:
	mkdir $(TEST_DIR)/obj

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# For TEST_UTILS_OBJS
$(TEST_DIR)/obj/%.o: $(TEST_DIR)/%.c | $(TEST_DIR)/obj
	$(CC) $(CFLAGS) -c $< -o $@

$(TEST_DIR)/bin/%: $(TEST_DIR)/%.c $(OBJS) $(TEST_UTILS_OBJS) | $(TEST_DIR)/bin
	$(CC) $(CFLAGS) $(LDLIBS) $(LDFLAGS) $(TESTFLAGS) $(OBJS) $(TEST_UTILS_OBJS) $< -o $@

test: $(TEST_BINS)
	for test in $(TEST_BINS) ; do ./$$test ; done

testv: $(TEST_BINS)
	for test in $(TEST_BINS) ; do ./$$test --verbose ; done

run: all
	./miniparser < $(INPUTS_DIR)/basic1.txt

# re_nolog: CFLAGS += -DLOG=false

re: fclean all

clean:
	rm -rf $(OBJ_DIR) $(TEST_DIR)/bin

fclean: clean
	rm -f $(NAME)

-include $(OBJ_DIR)/*.d
