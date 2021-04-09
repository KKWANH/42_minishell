#include "minishell.h"

t_mns				*g_mns;

void				ft_minishell_read_eof(char *lin)
{
	ft_util_putstr_fd("  \b\b", 1);
	if (ft_util_strlen(lin) != 0)
		g_mns->tmp = lin;
	if (ft_util_strlen(g_mns->tmp) == 0)
	{
		printf("exit\n");
		exit(0);
	}
}

void				ft_minishell_main(void)
{
	char			*lin;
	int				rst;
	int				tmp;

	lin = ft_util_strdup("");
	tmp = 0;
	while ((rst = read(0, &tmp, sizeof(tmp))) > 0)
	{
		if (tmp == LEFT_ARROW)
			write(1, "    \b\b\b\b", 8);
		else if (tmp == RIGHT_ARROW)
			write(1, "    \b\b\b\b", 8);
		else if (tmp == ENTER)
		{
			write(1, "\n", 1);
			ft_parse(lin);
			free(lin);
			lin = ft_util_strdup("");
			ft_prompt_put_msg();
		}
		else if (tmp == CTRL_D)
		{
			write(1, "EOF!", 4);
			exit(0);
		}
		else
		{
			write(0, &tmp, 1);
			char str;
			str = tmp;
			lin = ft_util_chajoin(lin, str);
		}
		tmp = 0;
	}
}

int					main(int arc, char **arv, char **env)
{
	if (!(g_mns = (t_mns *)malloc(sizeof(t_mns))))
		return (-1);
	ft_init(env);
	// while (1)
	// {
	// 	ft_prompt_put_msg();
	// 	while (get_next_line(0, &lin) == 0)
	// 		ft_minishell_read_eof(lin);
	// 	ft_parse(lin);
	// 	free(lin);
	// 	g_mns->tmp = NULL;
	// }
	ft_minishell_main();
	return (0);
}