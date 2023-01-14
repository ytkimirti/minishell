#!/bin/bash

valgrind --suppressions=readline.supp --leak-check=full --show-leak-kinds=definite,indirect,possible ./minishell
