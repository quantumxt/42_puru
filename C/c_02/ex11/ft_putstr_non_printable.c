/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: photon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 16:50:24 by photon            #+#    #+#             */
/*   Updated: 2023/06/27 10:36:31 by photon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	is_non_printable(char c)
{
	return (c < ' ' || c > '~');
}

void	itohex(unsigned char input)
{
	unsigned char	hex[3];

	hex[0] = '\\';
	hex[1] = "0123456789abcdef"[input / 16];
	hex[2] = "0123456789abcdef"[input % 16];
	write(1, hex, 3);
}

void	ft_putstr_non_printable(char *str)
{
	while (*str)
	{
		if (is_non_printable(*str))
			itohex((unsigned char) *str);
		else
			write(1, str, 1);
		str++;
	}
}
/*
int main() {
	char str0[] = "Another day.";
	ft_putstr_non_printable(str0);
	write(1, "\n", 1);

	// \t:09 \n: 0A: Hello\09World!\0a
	char str1[] = "Hello\tWorld!\n";	
	ft_putstr_non_printable(str1);
	write(1, "\n", 1);
	
	// Should print \01
	char str2[] = "\x01";			
	ft_putstr_non_printable(str2);
	write(1, "\n", 1);

	// \b:08 \r:0d: Bye\08\0dWorld
	char str3[] = "Bye\b\rWorld";		
	ft_putstr_non_printable(str3);
	write(1, "\n", 1);

	// Coucou\0atu vas bien
	char str4[] = "Coucou\ntu vas bien";	
	ft_putstr_non_printable(str4);
	write(1, "\n", 1);

	// Some\0arandom\09text\0fwith\0anon-printable\0dcharacters
	char str5[] = "Some\nrandom\ttext\x0Fwith\nnon-printable\rcharacters";	
	ft_putstr_non_printable(str5);
	write(1, "\n", 1);

	// \x1f: Hex val of character of US
	char str6[] = "lorem\t\b\r\n\x1fipsum";	
	ft_putstr_non_printable(str6);
	write(1, "\n", 1);
	
	// \x7f: Hex val of last ascii character 'DEL' and something above 0x7f
	// rainy day\7f?\ff
	char str7[] = "rainy day\x7f?\x8f";	
	ft_putstr_non_printable(str7);
	write(1, "\n", 1);

	return 0;
}
*/
