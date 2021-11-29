/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaker <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 13:25:26 by abaker            #+#    #+#             */
/*   Updated: 2021/11/16 12:12:21 by abaker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include <stdarg.h>
# include <stdbool.h>

typedef struct s_flags {
	char	type;
	bool	hash;
	bool	minus;
	bool	plus;
	bool	space;
	bool	zero;
	int		width;
	int		dot;
	bool	error;
}	t_flags;

int		ft_printf(const char *str, ...);
bool	ft_istype(char c);
bool	ft_isflag(char c);
int		ft_flagdot(const char *str, int i, t_flags *flags);
int		ft_flagwidth(const char *str, int i, t_flags *flags);
int		ft_printstr(char *str, int maxprint);
char	*ft_numtobase(unsigned long long n, char *base, bool cap);
int		ft_handletype(t_flags *flags, va_list args);
int		ft_handlechar(int c, t_flags *flags);
int		ft_handlestr(char *str, t_flags *flags);
int		ft_handleint(int n, t_flags *flags);
int		ft_handleuint(unsigned int n, t_flags *flags);
int		ft_handlepointer(unsigned long long ptr, t_flags *flags);
int		ft_handlehex(unsigned int n, t_flags *flags, bool cap);
int		ft_formatwidth(int width, int strlen, bool zero);

#endif
