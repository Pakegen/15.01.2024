/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quenalla <quenalla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 14:08:03 by qacjl             #+#    #+#             */
/*   Updated: 2025/01/15 12:38:53 by quenalla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "../utils/libft/libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <fcntl.h>
# define BUFFER_SIZE_2 4096 // Taille maximale à lire en une fois
# define MAX_BYTES 65536  // Limite totale de données transmises (64 KB)


void	pipex(char *infile, char *cmd1, char *cmd2, char *outfile, char **env);
void	execute_pipeline(char *cmd1, char *cmd2, int in_fd, int out_fd, int *pipefd, char **env);
void	create_child(int input_fd, int output_fd, char *cmd, char **env);
void	redirect(int input_fd, int output_fd);
void	wait_for_all_children(void);
void	run_command(char *cmd, char **env);
int		open_file(char *filename, int flags, int mode);
char	*find_command_path(char *cmd, char **env);
char	**get_env_paths(char **env);
char	*join_path(char *path, char *cmd);
void	free_split(char **split);
void	error_exit(const char *msg);
//void	limited_read_write(int input_fd, int output_fd);

#endif
