/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabriel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 02:33:56 by mabriel           #+#    #+#             */
/*   Updated: 2021/11/28 02:52:40 by mabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include <stdio.h>

void	print_iter(void *content)
{
	printf("%d\n", (int)content);
}

void	*map(void *content)
{
	(void)content;
	return ((void *)10);
}

void	del(void *content)
{
	(void)content;
}

void	print_lst(t_list *lst)
{
	while (lst)
	{
		printf("%d\n", (int)lst->content);
		lst = lst->next;
	}
	printf("\n");
}

int main()
{
	t_list	*lst;
	t_list	*tmp;

	lst = ft_lstnew((void *)4);
	ft_lstadd_front(&lst, ft_lstnew((void *)2));
	ft_lstadd_back(&lst, ft_lstnew((void *)12));
	ft_lstadd_front(&lst, ft_lstnew((void *)1));

	print_lst(lst);

	tmp = ft_lstlast(lst);
	printf("Le dernier element : %d\n\n", (int)tmp->content);
	printf("La taille de lst : %d\n\n", ft_lstsize(lst));
	
	ft_lstiter(lst, print_iter);
	printf("\n");

	tmp = ft_lstmap(lst, map, del);
	
	print_lst(tmp);
}
