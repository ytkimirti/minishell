NAME = minishell
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

TEST_DIR = tests

ENTRY_SRCS = $(SRC_DIR)/main.c

# NOTE: Write there with your hand when you are done!
# SRCS = src/summer.c
# You SHALL NOT include main
# SRCS := $(wildcard $(SRC_DIR)/*.c)
SRCS = $(SRC_DIR)/tokenizer.c \
		$(SRC_DIR)/tokenize_word.c \
		$(SRC_DIR)/tokenize_space.c \
		$(SRC_DIR)/utils_print.c \
		$(SRC_DIR)/tokenize_var.c \
		$(SRC_DIR)/parser.c \
		$(SRC_DIR)/executer.c \
		$(SRC_DIR)/utils.c \

OBJ_DIR	:=	obj
SRC_DIR	:=	src

MODULES   := parser executer tokenizer utils
SRC_DIRS   := $(addprefix src/,$(MODULES))
OBJ_DIRS := $(addprefix obj/,$(MODULES))

SRCS       := $(foreach sdir,$(SRC_DIRS),$(wildcard $(sdir)/*.c))
OBJS       := $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRCS))
INCLUDES  := $(addprefix -I,$(SRC_DIRS))

TEST_UTILS_SRCS = $(TEST_DIR)/test_utils.c
TEST_SRCS = $(TEST_DIR)/test_tokenize_word.c \
			$(TEST_DIR)/test_tokenizer.c \
			$(TEST_DIR)/test_parser.c \

TEST_UTILS_OBJS = $(patsubst $(TEST_DIR)/%.c, $(TEST_DIR)/obj/%.o, $(TEST_UTILS_SRCS))

BONUS_ENTRY_OBJS = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(BONUS_ENTRY_SRCS))
ENTRY_OBJS = $(patsubst $(SRC_DIR)/%.c, obj/%.o, $(ENTRY_SRCS))
# OBJS = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRCS))
TEST_BINS = $(patsubst $(TEST_DIR)/%.c, $(TEST_DIR)/bin/%, $(TEST_SRCS))

INPUTS_DIR = tests/inputs

vpath %.c $(SRC_DIRS)

all: $(NAME)
bonus: $(BONUS_NAME)

# Here is the actual compile rule. This is only for stuff in src/*/*.c

checkdirs: $(OBJ_DIRS)
	@echo obj: $(OBJ_DIR) $(OBJ_DIRS)
	@echo src: $(SRC_DIR) $(SRC_DIRS)
	@echo "All srcs: " $(SRCS)
	@echo "All objs: " $(OBJS)
	@echo "All includes: " $(INCLUDES)

define make-goal
$1/%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $$< -o $$@
endef

$(foreach bdir,$(OBJ_DIRS),$(eval $(call make-goal,$(bdir))))

$(OBJ_DIRS):
	mkdir -p $@

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

# Only for $(ENTRY_SRCS)
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# For TEST_UTILS_OBJS
$(TEST_DIR)/obj/%.o: $(TEST_DIR)/%.c | $(TEST_DIR)/obj
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(TEST_DIR)/bin/%: $(TEST_DIR)/%.c $(OBJS) $(TEST_UTILS_OBJS) | $(TEST_DIR)/bin
	$(CC) $(CFLAGS) $(LDLIBS) $(LDFLAGS) $(INCLUDES) $(TESTFLAGS) $(OBJS) $(TEST_UTILS_OBJS) $< -o $@

test: $(TEST_BINS)
	for test in $(TEST_BINS) ; do ./$$test ; done

testv: $(TEST_BINS)
	for test in $(TEST_BINS) ; do ./$$test --verbose ; done

run: all
	./$(NAME) < $(INPUTS_DIR)/basic1.txt

# re_nolog: CFLAGS += -DLOG=false

difftester/print_args: difftester/print_args.c
	$(CC) $< -o $@

re: fclean all

clean:
	rm -rf $(TEST_DIR)/obj
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)
	rm -rf $(TEST_DIR)/bin

-include $(OBJ_DIR)/*.d

.PHONY: all re clean fclean checkdirs run test testv
