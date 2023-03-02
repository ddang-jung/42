#include "../../include/main.h"
#include "../../include/excute.h"

int	check_sort(t_env *f, t_env *s1, t_env *s2)
{
	if (ft_strcmp(s1->key, s2->key) > 0)
	{
		f->next = s2;
		s1->next = s2->next;
		s2->next = s1;
		return (1);
	}
	return (0);
}

void	sorting_env(t_minishell *m)
{
	t_env	*front;
	t_env	*s1;
	t_env	*s2;

	front = m->senv;
	s1 = m->senv->next;
	s2 = m->senv->next->next;
	while (s2 != NULL)
	{
		if (check_sort(front, s1, s2) == 1)
		{
			front = m->senv;
			s1 = m->senv->next;
			s2 = m->senv->next->next;
			continue ;
		}
		front = s1;
		s1 = s1->next;
		s2 = s2->next;
	}
}
