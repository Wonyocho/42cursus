/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonyocho <wonyocho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 13:39:47 by wonyocho          #+#    #+#             */
/*   Updated: 2023/10/23 20:47:04 by wonyocho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// static 변수를 이용한다.
// read 함수의 리턴값은 int이다. -> i로 이용

// case 1: (충분히 파일일 때)bufsize 만큼 읽었으나 개행문자가 없을 경우
// case 2: (충분히 파일일 때)bufsize 만큼 읽었으나 개행문자가 있었을 경우

char	*get_next_line(int fd)
{
	static char	*buf;				// static: 다음 get_next_line이 실행되어도 이어서
	static int	buf_size;			// static: 다음 get_next_line이 실행되어도 이어서
	static int	i;					// static: 다음 get_next_line이 실행되어도 이어서
	static int	n;					//
	static char	*str;				//
	
	str = NULL;
	n = 0;
	buf_size = 10;
	buf = (char *)malloc(sizeof(char) * buf_size);
	str = (char *)malloc(sizeof(char) * buf_size + 1);
	i = read(fd, buf, buf_size);	// buf_size 만큼 읽고 buf에 저장, i = 읽어들인 바이트수
	if (i == - 1)					// read 실패시 예외처리
		return (NULL);
	while (n < i)					// buf안에서 '\n'찾아서 str에 저장
	{
		str[n] = buf[n];			// str에다가 buf 하나씩저장
		if (buf[n] == '\n')			// 인덱스 증가시키면서 '\n'찾기
		{
			n++;
			break ;
		}
		n++;
	}
	i = n;							// case 1 일때는?
	str[n] = '\0';
	return (str);
}


int main ()
{
	int fd;

	fd = open("test.txt", O_RDONLY);
	printf("1) GNL 1:%s\n", get_next_line(fd));
	printf("1) GNL 2:%s\n", get_next_line(fd));
	printf("1) GNL 3:%s\n", get_next_line(fd));
	printf("1) GNL 4:%s\n", get_next_line(fd));
	printf("1) GNL 5:%s\n", get_next_line(fd));
	printf("1) GNL 6:%s\n", get_next_line(fd));
}