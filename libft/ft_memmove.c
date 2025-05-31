/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlemoula <mlemoula@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 16:14:55 by mlemoula          #+#    #+#             */
/*   Updated: 2024/11/19 15:11:09 by mlemoula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	const unsigned char	*bytes_src;
	unsigned char		*bytes_dest;
	size_t				i;

	bytes_src = src;
	bytes_dest = dest;
	i = 0;
	if (!src && !dest)
		return (dest);
	if (src >= dest)
	{
		while (i < n)
		{
			bytes_dest[i] = bytes_src[i];
			i++;
		}
	}
	else
		while (n-- > 0)
			bytes_dest[n] = bytes_src[n];
	return (dest);
}

// #include <string.h>
// #include <stdio.h>
// int main() {
//     char src[14] = "123abcdefghijk";
// 	char *dst = src;

//     ft_memmove(src + 5, src, 6);
// 	printf("dst: ");
//     for (int i = 0; i < 15; i++) {
//         printf("%c", dst[i]);
//     }
//     printf("\n");
//     return 0;
// }