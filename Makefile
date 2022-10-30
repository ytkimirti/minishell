NAME = minishell

# NOTE: Add -Werror here before pushing to intra
# CFLAGS = -MD -Wall -Wextra -Ilibft -g -fsanitize=address
CFLAGS = -MD -Wall -Wextra -Ilibft -g
# LDFLAGS = -Llibft -fsanitize=address
LDFLAGS = -Llibft
LDLIBS = -lft -lreadline

GTEST = libs/googletest
LIB_GTEST = $(GTEST)/build/lib/libgtest.a $(GTEST)/build/lib/libgtest_main.a
TEST_CFLAGS = -std=c++11 -Ilibft -I$(GTEST)/googletest/include -g
TEST_LDFLAGS = -pthread -lreadline

CC = gcc
SHELL = /bin/sh

TEST_DIR = tests

OBJ_DIR	:=	obj
SRC_DIR	:=	src

MODULES   := parser executer tokenizer utils map prompt
SRC_DIRS   := $(addprefix src/,$(MODULES))
OBJ_DIRS := $(addprefix obj/,$(MODULES))

SRCS       := $(foreach sdir,$(SRC_DIRS),$(wildcard $(sdir)/*.c))
OBJS       := $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRCS))

INCLUDES  := $(addprefix -I,$(SRC_DIRS))

ENTRY_SRCS = $(SRC_DIR)/main.c
ENTRY_OBJS = $(patsubst $(SRC_DIR)/%.c, obj/%.o, $(ENTRY_SRCS))

TEST_SRCS = $(wildcard $(TEST_DIR)/*.cpp)
TEST_OBJS = $(patsubst $(TEST_DIR)/%.cpp, $(TEST_DIR)/obj/%.o, $(TEST_SRCS))
TEST_BIN = $(TEST_DIR)/test

INPUTS_DIR = tests/inputs

vpath %.c $(SRC_DIRS)

all: $(NAME)

# Here is the actual compile rule. This is only for stuff in src/*/*.c

checkdirs: $(OBJ_DIRS)
	@echo obj: $(OBJ_DIR) $(OBJ_DIRS)
	@echo src: $(SRC_DIR) $(SRC_DIRS)
	@echo "All srcs: " $(SRCS)
	@echo "All objs: " $(OBJS)
	@echo "All includes: " $(INCLUDES)

define make-goal
$1/%.o: %.c | $(OBJ_DIRS)
	$(CC) $(CFLAGS) $(INCLUDES) -c $$< -o $$@
endef

$(foreach bdir,$(OBJ_DIRS),$(eval $(call make-goal,$(bdir))))

$(NAME): $(OBJS) $(ENTRY_OBJS) libft/libft.a
	$(CC) $(OBJS) $(ENTRY_OBJS) $(LDFLAGS) $(LDLIBS) -o $@

libft/libft.a:
	make -C libft

$(GTEST)/build/lib/libgtest_main.a:
	mkdir -p $(GTEST)/build
	cd $(GTEST)/build && cmake .. && make

maketest: $(TEST_BIN)

test: $(TEST_BIN)
	./$(TEST_BIN)

$(TEST_BIN): $(TEST_OBJS) $(OBJS) $(GTEST)/build/lib/libgtest_main.a libft/libft.a
	@echo "==== LINKING TEST FILES ===="
	g++ $(TEST_CFLAGS) $(OBJS) $(TEST_OBJS) $(LIB_GTEST) libft/libft.a $(TEST_LDFLAGS) -o $@

$(TEST_DIR)/obj/%.o: $(TEST_DIR)/%.cpp | $(TEST_DIR)/obj
	g++ $(TEST_CFLAGS) $(INCLUDES) -c $< -o $@  

# Rules for making directiories
$(OBJ_DIRS) $(OBJ_DIR) $(TEST_DIR)/bin $(TEST_DIR)/obj:
	mkdir -p $@

# Only for $(ENTRY_SRCS)
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

run: all
	./$(NAME) < $(INPUTS_DIR)/basic1.txt

# re_nolog: CFLAGS += -DLOG=false

difftester/print_args: difftester/print_args.c
	$(CC) $< -o $@

re: fclean all

clean:
	rm -rf $(TEST_DIR)/obj
	rm -rf $(OBJ_DIR)
	rm -f difftester/print_args

fclean: clean
	rm -f $(NAME)
	rm -rf $(TEST_DIR)/bin

norm:
	norminette src | grep Error

# -include $(OBJ_DIR)/*.d
-include $(foreach odir,$(OBJ_DIRS),$(wildcard $(odir)/*.d))

.PHONY: all re clean fclean checkdirs run test maketest norm
