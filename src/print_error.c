/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdestreb <rdestreb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/26 11:21:21 by rdestreb          #+#    #+#             */
/*   Updated: 2015/10/26 11:21:25 by rdestreb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	print_error(char *msg)
{
	ft_putstr_fd("\033[31mft_select : Error : ", 2);
	ft_putendl_fd(msg, 2);
	exit(2);
}
