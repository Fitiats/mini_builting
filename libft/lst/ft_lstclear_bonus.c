/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmory < tmory@student.42antananarivo.mg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 14:46:08 by tmory             #+#    #+#             */
/*   Updated: 2024/08/12 14:46:10 by tmory            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*temp;
	t_list	*list;

	list = *lst;
	temp = list;
	if (!lst)
		return ;
	while (temp)
	{
		temp = list;
		temp = temp->next;
		ft_lstdelone(list, del);
		list = temp;
	}
	*lst = NULL;
}
