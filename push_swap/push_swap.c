/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonjun <hyeonjun@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 17:18:35 by hyeonjun          #+#    #+#             */
/*   Updated: 2022/11/18 16:57:35 by hyeonjun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_error(int error_num)
{
	ft_putstr_fd("Error\n", 1);
	exit(error_num);
	/*
	error_num
	1 : malloc failed
	2 : no argument
	3 : split failed
	4 : found overlap
	5 : no int size
	6 : something remained
	7 : only '-' or '+'
	8 : only space
	*/
}

t_stack	*ft_stacknew(t_list *ptr_head)
{
	t_stack	*new;

	new = (t_stack *)malloc(sizeof(t_stack));
	if (new == NULL)
		ft_error(1);
	new->head = ptr_head;
	new->tail = NULL;
	if (ptr_head != NULL)
		new->size = 1;
	else
		new->size = 0;
	return (new);
}

char	**join_split(int ac, char **av)
{
	int		i;
	char	*join;
	char	**split;

	if (ac < 2)
		ft_error(2);
	i = 0;
	while (++i < ac)
		join = ft_strjoin(join, av[i]);
	split = ft_split(join, ' ');
	free(join);
	return (split);
}

void	check_overlap(t_stack *a)
{
	t_list	*temp1;
	t_list	*temp2;

	temp1 = a->head;
	while (temp1 != NULL)
	{
		temp2 = temp1->next;
		while (temp2 != NULL)
		{
			if (temp1->content == temp2->content)
				ft_error(4); //found overlap
			temp2 = temp2->next;
		}
		temp1 = temp1->next;
	}
}

t_stack	*set_stack(int ac, char **av)
{
	t_stack	*a;
	t_list	*tmp;
	char	**strs;
	int		i;

	strs = join_split(ac, av);
	a = ft_stacknew(ft_lstnew(ft_atoi(strs[0])));
	tmp = a->head;
	i = 0;
	while (strs[++i] != NULL)
	{
		tmp->next = ft_lstnew(ft_atoi(strs[i]));
		tmp->next->prev = tmp;
		tmp = tmp->next;
		a->size += 1;
	}
	a->tail = ft_lstlast(a->head);
	check_overlap(a);
	ft_free_str(strs, a->size);
	return (a);
}

// void	free_all(t_stack *a, t_stack *b)
// {
	
// }

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;

	a = set_stack(ac, av);
	b = ft_stacknew(NULL);
	sort_stack(a, b);
	// free_all(a, b);
	return (0);
}
// 예외처리 그만하고 알고리즘 구현