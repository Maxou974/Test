/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabriel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 17:32:54 by mabriel           #+#    #+#             */
/*   Updated: 2022/04/20 08:49:59 by mabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"
#include "stdio.h"
#include <string.h>

void	putstr(char *s)
{
	printf("%s\n", s);
}
void	green()
{
	printf("\033[0;32m");
}

void reset_color()
{
	printf("\033[0m");
}

void	test_isalpha()
{
	putstr("IS ALPHA");
	for	(int i = 65; i <= 90; i++)
	{
		if (ft_isalpha(i) == 0)
		{
			putstr("  Pas bon 🙁");
			return ;
		}
	}
	for	(int i = 97; i <= 122; i++)
	{
		if (ft_isalpha(i) == 0)
		{
			putstr("  Pas bon 🙁");
			return ;
		}
	}
	for	(int i = 0; i <= 64; i++)
	{
		if (ft_isalpha(i) == 1)
		{
			putstr("  Pas bon 🙁");
			return ;
		}
	}
	for	(int i = 91; i <= 96; i++)
	{
		if (ft_isalpha(i) == 1)
		{
			putstr("  Pas bon 🙁");
			return ;
		}
	}
	for	(int i = 123; i <= 128; i++)
	{
		if (ft_isalpha(i) == 1)
		{
			putstr("  Pas bon 🙁");
			return ;
		}
	}
	green();
	putstr(" Bravo");
	reset_color();
}

void	test_isdigit()
{
	putstr("IS DIGIT");
	for	(int i = 48; i <= 57; i++)
	{
		if (ft_isdigit(i) == 0 && i >= '0' && i <= '9')
		{
			putstr("  Pas bon 🙁");
			return ;
		}
		if (ft_isdigit(i) == 1 && ((i >= 0 && i < '0') || (i > '9' && i < 129)))
		{
			putstr("  Pas bon 🙁");
			return ;
		}
	}
	green();
	putstr(" Bravo");
	reset_color();
}

void	test_isprint()
{
	putstr("IS PRINT");
	for	(int i = 32; i <= 126; i++)
	{
		if (ft_isprint(i) == 0)
		{
			putstr("  Pas bon 🙁");
			return ;
		}
	}
	for	(int i = 0; i <= 31; i++)
	{
		if (ft_isprint(i) == 1)
		{
			putstr("  Pas bon 🙁");
			return ;
		}
	}	
	green();
	putstr(" Bravo");
	reset_color();
}

void	test_isascii()
{
	putstr("IS ASCII");
	for	(int i = 0; i <= 127; i++)
	{
		if (ft_isascii(i) == 0)
		{
			putstr("  Pas bon 🙁");
			return ;
		}
	}
	if (ft_isascii(-1) == 1 || ft_isascii(128) == 1)
	{
		putstr("  Pas bon 🙁");
		return ;
	}
	green();
	putstr(" Bravo");
	reset_color();
}

void	test_isalnum()
{
	putstr("IS ALNUM");
	for	(int i = 48; i <= 57; i++)
	{
		if (ft_isalnum(i) == 0 && i >= '0' && i <= '9')
		{
			putstr("1  Pas bon 🙁");
			return ;
		}
		if (ft_isalnum(i) == 1 && ((i >= 0 && i < '0') || (i > '9' && i < 129)))
		{
			putstr("2  Pas bon 🙁");
			return ;
		}
	}
	for	(int i = 65; i <= 90; i++)
	{
		if (ft_isalnum(i) == 0)
		{
			putstr("3  Pas bon 🙁");
			return ;
		}
	}
	for	(int i = 97; i <= 122; i++)
	{
		if (ft_isalnum(i) == 0)
		{
			putstr("4  Pas bon 🙁");
			return ;
		}
	}
	for	(int i = 91; i <= 96; i++)
	{
		if (ft_isalnum(i) == 1)
		{
			putstr("6  Pas bon 🙁");
			return ;
		}
	}
	for	(int i = 123; i <= 128; i++)
	{
		if (ft_isalnum(i) == 1)
		{
			putstr("7  Pas bon 🙁");
			return ;
		}
	}
	green();
	putstr(" Bravo");
	reset_color();
}

void	test_strlen()
{
	putstr("STRLEN");
	if (ft_strlen("Je suis pas beau") != 16 ||
			ft_strlen("n") != 1 ||
			ft_strlen("") != 0 ||
			ft_strlen(NULL) != 0)
	{
		putstr("  Pas bon 🙁");
			return ;
	}
	green();
	putstr(" Bravo");
	reset_color();	
}

void	test_memset()
{
	putstr("MEMSET");
	char	c = '3';
	char	*b;
	b = malloc(12);
	ft_memset(b, c, 11);
	int i = 0;
	while (i < 11)
	{
		if (b[i] != c)
		{
			putstr(" Pas bon 🙁");
			free(b);
			return ;
		}
		i++;
	}
	if (b != ft_memset(b,c + 1,0))
	{
			putstr(" Pas bon 🙁");
			free(b);
			return ;
	}
	green();
	free(b);
	putstr(" Bravo");
	reset_color();
}

void	test_bzero()
{
	putstr("BZERO");
	char	*b;
	b = malloc(12);
	ft_bzero(b, 11);
	int i = 0;
	while (i < 11)
	{
		if (b[i] != '\0')
		{
			putstr(" Pas bon 🙁");
			free(b);
			return ;
		}
		i++;
	}
	free(b);
	green();
	putstr(" Bravo");
	reset_color();
}

void	test_memcpy()
{
	putstr("MEMCPY");
	char *dest = malloc(12);
	char *src = "jiwef";

	ft_memcpy(dest, src, 3);
	if (strncmp(src, dest, 3) != 0)
	{
		putstr("  Pas bon 🙁");
		free(dest);
		return ;
	}
	free(dest);
	green();
	putstr(" Bravo");
	reset_color();
}

void	test_memmove()
{
	putstr("MEMMOVE");
	char	str[] = "ABCDEFGHIJ";
	ft_memmove(str + 2, str, 4);
	if (strncmp(str, "ABABCDGHIJ", 10))
	{
		putstr("1  Pas bon 🙁");
		return ;
	}
	ft_memmove(str, str + 3, 7);
	if (strncmp(str, "BCDGHIJHIJ", 10))
	{
		putstr("2  Pas bon 🙁");
		return ;
	}
	ft_memmove(str, str + 1, 6);
	if (strncmp(str, "CDGHIJJHIJ", 10))
	{
		putstr("3  Pas bon 🙁");
		return ;
	}
	ft_memmove(str + 5, str, 5);
	if (strncmp(str, "CDGHICDGHI", 10))
	{
		putstr("4  Pas bon 🙁");
		return ;
	}
	green();
	putstr(" Bravo");
	reset_color();
}

void	test_toupper()
{
	putstr("TO UPPER");
	for (int i = 0; i < 128; i++)
	{
		if (i >= 'a' && i <= 'z')
		{
			if (ft_toupper(i) != i - 32)
			{
				putstr("4  Pas bon 🙁");
				return ;
			}
		}
		if (i >= 0 && i < 'a')
		{
			if (ft_toupper(i) != i)
			{
				putstr("4  Pas bon 🙁");
				return ;
			}
		}
		if (i > 'z' && i < 128)
		{
			if (ft_toupper(i) != i)
			{
				putstr("4  Pas bon 🙁");
				return ;
			}
		}
	}
	green();
	putstr(" Bravo");
	reset_color();
}

void	test_tolower()
{
	putstr("TO lower");
	for (int i = 0; i < 128; i++)
	{
		if (i >= 'A' && i <= 'Z')
		{
			if (ft_tolower(i) != i + 32)
			{
				printf("1|%d  Pas bon 🙁\n", i);
				return ;
			}
		}
		if (i >= 0 && i < 'A')
		{
			if (ft_tolower(i) != i)
			{
				printf("2|%d  Pas bon 🙁\n", i);
				return ;
			}
		}
		if (i > 'Z' && i < 128)
		{
			if (ft_tolower(i) != i)
			{
				printf("3|%d  Pas bon 🙁\n", i);
				return ;
			}
		}
	}
	green();
	putstr(" Bravo");
	reset_color();
}

void	test_atoi()
{
	putstr("ATOI");
	char	max[] = "2147483647";
	char	min[] = "-2147483648";

	if (ft_atoi(min) != -2147483648 || ft_atoi(max) != 2147483647 ||
			ft_atoi("-42") != -42 || ft_atoi("42") != 42 || ft_atoi(" -0") != 0)
	{
		putstr("  Pas bon 🙁");
		return ;
	}
	green();
	putstr(" Bravo");
	reset_color();
}

void	test_strchr()
{
	char str[] = "Je suis meuh";
	putstr("STRCHR");
	if (ft_strchr(str, 'J') != str || ft_strchr(str, 'e') != str + 1 ||
			ft_strchr(str, 'w') != NULL)
	{
		putstr("  Pas bon 🙁");
		return ;
	}
	green();
	putstr(" Bravo");
	reset_color();
}

void	test_strrchr()
{
	char str[] = "Je suis meuhhh";
	putstr("STRRCHR");
	if (ft_strrchr(str, 'J') != str || ft_strrchr(str, 'e') != str + 9 ||
			ft_strrchr(str, 'w') != NULL || ft_strrchr(str, 'h') != str + ft_strlen(str) - 1)
	{
		putstr("  Pas bon 🙁");
		return ;
	}
	green();
	putstr(" Bravo");
	reset_color();
}


void	test_strncmp()
{
	putstr("STRNCMP");
	char s1[] = "Je suis pas beau";
	char s2[] = "Je suis pas jolie";
	
	for (int i = 0; i < 20; i++)
	{
		if (ft_strncmp(s1, s2, i) != strncmp(s1, s2, i) && i < 13)
		{
			printf("%d  Pas bon 🙁\n", i);
			return ;
		}
		else if (ft_strncmp(s1, s2, i) >= 0 && strncmp(s1, s2, i) >= 0 && i >= 13)
		{
			printf("%d  Pas bon 🙁\n", i);
			return ;
		}
	}
	green();
	putstr(" Bravo");
	reset_color();
}

void    test_memchr()
{
        char str[] = "Je suis meuh";
        putstr("MEMCHR");
        if (ft_memchr(str, 'J', 1) != str || ft_memchr(str, 'e', 16) != str + 1 ||
                        ft_memchr(str, 'J', 0) != NULL || ft_memchr(str, 'J', 2) != str)
        {
                putstr("  Pas bon 🙁");
                return ;
        }
        green();
	putstr(" Bravo");
	reset_color();
}

void    test_memcmp()
{
        putstr("MEMCMP");
        char s1[] = "Je suis pas beau";
        char s2[] = "Je suis pas jolie";

        for (int i = 0; i < 20; i++)
        {
                if (ft_memcmp(s1, s2, i) != memcmp(s1, s2, i))
                {
                        printf("%d  Pas bon 🙁\n", i);
						return ;
                }
        }
        green();
	putstr(" Bravo");
	reset_color();
}

void test_strnstr()
{
        putstr("STRNSTR");
        char s1[] = "Je suis pas beau";

        for (int i = 0; i < 20; i++)
        {
                if (ft_strnstr(s1, "", i) != s1)
                {
                        putstr("  Pas bon 🙁 1");
                        printf("%d", i);
                        return ;
                }
                if (ft_strnstr(s1, "woefn", i) != NULL)
                {
                        putstr("  Pas bon 🙁 2");
                        printf("%d", i);
                        return ;
                }
                if (ft_strnstr(s1, "pas", i) != NULL && i < 11)
                {
                        putstr("  Pas bon 🙁 3");
                        printf("%d", i);
                        return ;
                }
        }
	if (ft_strnstr(s1, "pas ", 16) != s1 + 8 || ft_strnstr(s1, "J", 1) != s1)
        {
               putstr("  Pas bon 🙁 4");
               return ;
        }
        green();
	putstr(" Bravo");
	reset_color();
}

size_t truestrlcat(dst, src, siz)
        char *dst;
        const char *src;
        size_t siz;
{
        register char *d = dst;
        register const char *s = src;
        register size_t n = siz;
        size_t dlen;

        /* Find the end of dst and adjust bytes left but don't go past end */
        while (n-- != 0 && *d != '\0')
                d++;
        dlen = d - dst;
        n = siz - dlen;

        if (n == 0)
                return(dlen + strlen(s));
        while (*s != '\0') {
                if (n != 1) {
                        *d++ = *s;
                        n--;
                }
                s++;
        }
        *d = '\0';

        return(dlen + (s - src));       /* count does not include NUL */
}
void	test_strlcat()
{
	putstr("STRLCAT");
	for (int i = 0; i < 20; i++)
	{
		
	        char    dst1[20] = "Je suis";
	        char    src1[9] = "pas beau";
		char    dst2[20] = "Je suis";
     		char    src2[9] = "pas beau";
		if (ft_strlcat(dst1, src1, i) != truestrlcat(dst2, src2, i) || strcmp(dst1, dst2) != 0)
		{
			putstr("  Pas bon 🙁");
			return ;
		}
	}
	green();
	putstr(" Bravo");
	reset_color();
}

