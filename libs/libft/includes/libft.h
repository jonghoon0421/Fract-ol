/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonkim <jonkim@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/09 16:58:58 by jonkim            #+#    #+#             */
/*   Updated: 2018/01/11 01:20:27 by jonkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <stdarg.h>
# include <limits.h>

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

/*
** libft
*/
void				*ft_memcpy(void *str1, const void *str2, size_t n);
void				*ft_memccpy(void *str1, const void *str2, int c, size_t n);
void				*ft_memmove(void *str1, const void *str2, size_t n);
void				*ft_memchr(const void *str, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
char				*ft_strncpy(char *dest, const char *src, size_t n);
char				*ft_strncat(char *dest, const char *src, size_t n);
size_t				ft_strlcat(char *dest, const char *src, size_t size);
char				*ft_strrchr(const char *str, int c);
char				*ft_strstr(const char *big, const char *small);
char				*ft_strnstr(const char *big, const char *small, size_t n);
int					ft_strcmp(const char *str1, const char *str2);
int					ft_strncmp(const char *str1, const char *str2, size_t n);
int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
int					ft_tolower(int c);
void				ft_memdel(void **ap);
void				ft_strdel(char **as);
void				ft_strclr(char *s);
void				ft_striter(char *s, void (*f)(char*));
void				ft_striteri(char *s, void (*f)(unsigned int, char*));
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strtrim(char const *s);
char				**ft_strsplit(char const *s, char c);
void				ft_putendl(char const *s);
void				ft_putnbr(int n);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr_fd(int n, int fd);
t_list				*ft_lstnew(void const *content, size_t content_size);
void				ft_lstdelone(t_list **alst, void (*del)(void*, size_t));
void				ft_lstdel(t_list **alst, void (*del)(void*, size_t));
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));

int					ft_atoi_base(const char *s, int base);
char				*ft_itoa_base(int value, int base);
char				*ft_str_upcase(char *str);
char				*ft_str_lowcase(char *str);

/*
** get_next_line
*/

# define BUFF_SIZE 2

int					get_next_line(const int fd, char **line);
int					get_line(int fd, char **data, char **line);

/*
** ft_printf
*/

# define CHECK_TYPE "sSpdDioOuUxXcC"
# define CHECK_VALID "#0-+ 123456789.hljz*"
# define CHECK_NUM "123456789"
# define CHECK_FLAG "#0-+ "
# define CHECK_ENUM "hljz"
# define CHECK_OCTHEX "oOxX"

typedef enum		e_lmod
{
	pf_none,
	pf_hh,
	pf_h,
	pf_l,
	pf_ll,
	pf_j,
	pf_z
}					t_lmod;

typedef struct		s_pf_opt
{
	int				hash;
	int				sp;
	int				plus;
	int				minus;
	int				zero;
	int				prec;
	int				g_prec;
	int				width;
	int				g_width;
	t_lmod			lmod;
	int				g_lmod;
	char			type;
	int				neg;
}					t_pf_opt;

typedef struct		s_printf
{
	int				ret;
	va_list			ap;
	int				str_i;
	long			num;
	unsigned long	unum;
	int				chrtmp;
	char			*strtmp;
	char			*output;
	char			*tmp;
	t_pf_opt		arg;
	int				n_flag;
	wchar_t			wchr;
	wchar_t			*wstr;
}					t_printf;

/*
** libft_func1.c
*/
void				*ft_memset(void *str, int c, size_t n);
void				ft_bzero(void *str, size_t n);
void				ft_putchar(char c);
char				*ft_strcat(char *dest, const char *src);
char				*ft_strchr(const char *str, int c);

/*
** libft_func2.c
*/
size_t				ft_strlen(const char *s);
void				ft_putstr(char const *s);
char				*ft_strdup(const char *s1);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strcpy(char *dest, const char *src);

/*
** libft_func3.c
*/
int					ft_find_length(int n);
int					ft_atoi(const char *str);
char				*ft_itoa(int n);
char				*ft_uitoa(unsigned int n);
char				*ft_ultoa_base(unsigned long n, int base);

/*
** libft_func4.c
*/
char				*ft_ultoa(unsigned long n);
char				*ft_uitoa_base_cap(unsigned int n, int base);
char				*ft_uitoa_base(unsigned int n, int base);
char				*ft_ltoa(long n);
int					ft_toupper(int c);

