/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: insoares <insoares@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 16:01:39 by insoares          #+#    #+#             */
/*   Updated: 2024/10/28 11:22:31 by insoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <fcntl.h>
# include <sys/stat.h>
# include "libft/libft.h"

// -------------- pipex.c
int		exit_handler(int n_exit);
void	child_process(char **av, int *p, char **env);
void	child_process_2(char **av, char **env, int *p);
void	ft_child_process_2(char **av, char **env, int *p);

// --------------- pipex_utils.c
char	*ft_line_envp(char **env);
void	ft_free(char **str);
char	*ft_path(char *cmd, char **env);
void	ft_exec(char *av, char **env, int *p);
void	ft_close(int *p);

#endif