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

void				ft_minishell_init(char **str)
{
	ft_signal_set();
	g_mns->env_str = str;
	g_mns->env = ft_env_init();
	g_mns->pth = 0;
	g_mns->ext = 0;
	g_mns->tmp = NULL;
}

int					main(int arc, char **arv, char **env)
{
	char			*lin;

	if (!(g_mns = (t_mns *)malloc(sizeof(t_mns))))
		return (-1);
	ft_minishell_init(env);
	while (1)
	{
		ft_prompt_put_msg();
		while (get_next_line(0, &lin) == 0)
			ft_minishell_read_eof(lin);
		ft_parse(lin);
		free(lin);
		g_mns->tmp = NULL;
	}
	
}