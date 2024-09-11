/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pudry <pudry@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 21:41:37 by pudry             #+#    #+#             */
/*   Updated: 2024/09/11 21:41:37 by pudry            ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_list_lft	*ft_lstcreate(t_list_lft *lst, void *(*f)(void *))
{
	t_list_lft	*ptr;

	ptr = (t_list_lft *) malloc(sizeof(t_list_lft));
	if (!ptr)
		return (NULL);
	ptr->content = f(lst->content);
	return (ptr);
}

static t_list_lft	*ft_malloc_empty(t_list_lft **lst, void (*del) (void *))
{
	if (lst)
		ft_lstclear(lst, del);
	return (NULL);
}

t_list_lft	*ft_lstmap(t_list_lft *lst, void *(*f)(void *), void (*del) (void *))
{
	t_list_lft	*ptr;
	t_list_lft	*new_lst;
	t_list_lft	*old_lst;
	t_list_lft	*tmp;

	if (!lst || !f || !del)
		return (NULL);
	new_lst = ft_lstcreate(lst, f);
	if (!new_lst)
		return (NULL);
	old_lst = lst->next;
	ptr = new_lst;
	while (old_lst)
	{
		ptr->next = 0;
		tmp = ft_lstcreate(old_lst, f);
		if (!tmp)
			return (ft_malloc_empty(&new_lst, del));
		ptr->next = tmp;
		ptr = ptr->next;
		old_lst = old_lst->next;
	}
	ptr->next = NULL;
	return (new_lst);
}
/*
void	del(void *content)
{
	free(content);
}
void	*f(void *chr)
{

	chr ++;
	return (chr);
}

void	ft_print(t_list_lft *ptr)
{
	int	i;

	i = 1;
	while (ptr)
	{
		printf("lst %i : %s\n", i, (char *)ptr->content);
		ptr = ptr->next;
		i ++;
	}	
}

int	main(void)
{
	int		i;
	t_list_lft	*ptr;
	t_list_lft	*lst;
	char	c[] = "a";

	i = 0;
	lst = NULL;
	ptr = ft_lstnew((char *) "a");
	lst = ptr;
	while (i < 5)
	{
		c[0] ++;
		ptr->next = ft_lstnew(c);
		printf("char : %s\n", c);
		ptr = ptr->next;
		i ++;	
	}
	printf("size : %i\n", ft_lstsize(lst));
	ptr = ft_lstmap(lst, f, del);
	printf("size : %i\n", ft_lstsize(ptr));
	ft_print(ptr);
	
	return (0);
}
*/