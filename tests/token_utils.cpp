/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_utils.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykimirti <ykimirti@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 16:42:12 by ykimirti          #+#    #+#             */
/*   Updated: 2022/11/08 16:46:27 by ykimirti         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

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

void detailed_compare(char *a, char *b)
{
	printf("\"%s\"\n", a);
	int j = 0;
	printf(" ");
	while (a[j] != '\0' && b[j] != '\0' && a[j] == b[j])
	{
		printf(" ");
		j++;
	}
	if (a[j] == '\0' && b[j] == '\0')
		printf("what??\n");
	printf(RED "↕\n" RST);
	printf("\"%s\"\n", b);
	printf("%d != %d\n", (int)a[j], (int)b[j]);
}

bool operator==( const t_command& a, const t_command& b )
{
	if (a.argc != b.argc)
		return false;
	if (a.in_file != NULL && b.in_file != NULL && strcmp(a.in_file, b.in_file) != 0)
		return false;
	if ((a.in_file != NULL && b.in_file == NULL) || (a.in_file == NULL && b.in_file != NULL))
		return false;
	if (a.out_file != NULL && b.out_file != NULL && strcmp(a.out_file, b.out_file) != 0)
		return false;
	if ((a.out_file != NULL && b.out_file == NULL) || (a.out_file == NULL && b.out_file != NULL))
		return false;
	if (a.is_append != b.is_append)
		return false;
	for (int i = 0; i < a.argc; i++)
	{
		if (strcmp(a.argv[i], b.argv[i]) != 0)
		{
			return false;
		}
	}
	return true;
}

std::ostream& operator<<(std::ostream& stream, const t_command& command)
{
	stream << YEL << "(t_command) {" << RST;

	if (command.in_file != NULL)
		stream << "in_file = " << GRN << "\"" << command.in_file << "\"" << RST << ", ";
	if (command.out_file != NULL)
		stream << "out_file = " << GRN << "\"" << command.out_file << "\"" << RST << ", ";
	stream << "is_append = " << MAG << (command.is_append ? "false" : "true") << RST << ", ";

	stream << "argc = " << MAG << command.argc << RST << ", ";

	stream << "argv = [" << std::endl;
	for (int i = 0; i < command.argc; i++)
	{
		stream << GRN << "        \"" << command.argv[i] << "\"" << RST << ",\n";
	}
	stream << "    ]" << std::endl;

	stream << YEL << "}\n" << RST;

  	return stream;
}