size_t truestrlcpy(char * dst, const char * src, size_t maxlen) {
    const size_t srclen = strlen(src);
    if (srclen + 1 < maxlen) {
        memcpy(dst, src, srclen + 1);
    } else if (maxlen != 0) {
        memcpy(dst, src, maxlen - 1);
        dst[maxlen-1] = '\0';
    }
    return srclen;
}

void	test_strlcpy()
{
        putstr("STRLCPY");
        for (int i = 0; i < 20; i++)
        {

                char    dst1[20] = "Je suis";
                char    src1[9] = "pas beau";
                char    dst2[20] = "Je suis";
                char    src2[9] = "pas beau";
                if (ft_strlcpy(dst1, src1, i) != truestrlcpy(dst2, src2, i) || strcmp(dst1, dst2) != 0)
                {
                        putstr(" Pas bon 🙁");
                        return ;
                }
        }
        green();
	putstr(" Bravo");
	reset_color();

}

void	test_calloc()
{
	putstr("CALLOC");
	void *p = ft_calloc(2, 2);
	char e[] = {0, 0, 0, 0};

	if (memcmp(p, e, 4) != 0)
        {
	     putstr("  Pas bon 🙁");
	     free(p);
             return ;
        }
	green();
	free(p);
	putstr(" Bravo");
	reset_color();
}

