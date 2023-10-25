/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minwucho <minwucho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 20:55:41 by minwucho          #+#    #+#             */
/*   Updated: 2023/10/23 21:18:28 by minwucho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

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

void	init_list(t_dblist *plist);
void	insert_list(t_dblist *plist, int data);
void	free_stack(t_dblist *a);
int		pop(t_dblist *a);
void	insert_list_tail(t_dblist *plist, int data);
char	**ft_split(char const *s, char *charset);
void	pb(t_dblist *a, t_dblist *b);
void	pa(t_dblist *b, t_dblist *a);
void	ra(t_dblist *a);
void	rb(t_dblist *b);
void	rra(t_dblist *a);
void	rrb(t_dblist *b);
void	sa(t_dblist *a);
void	sb(t_dblist *b);
void	ss(t_dblist *a, t_dblist *b);
void	rr(t_dblist *a, t_dblist *b);
void	rrr(t_dblist *a, t_dblist *b);
char	*get_next_line(int fd);
char	*ft_strchr_gnl(char *s, int c);
char	*ft_strjoin_gnl(char *s1, char *s2);
int		ft_strlen_gnl(char *s);
void	ft_putstr_fd(char *s, int fd);
void	error_make(void);
int		check_overlap(t_dblist *a);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	all_free(t_dblist *a, t_dblist *b);
int		check_if_sorted(t_dblist *a);
int		is_empty(t_dblist *b);
void	do_ok_or_ko(t_dblist *a, t_dblist *b);
char	**ft_split(char const *s, char *charset);
char	*ft_strjoin(char const *s1, char const *s2);
void	parsing(char **str, t_dblist *a);
void	make_free(char **s);
int		check_empty(int ac, char **av);
size_t	ft_strlen(const char *s);
int		check_limit(long long result, int *check, int sign);

#endif
