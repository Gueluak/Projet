/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmarot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/14 12:04:11 by hmarot            #+#    #+#             */
/*   Updated: 2016/04/05 10:18:20 by hmarot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	push_buff(char c, t_env *env)
{
//	write(1, "b", 1);
	if (env->pos < BUFF_SIZE)
	{
		env->buffer[env->pos] = c;
		++(env->pos);
	}
	else
	{
		write(1, env->buffer, BUFF_SIZE);
		env->pos = 0;
		push_buff(c, env);
	}
}

int		char_chr(char c, char *chr)
{
//	write(1, "c", 1);
	int		i;

	i = 0;
	while (chr[i])
	{
		if (c == chr[i])
			return (i);
		++i;
	}
	return (-1);
}

void	aply_signe(long nb, t_env *env)
{
	if (nb < 0)
		push_buff('-', env);
	else if (env->flag & MORE)
		push_buff('+', env);
	else if (env->flag & SPACE)
		push_buff(' ', env);
}

int		nb_len(long nb)
{
	long	tmp;
	int		i;

	tmp = nb < 0 ? -nb : nb;
	i = 1;
	while(tmp >= 10)
	{
		(tmp = tmp / 10);
		++i;
	}
	return (i);
}

void	prf_itoa(long nb, t_env *env)
{
	long	tmp;
	long	i;

	i = 0;
	tmp = nb < 0 ? -nb : nb;
	//nb < 0 ? push_buff('-', env) : 0;
	if (tmp >= 10)
		prf_itoa(tmp / 10, env);
	push_buff((tmp % 10 + '0'), env);
}