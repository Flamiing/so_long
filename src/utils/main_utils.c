/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaaouam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 13:48:30 by alaaouam          #+#    #+#             */
/*   Updated: 2023/04/26 13:28:58 by alaaouam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>
#include <libft.h>

int	ft_valid_input(char *str)
{
	if (!str || ft_strnstr(str + (ft_strlen(str) - 4), ".ber", 4) == 0)
		return (0);
	return (1);
}
