/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrisset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/25 15:03:47 by jbrisset          #+#    #+#             */
/*   Updated: 2019/03/22 09:33:32 by jbrisset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "libft/libft.h"
# include <stdio.h>
# include <stdarg.h>

# define BLANK 	' '
# define ZERO 	'0'
# define MINUS	'-'
# define PLUS	'+'

typedef struct	s_struct {
	int				i;
	int				ret;
	int				minus;
	int				plus;
	int				space;
	int				sharp;
	int				got_precision;
	int				precision;
	int				width;
	int				zero;
	int				base;
	int				lower;
	int				sign;
	int				uns;
	int				parse;
	enum {
		none,
		hh,
		h,
		l,
		ll,
		L
	}				length;
}				t_struct;

/*
**	ft_printf.c
*/

int				ft_printf(const char *format, ...);

/*
**	parsing.c
*/

void			format_handler(const char *format, t_struct *t, va_list args);
void			spec_handler(const char *f, t_struct *t, va_list args);
void			modif_handler(char const *format, t_struct *t);
void			set_length(char const *format, t_struct *t);
void			init_struct(t_struct *t);

/*
**	aux_functionc.c
*/

void			put_chars_ret(int nb, t_struct *t, char c);
void			putstr_ret(char const *str, t_struct *t);
char			*get_itoa_base(long long res, t_struct *t);
int				get_len_base(long long res, t_struct *t);
u_int64_t		get_unsigned_argument(t_struct *t, va_list args);

/*
**	decimal_manager.c && decimal_manager_2.c
*/

void			put_sign(t_struct *t, long long res);
void			zero_manager(t_struct *t, long long res);
void			put_zero_flag(t_struct *t, long long res);
void			put_zero_precision(t_struct *t, long long res);
void			put_blank_left(t_struct *t, long long res);
void			put_blank_right(t_struct *t, long long res);
void			print_d(t_struct *t, long long res);
void			print_decimal(t_struct *t, long long res);
void			manage_decimal(t_struct *t, va_list args);

/*
**	uint_manager.c
*/

void			manage_uint(t_struct *t, va_list args);
/*
**	octal_manager.c
*/

void			print_o(t_struct *t, long long res);
void			print_o_left(t_struct *t, long long res);
void			manage_octal(t_struct *t, va_list args);

/*
**	hexa_manager.c
*/

void			filler(t_struct *t, long long res, int zeros);
void			print_hex(t_struct *t, long long res, int zeros, int l);
void			print_hex_left(t_struct *t, long long res, int zeros, int l);
void			manage_hexa(t_struct *t, va_list args);

/*
**	float_manager.c && longdbl_manager.c
*/

char			*get_result_dbl(t_struct *t, double f_res, int round_int);
void			print_dbl(t_struct *t, double res);
void			print_dbl_left(t_struct *t, double res);
void			manage_float(t_struct *t, va_list args);
char			*get_result_ldbl(t_struct *t, long double f_r, int round_int);
void			print_ldbl(t_struct *t, long double res);
void			print_ldbl_left(t_struct *t, long double res);
void			print_long_double(t_struct *t, long double res);

/*
**	float_aux_functions.c
*/

void			round_fraction_double(double *f_dec, int precision);
void			round_fraction_ldbl(long double *f_dec, int precision);
void			dbl_to_tab(char (*res)[1024], int i, int p, double f);
void			ldbl_to_tab(char (*r)[1024], int i, int p, long double f);
int				error_in_rounding(char (*res)[1024]);

/*
**	ptr_manager.c
*/

char			*get_addr(unsigned long long res);
void			print_p(t_struct *t, void *res);
void			print_p_left(t_struct *t, void *res);
void			print_ptr(t_struct *t, void *res);
void			manage_ptr(t_struct *t, va_list args);

/*
**	str_manager.c
*/

void			put_strings_ret(int len, t_struct *t, char *str);
void			precision_zero(t_struct *t);
void			print_s_left(t_struct *t, char *res);
void			print_s(t_struct *t, char *res);
void			manage_str(t_struct *t, va_list args);

/*
**	char_manager.c
*/

void			print_c(t_struct *t, char res);
void			print_c_left(t_struct *t, char res);
void			print_char(t_struct *t, int res);
void			manage_char(t_struct *t, va_list args);

#endif
