/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isInt.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pudry <pudry@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 15:53:46 by pudry             #+#    #+#             */
/*   Updated: 2024/08/07 15:56:31 by pudry            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_check_max_size(char *str, int isn)
{
	if (isn == -1)
		return (ft_strcmp("2147483648", str) >= 0);
	return (ft_strcmp("2147483647", str) >= 0);
}

int	ft_isint(char *str)
{
	int	isnegatif;

	isnegatif = 1;
	if (*str == '-')
		isnegatif = -1;
	if (*str == '-' || *str == '+')
		str ++;
	if (!*str)
		return (0);
	while (*str == '0')
		str ++;
	if (ft_strlen(str) > 10)
		return (0);
	else if (ft_strlen(str) == 10)
		if (!ft_check_max_size(str, isnegatif))
			return (0);
	while (*str && ft_isdigit(*str))
		str ++;
	if (*str)
		return (0);
	return (isnegatif);
}
