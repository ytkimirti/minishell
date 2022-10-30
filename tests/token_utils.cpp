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