void	test_strdup()
{
	putstr("STRDUP");
	char src1[] = "";
	char *dest1;
	char src2[] = "Je suis pas beau";
	char *dest2;
	char src3[] = "kfwiofo";
	char *dest3;
	char src4[] = "f";
	char *dest4;
	char src5[] = "fffffffff";
	char *dest5;
	dest1 = ft_strdup(src1);
	dest2 = ft_strdup(src2);
	dest3 = ft_strdup(src3);
	dest4 = ft_strdup(src4);
	dest5 = ft_strdup(src5);
	if (strcmp(dest1, "") || strcmp(dest2, "Je suis pas beau") ||
			strcmp(dest3, "kfwiofo") || strcmp(dest4, "f") || strcmp(dest5, "fffffffff"))
	{
		putstr("  Pas bon 🙁");
		return;
	}
	free(dest1);
	free(dest2);
	free(dest3);
	free(dest4);
	free(dest5);
	green();
	putstr(" Bravo");
	reset_color();
}

void	test_strjoin()
{
	putstr("STRJOIN");
	char s1[] = "Je suis";
	char s2[] = " pas beau";
	char *result;

	result = ft_strjoin(s1, s2);
	if (strcmp(result, "Je suis pas beau"))
	{
		printf("1  Pas bon 🙁\n");
		free(result);
		return ;
	}
	free(result);
	result = ft_strjoin("J", "");
	if  (strcmp(result, "J"))
	{
		printf("2  Pas bon 🙁\n");
		free(result);
		return ;
	}
	free(result);
	green();
	putstr(" Bravo");
	reset_color();

}

