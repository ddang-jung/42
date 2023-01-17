/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonjun <hyeonjun@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 16:54:04 by hyeonjun          #+#    #+#             */
/*   Updated: 2022/11/18 17:08:30 by hyeonjun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack *stack)
{
	t_list	*temp;

	temp = stack->head->next;
	temp->prev = NULL;
	stack->head->next = temp->next;
	temp->next = stack->head;
	stack->head->prev = temp;
	stack->head = temp;
	stack->tail = ft_lstlast(stack->head);
}

void	sa(t_stack *a)
{
	if (a->size < 2)
		return;
	swap(a);
	ft_putstr_fd("sa\n", 1);
}

void	sb(t_stack *b)
{
	if (b->size < 2)
		return;
	swap(b);
	ft_putstr_fd("sb\n", 1);
}

void	ss(t_stack *a, t_stack *b)
{
	if (a->size < 2 || b->size < 2)
		return;
	swap(a);
	swap(b);
	ft_putstr_fd("ss\n", 1);
}

void	push(t_stack *from, t_stack *to)
{
	t_list	*temp;

	temp = from->head;
	if (from->head->next != NULL)
	{
		from->head->next->prev = NULL;
		from->head = from->head->next;
	}
	else
		from->head = NULL;
	from->size -= 1;
	if (to->head != NULL)
	{
		temp->next = to->head;
		to->head->prev = temp;
	}
	else
		temp->next = NULL;
	to->head = temp;
	to->size += 1;
	from->tail = ft_lstlast(from->head);
	to->tail = ft_lstlast(to->head);
}

void	pa(t_stack *a, t_stack *b)
{
	if (b->size == 0)
		return;
	push(b, a);
	ft_putstr_fd("pa\n", 1);
}

void	pb(t_stack *a, t_stack *b)
{
	if (a->size == 0)
		return;
	push(a, b);
	ft_putstr_fd("pb\n", 1);
}

void	rotate(t_stack *stack)
{
	t_list *temp;

	if (stack->size < 2)
		return ;
	else if (stack->size == 2)
	{
		temp = stack->head;
		temp->prev = temp->next;
		temp->next = NULL;
		stack->tail = temp;
		stack->head = temp->prev;
		stack->head->next = temp;
		stack->head->prev = NULL;
	}
	else
	{
		temp = stack->head;
		stack->head->next->prev = NULL;
		stack->head = stack->head->next;
		stack->tail->next = temp;
		temp->prev = stack->tail;
		temp->next = NULL;
		stack->tail = temp;
	}
}

void	ra(t_stack *a)
{
	rotate(a);
	ft_putstr_fd("ra\n", 1);
}

void	rb(t_stack *b)
{
	rotate(b);
	ft_putstr_fd("rb\n", 1);
}

void	rr(t_stack *a, t_stack *b)
{
	rotate(a);
	rotate(b);
	ft_putstr_fd("rr\n", 1);
}

void	reverse_rotate(t_stack *stack)
{
	t_list *temp;

	if (stack->size < 2)
		return ;
	else if (stack->size == 2)
	{
		temp = stack->tail;
		temp->prev = NULL;
		stack->head->prev = temp;
		stack->head->next = NULL;
		stack->tail = stack->head;
		stack->head = temp;
	}
	else
	{
		temp = stack->tail;
		stack->tail->prev->next = NULL;
		stack->tail = stack->tail->prev;
		stack->head->prev = temp;
		temp->next = stack->head;
		stack->head = temp;
	}
}

void	rra(t_stack *a)
{
	reverse_rotate(a);
	ft_putstr_fd("rra\n", 1);
}

void	rrb(t_stack *b)
{
	reverse_rotate(b);
	ft_putstr_fd("rrb\n", 1);
}

void	rrr(t_stack *a, t_stack *b)
{
	reverse_rotate(a);
	reverse_rotate(b);
	ft_putstr_fd("rrr\n", 1);
}