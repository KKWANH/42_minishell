#include "minishell.h"
/*
 subject
 echo
 cd
 pwd
 export
 unset
 env
 exit
 */

char				**input_envp(char **envp)
{
	char			**dest;
	int				i;

	i = 0;
	while (envp[i])
		i++;
	dest = (char **)malloc(sizeof(char *) * (i + 1));
	if (dest == 0)
		return (0);
	i = 0;
	while (envp[i])
	{
		dest[i] = ft_strdup(envp[i]);
		i++;
	}
	dest[i] = 0;
	return (dest);
}

int 				main(int argc, char **argv, char **envp)
{
	char 			**envv;
	char 			*line;
	char 			*path;
	int				ret;

	envv = input_envp(envp);
//	while (*envv)
//		puts(*envv++);
	while (1)
	{
		printf("%s : ", getcwd(path, 128));
		ret = get_next_line(0, &line);
		if (ret >= 0)
		{
			printf("%s\n", line);
			free(line);
		}
		if (ft_strnstr(line, "exit", ft_strlen(line)))
			exit(1);
	}
//	while(1)
//	{
//		write_prompt();
//
//	}
	return (0);
}