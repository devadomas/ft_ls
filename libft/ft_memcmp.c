/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaliaus <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 18:01:49 by azaliaus          #+#    #+#             */
/*   Updated: 2018/04/03 18:38:10 by azaliaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t		i;
	char		*o_s1;
	char		*o_s2;
	int			ret;

	i = 0;
	ret = 0;
	o_s1 = (void *)s1;
	o_s2 = (void *)s2;
	while (i++ < n)
	{
		ret = *(unsigned char *)o_s1 - *(unsigned char *)o_s2;
		if (ret)
			return (ret);
		o_s1++;
		o_s2++;
	}
	return (ret);
}
