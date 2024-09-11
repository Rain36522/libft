/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pudry <pudry@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 21:41:40 by pudry             #+#    #+#             */
/*   Updated: 2024/09/11 21:41:40 by pudry            ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list_lft	*ft_lstnew(void *content)
{
	t_list_lft	*ptr;

	ptr = (t_list_lft *) malloc(sizeof(t_list_lft) * 1);
	if (!ptr)
		return (NULL);
	ptr->next = NULL;
	ptr->content = content;
	return (ptr);
}
