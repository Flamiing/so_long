/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaaouam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 13:10:51 by alaaouam          #+#    #+#             */
/*   Updated: 2023/03/21 17:51:44 by alaaouam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <so_long.h>

void	ft_print_error(char *error)
{
	write(2, "Error\n", 6);
	write(2, error, ft_strlen(error));
}
