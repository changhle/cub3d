/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: changhle <changhle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 09:24:26 by changhle          #+#    #+#             */
/*   Updated: 2023/02/05 16:52:12 by changhle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include "libft.h"

#include "macro.h"

void	error_exit_with_str(char *str)
{
	ft_putstr_fd("Error\n", STDERR_FILENO);
	ft_putstr_fd(str, STDERR_FILENO);
	ft_putstr_fd("\n", STDERR_FILENO);
	exit(EXIT_FAILURE);
}

void	perror_exit(char *str)
{
	perror(str);
	exit(errno);
}
