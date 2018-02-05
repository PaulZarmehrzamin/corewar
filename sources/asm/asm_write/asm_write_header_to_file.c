/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_write_header_to_file.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mplanell <mplanell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/25 18:49:05 by mplanell          #+#    #+#             */
/*   Updated: 2017/11/01 16:04:29 by mressier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include "libft.h"

static int		internal_swap_endian(int data)
{
	return ((data << 24) | ((data << 8) & 0x00FF0000) |
									((data >> 8) & 0x0000FF00) | (data >> 24));
}

void			asm_write_header_to_file(t_asm *asm_file_content, int fd)
{
	t_header *header;

	header = &asm_file_content->header;
	header->magic = COREWAR_EXEC_MAGIC;
	header->magic = internal_swap_endian(header->magic);
	header->prog_size = internal_swap_endian(header->prog_size);
	write(fd, header, sizeof(t_header));
}
