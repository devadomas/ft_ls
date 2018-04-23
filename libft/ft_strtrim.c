/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaliaus <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 17:23:47 by azaliaus          #+#    #+#             */
/*   Updated: 2018/04/11 14:47:59 by azaliaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char		*ft_strtrim(char const *s)
{
	int			begin;
	int			end;
	char		*ret;
	char		*cpy;

	if (!s)
		return (NULL);
	begin = 0;
	while (s[begin] == ' ' || s[begin] == '\t' || s[begin] == '\n')
		begin++;
	end = ft_strlen(s) - 1;
	while (s[end] == ' ' || s[end] == '\t' || s[end] == '\n')
		end--;
	ret = (char *)malloc(sizeof(char) *
			((end - begin < 0 ? -1 : end - begin) + 2));
	if (!ret)
		return (NULL);
	cpy = ret;
	while (begin <= end)
		*(cpy++) = s[begin++];
	*cpy = '\0';
	return (ret);
}
