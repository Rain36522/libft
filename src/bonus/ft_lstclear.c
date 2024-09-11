/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pudry <pudry@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 21:41:23 by pudry             #+#    #+#             */
/*   Updated: 2024/09/11 21:41:23 by pudry            ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list_lft **lst, void (*del)(void *))
{
	t_list_lft	*ptr;
	t_list_lft	*tmp;

	if (lst)
	{
		ptr = *lst;
		while (ptr)
		{
			tmp = ptr->next;
			ft_lstdelone(ptr, del);
			ptr = tmp;
		}
		*lst = NULL;
	}
}