void	test_strtrim()
{
	putstr("STRTRIM");
	char *a = ft_strtrim("abcJe suisbca", "abc");
	char *b = ft_strtrim("cJe suisb", "abc");
	char *c = ft_strtrim("abcJbca", "abc");
	char *d = ft_strtrim("Je suis", "abc");
	char *e = ft_strtrim("", "abc");
	if (strcmp(a, "Je suis"))
		putstr("1  Pas bon 🙁");
	else if (strcmp(b, "Je suis"))
		putstr("2  Pas bon 🙁");
	else if (strcmp(c, "J"))
		putstr("3  Pas bon 🙁");
	else if (strcmp(d, "Je suis"))
		putstr("4  Pas bon 🙁");
	else if (strcmp(e, ""))
		putstr("5  Pas bon 🙁");
	else
	{
		green();
		putstr(" Bravo");
	}
	free(e);
	free(d);
	free(c);
	free(b);
	free(a);
	reset_color();
}

void	test_itoa()
{
	putstr("ITOA");
	char *a = ft_itoa(1);
	char *b = ft_itoa(-1);
	char *c = ft_itoa(-0);
	char *d = ft_itoa(2147483647);
	char *e = ft_itoa(-2147483648);
	if (strcmp(a, "1"))
		putstr("1  Pas bon 🙁");
	else if (strcmp(b, "-1"))
		putstr("2  Pas bon 🙁");
	else if (strcmp(c, "0"))
		putstr("3  Pas bon 🙁");
	else if (strcmp(d, "2147483647"))
		putstr("4  Pas bon 🙁");
	else if (strcmp(e, "-2147483648"))
		putstr("5  Pas bon 🙁");
	else
	{
		free(a);
		free(b);
		free(c);
		free(d);
		free(e);
		green();
		putstr(" Bravo");
	}
	reset_color();
}

