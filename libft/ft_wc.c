/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wc.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocaball <jocaball@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 12:22:50 by jocaball          #+#    #+#             */
/*   Updated: 2023/08/17 14:02:55 by jocaball         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Parametros  : s: La string en la que contar las palabras.
//               c: El carácter delimitador entre palabras.
// Devuelve    : La cuenta de palabras encontradas en la string.
//               NULL si falla la reserva de memoria.

#include "libft.h"

size_t	ft_wc(char const *str, char c)
{
	size_t	count;
	size_t	i;

	count = 0;
	i = 0;
	while (str[i])
	{
		if ((str[i] != c) && ft_isalnum(str[i]))
		{
			count++;
			while (str[i] && str[i] != c)
				i++;
		}
		else
			i++;
	}
	return (count);
}
