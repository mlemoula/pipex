/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlemoula <mlemoula@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 18:06:18 by mlemoula          #+#    #+#             */
/*   Updated: 2024/11/11 15:38:03 by mlemoula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*bytes;

	i = 0;
	bytes = s;
	while (i < n)
	{
		bytes[i] = '\0';
		i++;
	}
}

// #include <string.h>
// #include <stdio.h>
// int main() {
//     char buffer1[11] = "Hello6 8he\0";

//     ft_bzero(buffer1 +5, 5 * sizeof(char));

//    printf("Custom ft_bzero: ");
//     for (int i = 0; i < 10; i++) {
//         printf("%c", buffer1[i]);
//     }
//     printf("\n");

//     return 0;
// }