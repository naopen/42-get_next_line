/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkannan <nkannan@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 08:46:56 by nkannan           #+#    #+#             */
/*   Updated: 2024/02/06 08:46:56 by nkannan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// ファイルディスクリプタからデータを読み込み、結果を保存する関数
char *read_and_store_data(int fd, char **score)
{
	char *buf;
	int read_size;

	while (1)
	{
		buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (!buf)
			return (NULL);
		read_size = read(fd, buf, BUFFER_SIZE);
		if (read_size == -1)
			return (free(buf), NULL);
		buf[read_size] = '\0';
		if (*score == NULL)
			*score = ft_strdup_gnl(buf);
		else
			*score = ft_strjoin_gnl(*score, buf);
		free(buf);
		if (*store == NULL)
			return (NULL);
		if (ft_strchr_gnl(*score, '\n') || read_size == 0)
			break ;
	}
	return (*score);
}

// 保存された文字列から1行を抽出する関数
char *get_line(char *store)
{
	char *line;
	size_t cnt;

	while (store[cnt] != '\n' && store[cnt] != '\0')
		cnt++;
	if (store[cnt] == '\n')
		cnt++;
	line = (char *)malloc(sizeof(char) * (cnt + 1));
	if (!line)
		return (free(store), NULL);
	cnt = 0;
	while (store[cnt] != '\n' && store[cnt] != '\0')
	{
		line[cnt] = store[cnt];
		cnt++;
	}
	if (store[cnt] == '\n') // 消せるかも？
	{
		line[cnt] = store[cnt];
		cnt++;
	}
	line[cnt] = '\0';
	return (line);
}


// 既に取り出された行をストアから削除し、残ったデータを更新する関数
char *update_store(char *store)
{
	char *new_store;
	size_t cnt;

	while (store[cnt] != '\n' && store[cnt] != '\0')
		cnt++;
	if (store[cnt] == '\0')
	{
		free(store);
		return (NULL);
	}
	new_store = ft_strdup_gnl(&store[cnt]);
	free(store);
	return (new_store);
}


char	*get_next_line(int fd)
{
	static char	*store[OPEN_MAX];
	char		*line;

	if (fd < 0 || OPEN_MAX <= fd || BUFFER_SIZE <= 0)
		return (NULL);
	store[fd] = read_buffer(fd, store);
	if (store[fd] == NULL)
		return (NULL);
	line = concat_to_line(store[fd]);
	if (line == NULL)
		return (NULL);
	store[fd] = update_store(store[fd]);
	if (store[fd] == NULL && line[0] == '\0')
		return (free(line), NULL);
	return (line);
}