void	free_split(char **d)
{
	int	i = 0;

	while (d[i])
	{
		free(d[i]);
		i++;
	}
	free(d);
}

void	test_split()
{
	putstr("SPLIIIIIIIIT");
	char	**result;
	int	i = 0;

	result = ft_split("Je suis beau", ' ');
	if ((strcmp(result[0], "Je") || strcmp(result[1], "suis") || 
			strcmp(result[2], "beau") || result[3] != NULL) && ++i)
		putstr("1  Pas bon 🙁");
	free_split(result);
	result = ft_split ("       ", ' ');
	if (result[0] != NULL && ++i)
		putstr("2  Pas bon 🙁");
	free_split(result);
	result = ft_split("Je suis pas beau", 'z');
	if ((strcmp(result[0], "Je suis pas beau") || result[1] != NULL) && ++i)
		putstr("3  Pas bon 🙁");
	free_split(result);
	result = ft_split("J", ' ');
	if ((strcmp(result[0], "J") || result[1] != NULL) && ++i)
		putstr("4  Pas bon 🙁");
	free_split(result);
	if (i == 0)
	{
		green();
		putstr(" Bravo");
	}
	reset_color();
}

void	test_substr()
{
	putstr("SUBSTR");
	char *a = ft_substr("Je suis pas beau", 0, 10);
	char *b = ft_substr("Je suis pas beau", 5, 20);
	char *c = ft_substr("Je suis pas beau", 7, 3);
	char *d = ft_substr("", 0, 20);
	if (strcmp(a, "Je suis pa"))
		putstr("1  Pas bon 🙁");
	else if (strcmp(b, "is pas beau"))
		putstr("2  Pas bon 🙁");
	else if (strcmp(c, " pa"))
		putstr("3  Pas bon 🙁");
	else if (strcmp(d, ""))
		putstr("4  Pas bon 🙁");
	else
	{
		green();
		putstr(" Bravo");
	}
	free(a);
	free(d);
	free(c);
	free(b);
	reset_color();
}

