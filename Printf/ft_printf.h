/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeschall <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 20:38:06 by yeschall          #+#    #+#             */
/*   Updated: 2021/01/17 21:00:22 by yeschall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# define SUBJ_TYPES "cspdiuxX%"

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include "./libft/libft.h"

typedef struct		s_part
{
	int				on;
	int				val;
}					t_part;

typedef struct		s_obj
{
	struct s_part	s_flag;
	struct s_part	s_width;
	struct s_part	s_prec;
	struct s_part	s_type;
	size_t			len;
}					t_obj;

int					ft_printf(const char *str, ...);
t_obj				ft_parse(const char **str, va_list p);
void				ft_init_obj(t_obj *obj);
char				*ft_processor(t_obj *obj, va_list p);
char				*ft_check_precision(t_obj *obj, char *str);
char				*ft_check_width(t_obj *obj, char *str);
char				*ft_int(t_obj *obj, int val);
char				*ft_u(t_obj *obj, unsigned int val);
char				*ft_x(t_obj *obj, unsigned int val);
char				*ft_char(t_obj *obj, int val);
char				*ft_s(t_obj *obj, char **val);
char				*ft_p(t_obj *obj, char **val);
void				check_additional_rules(t_obj *obj);
#endif
