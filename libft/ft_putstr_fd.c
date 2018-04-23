/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaliaus <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 17:51:28 by azaliaus          #+#    #+#             */
/*   Updated: 2018/04/11 14:48:46 by azaliaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

void		ft_putstr_fd(char const *s, int fd)
{
	size_t		len;

	if (!s)
		return ;
	len = ft_strlen(s);
	write(fd, s, len);
}