char	root_one(unsigned int i, char c)
{
	(void)i;
	if (c == 'Z')
		return ('A');
	if (c == 'z')
		return ('a');
	if ((c >= 'A' && c < 'Z') || (c >= 'a' && c < 'z' ))
		return (c + 1);
	return (c);
}

void	test_strmapi()
{
	putstr("STRMAPI");
	char *a = ft_strmapi("aBcDeF", &root_one);
	char *b = ft_strmapi("aBc ,DeF", &root_one);
	char *c = ft_strmapi("z", &root_one);
	if (strcmp(a, "bCdEfG"))
		putstr("1  Pas bon 🙁");
	else if (strcmp(b, "bCd ,EfG"))
		putstr("2  Pas bon 🙁");
	else if (strcmp(c, "a"))
		putstr("3  Pas bon 🙁");
	else
	{
		green();
		putstr(" Bravo");
		reset_color();
	}
	free(c);
	free(b);
	free(a);
}

void	root_one_address(unsigned int i, char *c)
{
	(void)i;
	if (*c == 'Z')
		*c = 'A';
	else if (*c == 'z')
		*c = 'a';
	else if((*c >= 'A' && *c < 'Z') || (*c >= 'a' && *c < 'z' ))
		*c = *c + 1;
}

void	test_striteri()
{
	putstr("STRITERI");
	char s1[] = "aBcDeF";
	char s2[] = "aBc ,DeF";
	char s3[] = "Z";
	ft_striteri(s1, &root_one_address);
	ft_striteri(s2, &root_one_address);
	ft_striteri(s3, &root_one_address);
	if (strcmp(s1, "bCdEfG"))
		putstr("1  Pas bon 🙁");
	else if (strcmp(s2, "bCd ,EfG"))
		putstr("2  Pas bon 🙁");
	else if (strcmp(s3, "A"))
		putstr("3  Pas bon 🙁");
	else
	{
		green();
		putstr(" Bravo");
		reset_color();	
	}
	
}

void	test_putchar_fd()
{
	char s[] = "PUTCHAR_FD\n";
	char d[] = " Bravo\n";
	int	i = 0;
	putstr("");
	while (s[i])
	{
		ft_putchar_fd(s[i], 1);
		i++;
	}
	printf("%s", s);
	i = 0;
	while (d[i])
	{
		ft_putchar_fd(d[i], 1);
		i++;
	}
	printf("%s", d);

}

void	test_putstr_fd()
{
	putstr("");
	ft_putstr_fd("PUTSTR_FD\n", 1);
	putstr("PUTSTR_FD");
	ft_putstr_fd(" Bravo\n", 1);
	putstr(" Bravo\n");

}

void	test_putendl_fd()
{
	ft_putendl_fd("PUTENDL", 1);
	putstr("PUTENDL");
	ft_putendl_fd(" Bravo", 1);
	putstr(" Bravo\n");
}

void	test_putnbr_fd()
{

	printf("\n-2147483648 | 2147483647\n");

	ft_putnbr_fd(-2147483648, 1);
	ft_putstr_fd(" | ", 1);
	ft_putnbr_fd(2147483647, 1);	
	printf("\n\n0\n");
	ft_putnbr_fd(0, 1);
	printf("\n0\n");
	ft_putnbr_fd(-0, 1);
	putstr("");
}

#include <stdlib.h>

int main()
{
	test_isalpha();
	test_isdigit();
	test_isprint();
	test_isascii();
	test_isalnum();
	test_strlen();
	test_memset();
	test_bzero();
	test_memcpy();
	test_memmove();
	test_toupper();
	test_tolower();
	test_atoi();
	test_strchr();
	test_strrchr();
	test_strncmp();
	test_memchr();
	test_memcmp();
	test_strnstr();
	test_strlcat();
	test_strlcpy();
	test_calloc();
	test_strdup();
	test_strjoin();
	test_strtrim();
	test_itoa();
	test_split();
	test_substr();
	test_strmapi();
	test_striteri();
	reset_color();
	test_putchar_fd();
	test_putstr_fd();
	test_putendl_fd();
	test_putnbr_fd();
}
