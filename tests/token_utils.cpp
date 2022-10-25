#include <cstring>
#include <string>
extern "C" 
{
#include "utils.h"
#include "executer.h"
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
	stream << "{";

	stream << " .type = " << token_type_tostr(token.type);

	if (token.type & PRINTABLE)
	{
		std::string str(token.str, token.len);
		stream << " .str = \"" << std::string(token.str, token.len) << "\"";

		stream << " .len = " << token.len;
	}

	stream << " }";

  	return stream;
}

bool operator==( const t_token& a, const t_token& b )
{
	if (a.type != b.type)
		return false;
	if (a.type & PRINTABLE)
		return a.len == b.len && a.len >= 0 && b.len >= 0 && strncmp(a.str, b.str, a.len) == 0;
    return true;
}

