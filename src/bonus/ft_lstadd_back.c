/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pudry <pudry@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 21:41:13 by pudry             #+#    #+#             */
/*   Updated: 2024/09/11 21:41:13 by pudry            ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list_lft **lst, t_list_lft *new)
{
	t_list_lft	*ptr;

	if (new && !*lst)
		*lst = new;
	else if (new && *lst)
	{
		ptr = ft_lstlast(*lst);
		ptr->next = new;
	}
}
