/*
 * Mikoto kernel head.S
 */

.text
.code 32

.globl 	mikoto_kernel_start

mikoto_kernel_start:
	ldr sp, =stack_top
	bl kernel_main

