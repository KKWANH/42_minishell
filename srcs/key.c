#include "../minishell.h"

extern t_mns		*g_mns;

char				*ft_key_backspace(int *col, int *row, char *lin, t_cap *cap)
{
	if (cap->p_col >= *col)
		return (lin);
	*col -= 1;
	tputs(tgoto(cap->cm, *col, *row), 1, ft_util_putchar);
	tputs(cap->dc, 1, ft_util_putchar);
	lin = ft_util_chaout(lin, g_mns->idx);
	g_mns->idx -= 1;
	return (lin);
}

void				ft_key_left(int *col, int *row, t_cap *cap)
{
	if (cap->p_col >= *col)
		return ;
	*col -= 1;
	g_mns->idx -= 1;
	tputs(tgoto(cap->cm, *col, *row), 1, ft_util_putchar);
}

void				ft_key_right(int *col, int *row, char *lin, t_cap *cap)
{
	if (ft_util_strlen(lin) <= g_mns->idx + 1)
		return ;
	*col += 1;
	g_mns->idx += 1;
	tputs(tgoto(cap->cm, *col, *row), 1, ft_util_putchar);
}
