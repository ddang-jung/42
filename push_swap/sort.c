/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonjun <hyeonjun@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 16:58:13 by hyeonjun          #+#    #+#             */
/*   Updated: 2022/11/18 17:59:24 by hyeonjun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	indexing(t_stack *a)
{
	t_list	*temp1;
	t_list	*temp2;

	temp1 = a->head;
	while (temp1 != NULL)
	{
		temp2 = a->head;
		while (temp2 != NULL)
		{
			if (temp1->content > temp2->content)
				temp1->index += 1;
			temp2 = temp2->next;
		}
		temp1 = temp1->next;
	}
}

void	move_a_to_b(t_stack *a, t_stack *b, unsigned int chunk)
{
	unsigned int	i;

	i = 0;
	while (a->size)
	{
		if (a->head->index > i + chunk)
			ra(a);
		else if (a->head->index > i && a->head->index <= i + chunk)
		{
			pb(a, b);
			rb(b);
		}
		else
			pb(a, b);
		i++;
	}
}

void	move_b_to_a(t_stack *a, t_stack *b)
{
	unsigned int	loc;
	t_list			*temp;

	while (b->size)
	{
		temp = b->head;
		loc = 0;
		while (temp->index != (b->size - 1))
		{	
			temp = temp->next;
			loc++;
		}
		if (loc > (b->size) / 2)
			while (b->head != temp)
				rrb(b);
		else
			while (b->head != temp)
				rb(b);
		pa(a, b);
	}
}

void	sort_stack(t_stack *a, t_stack *b)
{
	unsigned int	chunk;

	if (a->size < 100)
		chunk = a->size / 3;
	else if (a->size >= 100 && a->size < 500)
		chunk = 15;
	else if (a->size >= 500 && a->size < 1000)
		chunk = 30;
	else
		chunk = (0.000000053) * (a->size) * (a->size) + (0.03) * (a->size) + 14.5;
	indexing(a);
	move_a_to_b(a, b, chunk);
	move_b_to_a(a, b);
}