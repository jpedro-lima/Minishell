/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpedrones <jpedrones@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 20:23:48 by joapedr2          #+#    #+#             */
/*   Updated: 2022/11/15 13:24:35 by jpedrones        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* compare the value of two strings up to the 'n' slot
passed as an argument and returns the difference between
them, if no difference is found, 0 is returned */
int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (!s1 || !s2)
		return (-1);
	while (i < n)
	{
		if (s1[i] != s2[i] || s1[i] == '\0')
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		++i;
	}
	return (0);
}
