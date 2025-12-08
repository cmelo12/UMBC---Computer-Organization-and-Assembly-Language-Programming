	.file	"matrix_operations.c"
	.intel_syntax noprefix
	.text
	.def	__main;	.scl	2;	.type	32;	.endef
	.section .rdata,"dr"
.LC0:
	.ascii "A\0"
.LC1:
	.ascii "B\0"
.LC2:
	.ascii "A*B+A\0"
	.text
	.globl	main
	.def	main;	.scl	2;	.type	32;	.endef
	.seh_proc	main
main:
	push	rbp
	.seh_pushreg	rbp
	mov	rbp, rsp
	.seh_setframe	rbp, 0
	sub	rsp, 224
	.seh_stackalloc	224
	.seh_endprologue
	call	__main
	mov	DWORD PTR -48[rbp], 1
	mov	DWORD PTR -44[rbp], 2
	mov	DWORD PTR -40[rbp], 3
	mov	DWORD PTR -36[rbp], 4
	mov	DWORD PTR -32[rbp], 5
	mov	DWORD PTR -28[rbp], 6
	mov	DWORD PTR -24[rbp], 7
	mov	DWORD PTR -20[rbp], 8
	mov	DWORD PTR -16[rbp], 9
	mov	DWORD PTR -96[rbp], 1
	mov	DWORD PTR -92[rbp], 2
	mov	DWORD PTR -88[rbp], 0
	mov	DWORD PTR -84[rbp], 3
	mov	DWORD PTR -80[rbp], 4
	mov	DWORD PTR -76[rbp], 5
	mov	DWORD PTR -72[rbp], 0
	mov	DWORD PTR -68[rbp], 6
	mov	DWORD PTR -64[rbp], 7
	lea	rax, -48[rbp]
	mov	rdx, rax
	lea	rax, .LC0[rip]
	mov	rcx, rax
	call	printMatrix
	mov	ecx, 10
	call	putchar
	lea	rax, -96[rbp]
	mov	rdx, rax
	lea	rax, .LC1[rip]
	mov	rcx, rax
	call	printMatrix
	mov	ecx, 10
	call	putchar
	lea	rcx, -96[rbp]
	lea	rdx, -48[rbp]
	lea	rax, -144[rbp]
	mov	r8, rcx
	mov	rcx, rax
	call	matmult
	lea	rcx, -48[rbp]
	lea	rdx, -144[rbp]
	lea	rax, -192[rbp]
	mov	r8, rcx
	mov	rcx, rax
	call	matadd
	lea	rax, -192[rbp]
	mov	rdx, rax
	lea	rax, .LC2[rip]
	mov	rcx, rax
	call	printMatrix
	mov	eax, 0
	add	rsp, 224
	pop	rbp
	ret
	.seh_endproc
	.globl	matmult
	.def	matmult;	.scl	2;	.type	32;	.endef
	.seh_proc	matmult
matmult:
	push	rbp
	.seh_pushreg	rbp
	mov	rbp, rsp
	.seh_setframe	rbp, 0
	sub	rsp, 16
	.seh_stackalloc	16
	.seh_endprologue
	mov	QWORD PTR 16[rbp], rcx
	mov	QWORD PTR 24[rbp], rdx
	mov	QWORD PTR 32[rbp], r8
	mov	DWORD PTR -4[rbp], 0
	jmp	.L4
.L7:
	mov	DWORD PTR -8[rbp], 0
	jmp	.L5
.L6:
	mov	eax, DWORD PTR -4[rbp]
	movsx	rdx, eax
	mov	rax, rdx
	add	rax, rax
	add	rax, rdx
	sal	rax, 2
	mov	rdx, rax
	mov	rax, QWORD PTR 16[rbp]
	add	rdx, rax
	mov	eax, DWORD PTR -8[rbp]
	cdqe
	mov	DWORD PTR [rdx+rax*4], 0
	add	DWORD PTR -8[rbp], 1
