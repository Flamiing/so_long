/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_utils_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaaouam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 13:48:30 by alaaouam          #+#    #+#             */
/*   Updated: 2023/03/25 16:11:39 by alaaouam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long_bonus.h>
#include <libft.h>

int	ft_valid_input(char *str)
{
	if (!str || ft_strnstr(str + (ft_strlen(str) - 4), ".ber", 4) == 0)
		return (0);
	return (1);
}
