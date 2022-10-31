#include <cstring>
#include <string>
extern "C" 
{
#include "utils.h"
#include "token.h"
#include "tokenize_state.h"
#include "tokenizer.h"
#include "tokenizer_funcs.h"
#include "colors.h"
#include "command.h"
}
#include "gtest/gtest.h"
#include "../libs/googletest/googletest/include/gtest/gtest.h"

std::ostream& operator<<(std::ostream& stream, const t_token& token)
{
	stream << YEL << "{" << RST;

	stream << " .type = " << MAG << token_type_tostr(token.type) << RST;

	if (is_printable(token.type))
	{
		std::string str(token.str, token.len);
		if (token.str == nullptr)
			stream << " .str = " << RED << "NULL" << RST;
		else
			stream << " .str = " << GRN << "\"" << std::string(token.str, token.len) << "\"" << RST;

		stream << " .len = " << MAG << token.len << RST;
	}

	stream << YEL << " }" << RST;

  	return stream;
}

bool operator==( const t_token& a, const t_token& b )
{
	if (a.type != b.type)
		return false;
	if (is_printable(a.type))
		return a.len == b.len && a.len >= 0 && b.len >= 0 && strncmp(a.str, b.str, a.len) == 0;
    return true;
}

bool operator==( const t_command& a, const t_command& b )
{
	if (a.argc != b.argc)
		return false;
	if (a.redir_file != NULL && b.redir_file != NULL && strcmp(a.redir_file, b.redir_file) != 0)
		return false;
	if (a.redir_file == NULL && b.redir_file != NULL)
		return false;
	if (b.redir_file == NULL && a.redir_file != NULL)
		return false;
	for (int i = 0; i < a.argc; i++)
	{
		if (strcmp(a.argv[i], b.argv[i]) != 0)
			return false;
	}
	return true;
}

std::ostream& operator<<(std::ostream& stream, const t_command& command)
{
	stream << YEL << "(t_command) {" << RST;

	if (command.redir_file == NULL)
		stream << " .redir_file = " << RED << "NULL" << RST << ", ";
	else
	{
		stream << " .redir_file = " << GRN << command.redir_file << RST << ", ";
		stream << " .redir_type = " << MAG << redir_type_tostr(command.redir_type) << RST << ", ";
	}
	stream << " .argc = " << MAG << command.argc << RST;

	stream << " .argv = [" << std::endl;
	for (int i = 0; i < command.argc; i++)
	{
		stream << GRN << "        \"" << command.argv[i] << "\",\n" << RST;
	}
	stream << "    ]" << std::endl;

	stream << YEL << "}\n" << RST;

  	return stream;
}
