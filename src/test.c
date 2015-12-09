/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdestreb <rdestreb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/19 14:51:53 by rdestreb          #+#    #+#             */
/*   Updated: 2015/11/19 15:24:46 by rdestreb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"
#include <stdio.h>

int	main(int ac, char **av, char **env)
{
	char	*term_name;
	char	stock[4];

	(void)ac;
	(void)av;
	(void)env;
	if (!(term_name = getenv("TERM")))
		print_error("No terminal specified (env. var. 'TERM' is missing ?)");
	printf("%s\n", term_name);
	if (tgetent(0, term_name) < 1)
		print_error("Can't access to the termcap data base");
	if (tcgetattr(0, &t_term) < 0)
		print_error("");
	t_term.c_lflag &= ~(ICANON | ECHO);
//	t_term.c_lflag &= ~(ECHO);
	t_term.c_cc[VMIN] = 1;
	t_term.c_cc[VTIME] = 0;
	if (tcsetattr(0, TCSADRAIN, &t_term) < 0)
		print_error("");
	printf("%d\n%d\n", tgetnum("li"), tgetnum("co"));
	printf("%d\n", tgetflag("am"));
	printf("%s\n", tgetstr("al", 0));
	while (42){
		if (read(0, stock, 3) < 0)
			print_error("read error");
//		if (stock[0] == 27)
		printf("%s\n", stock);
	}
	return (0);
}