.L5:
	cmp	DWORD PTR -8[rbp], 2
	jle	.L6
	add	DWORD PTR -4[rbp], 1
.L4:
	cmp	DWORD PTR -4[rbp], 2
	jle	.L7
	mov	DWORD PTR -4[rbp], 0
	jmp	.L8
.L13:
	mov	DWORD PTR -8[rbp], 0
	jmp	.L9
.L12:
	mov	DWORD PTR -12[rbp], 0
	jmp	.L10
.L11:
	mov	eax, DWORD PTR -4[rbp]
	movsx	rdx, eax
	mov	rax, rdx
	add	rax, rax
	add	rax, rdx
	sal	rax, 2
	mov	rdx, rax
	mov	rax, QWORD PTR 16[rbp]
	add	rdx, rax
	mov	eax, DWORD PTR -8[rbp]
	cdqe
	mov	r8d, DWORD PTR [rdx+rax*4]
	mov	eax, DWORD PTR -4[rbp]
	movsx	rdx, eax
	mov	rax, rdx
	add	rax, rax
	add	rax, rdx
	sal	rax, 2
	mov	rdx, rax
	mov	rax, QWORD PTR 24[rbp]
	add	rdx, rax
	mov	eax, DWORD PTR -12[rbp]
	cdqe
	mov	ecx, DWORD PTR [rdx+rax*4]
	mov	eax, DWORD PTR -12[rbp]
	movsx	rdx, eax
	mov	rax, rdx
	add	rax, rax
	add	rax, rdx
	sal	rax, 2
	mov	rdx, rax
	mov	rax, QWORD PTR 32[rbp]
	add	rdx, rax
	mov	eax, DWORD PTR -8[rbp]
	cdqe
	mov	eax, DWORD PTR [rdx+rax*4]
	imul	ecx, eax
	mov	eax, DWORD PTR -4[rbp]
	movsx	rdx, eax
	mov	rax, rdx
	add	rax, rax
	add	rax, rdx
	sal	rax, 2
	mov	rdx, rax
	mov	rax, QWORD PTR 16[rbp]
	add	rdx, rax
	add	ecx, r8d
	mov	eax, DWORD PTR -8[rbp]
	cdqe
	mov	DWORD PTR [rdx+rax*4], ecx
	add	DWORD PTR -12[rbp], 1
.L10:
	cmp	DWORD PTR -12[rbp], 2
	jle	.L11
	add	DWORD PTR -8[rbp], 1
.L9:
	cmp	DWORD PTR -8[rbp], 2
	jle	.L12
	add	DWORD PTR -4[rbp], 1
.L8:
	cmp	DWORD PTR -4[rbp], 2
	jle	.L13
	nop
	nop
	add	rsp, 16
	pop	rbp
	ret
	.seh_endproc
	.globl	matadd
	.def	matadd;	.scl	2;	.type	32;	.endef
	.seh_proc	matadd
matadd:
	push	rbp
	.seh_pushreg	rbp
	mov	rbp, rsp
	.seh_setframe	rbp, 0
	sub	rsp, 16
	.seh_stackalloc	16
	.seh_endprologue
	mov	QWORD PTR 16[rbp], rcx
	mov	QWORD PTR 24[rbp], rdx
	mov	QWORD PTR 32[rbp], r8
	mov	DWORD PTR -4[rbp], 0
	jmp	.L15
.L18:
	mov	DWORD PTR -8[rbp], 0
	jmp	.L16
