/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   acl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaliaus <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/30 12:39:43 by azaliaus          #+#    #+#             */
/*   Updated: 2018/04/30 12:50:15 by azaliaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include <sys/acl.h>

void		print_acl(t_file *file)
{
	ssize_t xattr;
	acl_t	acl;

	if (!file)
	{
		ft_putchar(' ');
		return ;
	}
	xattr = listxattr(file->path, NULL, 0, XATTR_NOFOLLOW);
	acl = acl_get_file(file->path, ACL_TYPE_EXTENDED);
	if (xattr > 0)
		ft_putchar('@');
	else if (acl)
	{
		ft_putchar('+');
		acl_free(acl);
	}
	else
		ft_putchar(' ');
}
