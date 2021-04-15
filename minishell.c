#include "minishell.h"

t_mns				*g_mns;


void				ft_minishell_input_main(int col, int row, int tmp)
{
	char			chr;
	int				rst;

	while (read(0, &tmp, sizeof(tmp)) > 0)
	{
		rst = ft_cursor(&col, &row, tmp);
		if (rst == -1)
			return ;
		if (rst == 0)
		{
			chr = tmp;
			if (chr == '\t')
				continue ;
			write(0, &tmp, 1);
			g_mns->lin = ft_util_chajoin(g_mns->lin, chr);
			++g_mns->idx;
		}
		tmp = 0;
	}
}

int					main(int arc, char **arv, char **env)
{
	struct termios	s_term;
	struct termios	s_backup;

	if (!(g_mns = (t_mns *)malloc(sizeof(t_mns))))
		return (-1);
	ft_init(env, &s_term, &s_backup);
	while (1)
	{
		ft_prompt_put_msg();
		// NonCanonical
		tcsetattr(STDIN_FILENO, TCSANOW, &s_term);
		ft_cursor_whereisit(&g_mns->cap.p_col, &g_mns->cap.p_row);
		g_mns->lin = ft_util_strdup("");
		ft_minishell_input_main(0, 0, 0);
		// Backup
		tcsetattr(STDIN_FILENO, TCSANOW, &s_backup);
		ft_parse(g_mns->lin);
		free(g_mns->lin);
	}
	return (0);
}