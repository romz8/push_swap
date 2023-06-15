/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjobert <rjobert@student.42barcelo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 15:07:34 by rjobert           #+#    #+#             */
/*   Updated: 2023/05/11 15:27:52 by rjobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*head;
	t_list	*tmp_next;

	if (!lst)
		return ;
	head = *lst;
	while (head)
	{
		tmp_next = head->next;
		ft_lstdelone(head, del);
		head = tmp_next;
	}
	*lst = NULL;
}
