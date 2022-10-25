#ifndef TEST_UTILS_HPP

# define TEST_UTILS_HPP

#include <cstring>
#include <string>

extern "C" 
{
#include "token.h"
}

std::ostream& operator<<(std::ostream& stream, const t_token& token);

bool operator==( const t_token& a, const t_token& b);

#endif
