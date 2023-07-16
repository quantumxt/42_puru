/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: photon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 15:34:34 by photon            #+#    #+#             */
/*   Updated: 2023/07/06 15:35:15 by photon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	s_len(char *str)
{
	int	count;

	count = 0;
	while (*str++)
		count++;
	return (count);
}

int	count_words(char *str, char *charset)
{
	int		word_count;
	int		is_word;
	char	*charset_chk;

	if (!*str)
		return (0);
	is_word = 0;
	word_count = 0;
	while (*str)
	{
		charset_chk = charset;
		while (*charset_chk && *str != *charset_chk)
			charset_chk++;
		if (!*charset_chk && !is_word)
		{
			is_word = 1;
			word_count++;
		}
		else if (*charset_chk)
			is_word = 0;
		str++;
		while (*str == *charset_chk && *charset_chk)
			str++;
	}
	return (word_count);
}

void	extract_word(char **str, char *charset, char **word_addr)
{
	int		i;
	int		word_size;
	char	*charset_chk;

	i = -1;
	while ((*str)[++i])
	{
		charset_chk = charset;
		while (*charset_chk)
		{
			if ((*str)[i] == *charset_chk)
				break ;
			charset_chk++;
		}
		if (*charset_chk)
			break ;
	}
	word_size = i;
	*word_addr = (char *) malloc((word_size + 1) * sizeof(char));
	i = -1;
	while (++i < word_size)
		(*word_addr)[i] = (*str)[i];
	(*word_addr)[i] = '\0';
	*str += i;
}

char	*skip_charset(char *str, char *charset)
{
	char	*charset_chk;
	int		is_word;

	is_word = 0;
	while (*str)
	{
		charset_chk = charset - 1;
		while (*(++charset_chk))
			if (*str == *charset_chk)
				break ;
		if (!*charset_chk)
		{
			if (is_word)
				break ;
			else
				is_word = 1;
		}
		else
		{
			is_word = 0;
			str++;
		}
	}
	return (str);
}

char	**ft_split(char *str, char *charset)
{
	char	**arr;
	char	*word;
	int		word_count;
	int		i;

	str = skip_charset(str, charset);
	word_count = count_words(str, charset);
	arr = (char **) malloc((word_count + 1) * sizeof(char *));
	i = 0;
	while (i < word_count)
	{
		extract_word(&str, charset, &word);
		arr[i] = word;
		str = skip_charset(str, charset);
		i++;
	}
	arr[i] = NULL;
	return (arr);
}
/*
#include <assert.h>
#include <string.h>
#include <stdio.h>

int main() {
    // We assume the `ft_split` function has been properly declared and defined.

    char **result;
    int i;

    // Test Case 1: Standard Case
    result = ft_split("Hello World, this is a test", " ");
    assert(strcmp(result[0], "Hello") == 0);
    assert(strcmp(result[1], "World,") == 0);
    assert(strcmp(result[2], "this") == 0);
    assert(strcmp(result[3], "is") == 0);
    assert(strcmp(result[4], "a") == 0);
    assert(strcmp(result[5], "test") == 0);
    assert(result[6] == 0);
    for(i=0; result[i] != 0; i++) free(result[i]); free(result);  // cleanup

    // Test Case 2: Consecutive delimiters
    result = ft_split("Hello,,,,,World", ",");
    assert(strcmp(result[0], "Hello") == 0);
    assert(strcmp(result[1], "World") == 0);
    assert(result[2] == 0);
    for(i=0; result[i] != 0; i++) free(result[i]); free(result);  // cleanup

    // Test Case 3: Delimiter at beginning and end of string
    result = ft_split(" Hello World ", " ");
    assert(strcmp(result[0], "Hello") == 0);
    assert(strcmp(result[1], "World") == 0);
    assert(result[2] == 0);
    for(i=0; result[i] != 0; i++) free(result[i]); free(result);  // cleanup

    // Test Case 4: No delimiter in the string
    result = ft_split("HelloWorld", ",");
    assert(strcmp(result[0], "HelloWorld") == 0);
    assert(result[1] == 0);
    for(i=0; result[i] != 0; i++) free(result[i]); free(result);  // cleanup

    // Test Case 5: Empty string and non-empty delimiter
    result = ft_split("", ",");
    assert(result[0] == 0);
    free(result);  // cleanup

    // Test Case 6: Non-empty string and empty delimiter
    result = ft_split("HelloWorld", "");
    assert(strcmp(result[0], "HelloWorld") == 0);
    assert(result[1] == 0);
    for(i=0; result[i] != 0; i++) free(result[i]); free(result);  // cleanup

    // Test Case 7: Both string and delimiter are empty
    result = ft_split("", "");
    assert(result[0] == 0);
    free(result);  // cleanup
    
    result = ft_split(",,bye,night,,", ",");
    assert(strcmp(result[0], "bye") == 0);
    assert(strcmp(result[1], "night") == 0);
    assert(result[2] == 0);
    free(result);  // cleanup
    
    printf("All test passed!");
    
    return 0;
}
*/
