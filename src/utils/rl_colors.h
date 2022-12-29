/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rl_colors.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykimirti <42istanbul.com.tr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 18:31:06 by ykimirti          #+#    #+#             */
/*   Updated: 2022/12/29 14:56:09 by ykimirti         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RL_COLORS_H

# define RL_COLORS_H

// These colors are wrapped with \001 and \002 so readline
// knows how to handle non printing characters
//Regular text
# define RL_BLK "\001\e[0;30m\002"
# define RL_RED "\001\e[0;31m\002"
# define RL_GRN "\001\e[0;32m\002"
# define RL_YEL "\001\e[0;33m\002"
# define RL_BLU "\001\e[0;34m\002"
# define RL_MAG "\001\e[0;35m\002"
# define RL_CYN "\001\e[0;36m\002"
# define RL_WHT "\001\e[0;37m\002"

//Regular bold text
# define RL_BBLK "\001\e[1;30m\002"
# define RL_BRED "\001\e[1;31m\002"
# define RL_BGRN "\001\e[1;32m\002"
# define RL_BYEL "\001\e[1;33m\002"
# define RL_BBLU "\001\e[1;34m\002"
# define RL_BMAG "\001\e[1;35m\002"
# define RL_BCYN "\001\e[1;36m\002"
# define RL_BWHT "\001\e[1;37m\002"

//Regular underline text
# define RL_UBLK "\001\e[4;30m\002"
# define RL_URED "\001\e[4;31m\002"
# define RL_UGRN "\001\e[4;32m\002"
# define RL_UYEL "\001\e[4;33m\002"
# define RL_UBLU "\001\e[4;34m\002"
# define RL_UMAG "\001\e[4;35m\002"
# define RL_UCYN "\001\e[4;36m\002"
# define RL_UWHT "\001\e[4;37m\002"

//Regular backgroundd
# define RL_BLKB "\001\e[40m\002"
# define RL_REDB "\001\e[41m\002"
# define RL_GRNB "\001\e[42m\002"
# define RL_YELB "\001\e[43m\002"
# define RL_BLUB "\001\e[44m\002"
# define RL_MAGB "\001\e[45m\002"
# define RL_CYNB "\001\e[46m\002"
# define RL_WHTB "\001\e[47m\002"

# define RL_RST "\001\e[0m\002"

#endif
