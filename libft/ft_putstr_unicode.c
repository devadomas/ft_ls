/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaliaus <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 17:51:28 by azaliaus          #+#    #+#             */
/*   Updated: 2018/04/21 20:13:01 by azaliaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>
#include <wchar.h>

void		ft_putstr_unicode(wchar_t const *s)
{
	if (!s)
		return ;
	while (*s)
		ft_putchar_unicode(*(s++));
}
