# minishell
![norminette](https://github.com/ytkimirti/minishell/actions/workflows/norminette.yml/badge.svg)
![build](https://github.com/ytkimirti/minishell/actions/workflows/compile.yml/badge.svg)

A simple bash like shell
Features:
- Quotes `"` and `'`, environment variables with `$`
- `export a=b` and `unset`
- Pipes `|`, and `&&`, or `||`
- Parens for additional forking `(ls && echo heyo) | cat`
- Redirections `<` `>>` `>` and heredoc `<<`

Some stuff we use:
- A hashmap to store environment variables for faster access
- A cached path for faster command search
- No unnecesarry copies for things like envp generation, always using pointer references
- Unit testing with google test framework for testing tokenizer, parser and the hashmap
- Github Actions for automating tests and norminette linting.

## Installation

```sh
git clone git@github.com:ytkimirti/minishell.git --recursive
cd minishell
make
./minishell
```

To run the tests, you have to have a C++ compiler

```sh
make test
```

## Differences from bash

- It does not support word splitting.
- Redirections after parentheses does not work like `(ls) >out`
- Multiple readlines opening with `cat <<a | cat <<b`
- `echo` and `exit` command flags
- Handling of the signal `SIGQUIT`
