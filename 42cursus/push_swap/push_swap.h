/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minwucho <minwucho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 13:40:20 by minwucho          #+#    #+#             */
/*   Updated: 2023/10/22 20:59:31 by minwucho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>

# define MAX_INT 2147483647
# define MIN_INT -2147483648

typedef struct s_node
{
	int				data;
	struct s_node	*next;
	struct s_node	*prev;
}	t_node;

typedef struct s_dblist
{
	t_node	*head;
	t_node	*cur;
	t_node	*tail;
	int		numofdata;
}	t_dblist;

void	ft_putstr_fd(char *s, int fd);
char	*ft_strjoin(char const *s1, char const *s2);
char	**ft_split(char const *s, char *charset);
void	error_make(void);
void	init_list(t_dblist *plist);
void	insert_list(t_dblist *plist, int data);
void	insert_list_tail(t_dblist *plist, int data);
void	parsing(char **str, t_dblist *a);
void	make_free(char **s);
void	free_stack(t_dblist *a);
int		check_overlap(t_dblist *a);
void	sort(t_dblist *a, t_dblist *b);
int		*for_quick_arr(t_dblist *a);
void	quicksort(int *arr, int left, int right);
int		pop(t_dblist *a);
void	pb(t_dblist *a, t_dblist *b);
void	pa(t_dblist *b, t_dblist *a);
void	ra(t_dblist *a);
void	rb(t_dblist *b);
void	rra(t_dblist *a);
void	rrb(t_dblist *b);
void	sa(t_dblist *a);
void	a_to_b(t_dblist *a, t_dblist *b, double chunk);
void	b_to_a(t_dblist *b, t_dblist *a);
void	change(t_dblist *a);
void	hardcoding_two(t_dblist *a);
void	hardcoding_three(t_dblist *a);
void	hardcoding_four(t_dblist *a, t_dblist *b);
void	hardcoding_five(t_dblist *a, t_dblist *b);
int		check_if_sorted(t_dblist *a);
int		small_idx(t_dblist *a, int target, int length);

#endif