/*
** libft_func5.c
*/
void				*ft_memalloc(size_t size);
char				*ft_strnew(size_t size);

/*
** ft_printf.c
*/
int					ft_printf(const char *format, ...);
void				ft_printf_parse(const char *format, t_printf *pf);

/*
** ft_init.c
*/
void				ft_init_arg(t_printf *pf);

/*
** ft_check.c
*/
void				ft_check_flag(const char *format, t_printf *pf);
void				ft_check_flag_prec(const char *format, t_printf *pf);
void				ft_check_bflag(const char *format, t_printf *pf);
void				ft_check_enum(const char *format, t_printf *pf);
void				ft_check_type(const char *format, t_printf *pf);

/*
** ft_set_i.c
*/
void				ft_set_int(const char *format, t_printf *pf);
void				ft_set_iprec(t_printf *pf);
void				ft_set_int_lmod(t_printf *pf);
void				ft_set_uint(const char *format, t_printf *pf);
void				ft_set_uint_lmod(t_printf *pf);

/*
** ft_work_int.c
*/
void				ft_work_int_zero(t_printf *pf);
void				ft_work_int_left(t_printf *pf);
void				ft_work_int_wpad(t_printf *pf);
int					ft_set_iprec_prep(t_printf *pf);

/*
** ft_set_lcs.c
*/
void				ft_set_lcs(const char *format, t_printf *pf);
void				ft_set_lc(t_printf *pf);
void				ft_set_lsprec(t_printf *pf);
void				ft_set_ls(t_printf *pf);

/*
** ft_set_ls_subfunc.c
*/
void				ft_set_ls_subfunc1(t_printf *pf, int length);
void				ft_set_ls_subfunc2(t_printf *pf, int length);
void				ft_set_ls_subfunc3(t_printf *pf, int length);

/*
** ft_set_ptraddr.c
*/
void				ft_set_ptraddr(const char *format, t_printf *pf);
void				ft_set_ptraddr_wpad(t_printf *pf);
void				ft_set_ptraddr_zero(t_printf *pf);
void				ft_set_ptraddr_left(t_printf *pf);

/*
** ft_set_xi.c
*/
void				ft_set_xint(const char *format, t_printf *pf);
void				ft_set_xint_lmod(t_printf *pf, int base);
void				ft_set_xiprec(t_printf *pf);
void				ft_set_xint_hash(t_printf *pf);

/*
** ft_work_xint.c
*/
void				ft_work_xint_zero(t_printf *pf);
void				ft_work_xint_zero_part2(t_printf *pf, int length);
void				ft_work_xint_left(t_printf *pf);
void				ft_work_xint_wpad(t_printf *pf);

/*
** ft_set_percent.c
*/
void				ft_set_percent(t_printf *pf);
void				ft_set_percent_zero(t_printf *pf);
void				ft_set_percent_left(t_printf *pf);
void				ft_set_percent_wpad(t_printf *pf);

/*
** ft_work_uint.c
*/
void				ft_work_uint_zero(t_printf *pf);
void				ft_work_uint_left(t_printf *pf);
void				ft_work_uint_wpad(t_printf *pf);

/*
** ft_set_general.c
*/
void				ft_set_general(const char *format, t_printf *pf);
void				ft_set_general_zero(t_printf *pf);
void				ft_set_general_left(t_printf *pf);
void				ft_set_general_wpad(t_printf *pf);

/*
** ft_set_wcs.c
*/
void				ft_set_wcs(const char *format, t_printf *pf);
void				ft_set_wchr(t_printf *pf);
void				ft_set_wstr(t_printf *pf);

/*
** ft_work_wchr.c
*/
void				ft_work_wchr_null(t_printf *pf);
void				ft_work_wchr_left(t_printf *pf);
void				ft_work_wchr_putchar(char c);
void				ft_work_wchr_wchar(t_printf *pf);

/*
** ft_work_wstr.c
*/
void				ft_work_wstr_null(t_printf *pf);
void				ft_work_wstr_putchar(t_printf *pf, char c);
void				ft_work_wstr_wstr(t_printf *pf, int i);
int					ft_work_wstr_len(t_printf *pf);
void				ft_work_wstr_left(t_printf *pf, int length);

/*
** ft_asterisk.c
*/
void				ft_asterisk_width(t_printf *pf);
void				ft_asterisk_prec(t_printf *pf);

#endif
