;******************************************************************************;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_strncmp.s                                       :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: pguillie <pguillie@student.42.fr>          +#+  +:+       +#+         ;
;                                                 +#+#+#+#+#+   +#+            ;
;    Created: 2019/10/06 17:18:56 by pguillie          #+#    #+#              ;
;    Updated: 2019/10/06 17:44:01 by pguillie         ###   ########.fr        ;
;                                                                              ;
;******************************************************************************;

global ft_strncmp

section .text
ft_strncmp:
	push	rbp
	mov	rbp, rsp
	mov	rcx, rdx
	repe cmpsb
	dec	rdi
	dec	rsi
	movzx	rax, byte [rdi]
	movzx	rdx, byte [rsi]
	sub	rax, rdx
	mov	rsp, rbp
	pop	rbp
	ret
