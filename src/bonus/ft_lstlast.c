/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pudry <pudry@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 21:41:48 by pudry             #+#    #+#             */
/*   Updated: 2024/09/11 21:41:48 by pudry            ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list_lft	*ft_lstlast(t_list_lft *lst)
{
	t_list_lft	*ptr;

	ptr = lst;
	while (ptr)
	{
		if (!ptr->next)
			return (ptr);
		ptr = ptr->next;
	}
	return (lst);
}