.L17:
	mov	eax, DWORD PTR -4[rbp]
	movsx	rdx, eax
	mov	rax, rdx
	add	rax, rax
	add	rax, rdx
	sal	rax, 2
	mov	rdx, rax
	mov	rax, QWORD PTR 24[rbp]
	add	rdx, rax
	mov	eax, DWORD PTR -8[rbp]
	cdqe
	mov	r8d, DWORD PTR [rdx+rax*4]
	mov	eax, DWORD PTR -4[rbp]
	movsx	rdx, eax
	mov	rax, rdx
	add	rax, rax
	add	rax, rdx
	sal	rax, 2
	mov	rdx, rax
	mov	rax, QWORD PTR 32[rbp]
	add	rdx, rax
	mov	eax, DWORD PTR -8[rbp]
	cdqe
	mov	ecx, DWORD PTR [rdx+rax*4]
	mov	eax, DWORD PTR -4[rbp]
	movsx	rdx, eax
	mov	rax, rdx
	add	rax, rax
	add	rax, rdx
	sal	rax, 2
	mov	rdx, rax
	mov	rax, QWORD PTR 16[rbp]
	add	rdx, rax
	add	ecx, r8d
	mov	eax, DWORD PTR -8[rbp]
	cdqe
	mov	DWORD PTR [rdx+rax*4], ecx
	add	DWORD PTR -8[rbp], 1
.L16:
	cmp	DWORD PTR -8[rbp], 2
	jle	.L17
	add	DWORD PTR -4[rbp], 1
.L15:
	cmp	DWORD PTR -4[rbp], 2
	jle	.L18
	nop
	nop
	add	rsp, 16
	pop	rbp
	ret
	.seh_endproc
	.section .rdata,"dr"
.LC3:
	.ascii "    [%d %d %d]\12\0"
.LC4:
	.ascii "%s = |%d %d %d|\12\0"
	.text
	.globl	printMatrix
	.def	printMatrix;	.scl	2;	.type	32;	.endef
	.seh_proc	printMatrix
printMatrix:
	push	rbp
	.seh_pushreg	rbp
	mov	rbp, rsp
	.seh_setframe	rbp, 0
	sub	rsp, 48
	.seh_stackalloc	48
	.seh_endprologue
	mov	QWORD PTR 16[rbp], rcx
	mov	QWORD PTR 24[rbp], rdx
	mov	rax, QWORD PTR 24[rbp]
	mov	ecx, DWORD PTR 8[rax]
	mov	rax, QWORD PTR 24[rbp]
	mov	edx, DWORD PTR 4[rax]
	mov	rax, QWORD PTR 24[rbp]
	mov	eax, DWORD PTR [rax]
	mov	r9d, ecx
	mov	r8d, edx
	mov	edx, eax
	lea	rax, .LC3[rip]
	mov	rcx, rax
	call	printf
	mov	rax, QWORD PTR 24[rbp]
	add	rax, 12
	mov	edx, DWORD PTR 8[rax]
	mov	rax, QWORD PTR 24[rbp]
	add	rax, 12
	mov	r8d, DWORD PTR 4[rax]
	mov	rax, QWORD PTR 24[rbp]
	add	rax, 12
	mov	ecx, DWORD PTR [rax]
	mov	rax, QWORD PTR 16[rbp]
	mov	DWORD PTR 32[rsp], edx
	mov	r9d, r8d
	mov	r8d, ecx
	mov	rdx, rax
	lea	rax, .LC4[rip]
	mov	rcx, rax
	call	printf
	mov	rax, QWORD PTR 24[rbp]
	add	rax, 24
	mov	ecx, DWORD PTR 8[rax]
	mov	rax, QWORD PTR 24[rbp]
	add	rax, 24
	mov	edx, DWORD PTR 4[rax]
	mov	rax, QWORD PTR 24[rbp]
	add	rax, 24
	mov	eax, DWORD PTR [rax]
	mov	r9d, ecx
	mov	r8d, edx
	mov	edx, eax
	lea	rax, .LC3[rip]
	mov	rcx, rax
	call	printf
	nop
	add	rsp, 48
	pop	rbp
	ret
	.seh_endproc
	.ident	"GCC: (Rev3, Built by MSYS2 project) 13.2.0"
	.def	putchar;	.scl	2;	.type	32;	.endef
	.def	printf;	.scl	2;	.type	32;	.endef
