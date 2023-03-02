/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junyoung <junyoung@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 14:18:41 by hyeonjun          #+#    #+#             */
/*   Updated: 2023/02/03 09:04:59 by junyoung         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

t_env	*ft_lstlast(t_env *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}
