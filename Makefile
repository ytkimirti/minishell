NAME = minishell

GTEST = libs/googletest

FT_DIR = libft
READLINE_DIR = libs/readline
GTEST_DIR = libs/googletest

LIB_FT = $(FT_DIR)/libft.a
LIB_READLINE = $(READLINE_DIR)/libreadline.a
LIB_GTEST = $(GTEST_DIR)/build/lib/libgtest.a $(GTEST)/build/lib/libgtest_main.a

TEST_CFLAGS = -std=c++11 -Ilibft -I$(GTEST)/googletest/include -g
TEST_LDFLAGS = -pthread -lreadline

CFLAGS = -MD -Wall -Wextra -Werror -I$(FT_DIR) -Ilibs -g

# readline requires that it's linked with termcap
# LDFLAGS = -Llibft -fsanitize=address -ltermcap
LDFLAGS = -ltermcap

CC = gcc
SHELL = /bin/sh

TEST_DIR = tests

OBJ_DIR	:=	obj
SRC_DIR	:=	src

MODULES   := parser executer tokenizer utils map prompt command ast built_in env error
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

$(NAME): $(OBJS) $(ENTRY_OBJS) $(LIB_FT) $(LIB_READLINE)
	$(CC) $(OBJS) $(ENTRY_OBJS) $(LDFLAGS) $(LIB_FT) $(LIB_READLINE) -o $@

$(LIB_FT):
	make -C $(FT_DIR)

$(LIB_GTEST):
	mkdir -p $(GTEST_DIR)/build
	cd $(GTEST_DIR)/build; \
		cmake ..; \
		make

$(LIB_READLINE):
	cd $(READLINE_DIR); \
	./configure --with-curses; \
	make; \
	rm -f history.pc

maketest: $(TEST_BIN)

test: $(TEST_BIN)
	./$(TEST_BIN)

testerr: $(TEST_BIN)
	./$(TEST_BIN) --gtest_brief=1

$(TEST_BIN): $(TEST_OBJS) $(OBJS) $(LIB_GTEST)
	@echo "==== LINKING TEST FILES ===="
	g++ $(TEST_CFLAGS) $(OBJS) $(TEST_OBJS) $(LIB_GTEST) $(LIB_FT) $(TEST_LDFLAGS) -o $@

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

-include $(foreach odir,$(OBJ_DIRS),$(wildcard $(odir)/*.d))

.PHONY: all re clean fclean checkdirs run test testerr maketest norm
