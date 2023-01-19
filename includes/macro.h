/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   macro.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljeongin <ljeongin@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 09:12:16 by ljeongin          #+#    #+#             */
/*   Updated: 2022/11/02 09:12:17 by ljeongin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MACRO_H
# define MACRO_H

# ifndef STDIN_FILENO
#  define STDIN_FILENO 0
# endif

# ifndef STDOUT_FILENO
#  define STDOUT_FILENO 1
# endif

# ifndef STDERR_FILENO
#  define STDERR_FILENO 2
# endif

# ifndef EXIT_SUCCESS
#  define EXIT_SUCCESS 0
# endif

# ifndef EXIT_FAILURE
#  define EXIT_FAILURE 1
# endif

typedef enum e_bool			t_bool;

enum e_bool
{
	FALSE = 0,
	TRUE
};

#endif
