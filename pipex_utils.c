/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: insoares <insoares@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 16:57:23 by insoares          #+#    #+#             */
/*   Updated: 2024/10/28 11:30:37 by insoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*ft_line_envp(char **env)
{
	int	i;

	i = -1;
	while (env[++i])
	{
		if (ft_strnstr(env[i], "PATH=", 5))
			return (env[i]);
	}
	return (NULL);
}

void	ft_free(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free (str);
}

char	*ft_path(char *cmd, char **env)
{
	char	**all_paths;
	char	*half_path;
	char	*path;
	int		i;

	i = 0;
	if (!env[i])
		return (NULL);
	all_paths = ft_split((ft_line_envp(env)), ':');
	i = -1;
	while (all_paths[++i])
	{
		half_path = ft_strjoin(all_paths[i], "/");
		path = ft_strjoin(half_path, cmd);
		free(half_path);
		if (access(path, F_OK | X_OK) == 0)
			return (ft_free(all_paths), path);
		free(path);
	}
	return (ft_free(all_paths), NULL);
}

void	ft_exec(char *av, char **env, int *p)
{
	char	**cmd;
	char	*path;

	cmd = ft_split(av, ' ');
	path = ft_path(cmd[0], env);
	if (!path)
	{
		ft_free(cmd);
		ft_putstr_fd("execve1() error", 2);
		ft_close(p);
		exit(1);
	}
	if (execve(path, cmd, env) == -1)
	{
		ft_free(cmd);
		ft_free(&path);
		ft_close(p);
		ft_putstr_fd("execve2() error", 2);
		exit(1);
	}
	ft_free(cmd);
	ft_free(&path);
}

void	ft_close(int *p)
{
	close(p[1]);
	close(p[2]);
}
