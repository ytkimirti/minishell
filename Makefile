NAME = minishell

GTEST = libs/googletest

FT_DIR = libft
READLINE_DIR = libs/readline
GTEST_DIR = libs/googletest

LIB_FT = $(FT_DIR)/libft.a
LIB_READLINE = $(READLINE_DIR)/libreadline.a
LIB_GTEST = $(GTEST_DIR)/build/lib/libgtest.a $(GTEST)/build/lib/libgtest_main.a

TEST_CFLAGS = -std=c++11 -Ilibft -I$(GTEST)/googletest/include -g
TEST_LDFLAGS = -pthread -ltermcap

CFLAGS = -MD -Wall -Wextra -Werror -I$(FT_DIR) -Ilibs -g

# readline requires that it's linked with termcap
# LDFLAGS = -Llibft -fsanitize=address -ltermcap
LDFLAGS = -ltermcap

CC = gcc
SHELL = /bin/sh

TEST_DIR = tests

OBJ_DIR	:=	obj
SRC_DIR	:=	src


MODULES   := parser executer tokenizer utils map prompt command ast built_in env error print wildcard new

SRC_DIRS   := $(addprefix src/,$(MODULES))
OBJ_DIRS := $(addprefix obj/,$(MODULES))

# SRCS       := $(foreach sdir,$(SRC_DIRS),$(wildcard $(sdir)/*.c))
SRCS       := src/ast/builder.c src/ast/builder_utils.c src/ast/free_tree.c  \
src/ast/node_utils.c src/ast/print_tree.c src/ast/walk_logic.c  \
src/ast/walk_utils.c src/ast/walkers.c src/built_in/built_in.c  \
src/built_in/ft_cd.c src/built_in/ft_echo.c src/built_in/ft_env.c  \
src/built_in/ft_exit.c src/built_in/ft_export.c src/built_in/ft_path.c  \
src/built_in/ft_pwd.c src/built_in/ft_unset.c src/command/execute.c  \
src/command/execute_builtin.c src/command/file_open.c src/command/free_command.c  \
src/env/cached_path.c src/env/env_singleton.c src/env/extract_env.c  \
src/env/get_env.c src/env/get_env_length.c src/env/init_env.c src/env/path.c  \
src/env/pwd.c src/env/set_env.c src/env/unset_env.c src/error/error.c  \
src/error/singleton.c src/error/trace.c src/error/unexpected.c  \
src/map/copy_map.c src/map/create_map.c src/map/destroy_map.c src/map/hashing.c  \
src/map/map_get.c src/map/map_insert.c src/map/map_remove.c src/map/map_select.c  \
src/new/is_next_pipeline.c src/new/jumpers.c src/new/new.c  \
src/new/parse_and_run.c src/parser/append_to_pvec.c src/parser/expand.c  \
src/parser/expand_tokens.c src/parser/is_command_token.c  \
src/parser/is_redir_token.c src/parser/is_wildcard_argument.c  \
src/parser/length.c src/parser/parser.c src/parser/skip_spaces.c  \
src/parser/strlencpy.c src/print/print.c src/print/token_colors.c  \
src/prompt/git_status.c src/prompt/git_status_format.c src/prompt/prompt.c  \
src/prompt/replace_prefix.c src/tokenizer/free_tokens.c  \
src/tokenizer/metacharacter.c src/tokenizer/token.c  \
src/tokenizer/tokenize_control.c src/tokenizer/tokenize_paren.c  \
src/tokenizer/tokenize_pipe.c src/tokenizer/tokenize_quote.c  \
src/tokenizer/tokenize_redir.c src/tokenizer/tokenize_space.c  \
src/tokenizer/tokenize_var.c src/tokenizer/tokenize_wildcard.c  \
src/tokenizer/tokenize_word.c src/tokenizer/tokenizer.c src/utils/close.c  \
src/utils/node_type_tostr.c src/utils/print_token.c src/utils/utils.c  \
src/utils/utils_print.c src/wildcard/check_end.c src/wildcard/check_match.c  \
src/wildcard/check_start.c src/wildcard/compare_char.c  \
src/wildcard/vector_append_all.c src/wildcard/wildcard.c  

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
	$(CC) $(OBJS) $(ENTRY_OBJS) $(LIB_FT) $(LIB_READLINE) $(LDFLAGS) -o $@

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

$(TEST_BIN): $(TEST_OBJS) $(OBJS) $(LIB_GTEST) $(LIB_READLINE)
	@echo "==== LINKING TEST FILES ===="
	g++ $(TEST_CFLAGS) $(OBJS) $(TEST_OBJS) $(LIB_GTEST) $(LIB_FT) $(LIB_READLINE) $(TEST_LDFLAGS) -o $@

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
	@norminette src | grep Error || ( (command -v &>/dev/null && cowsay "All clear" ) || echo "(ﾉ◕ヮ◕)ﾉ*:･ﾟ✧ All clear")

# -include $(foreach odir,$(OBJ_DIRS),$(wildcard $(odir)/*.d))

.PHONY: all re clean fclean checkdirs run test testerr maketest norm
