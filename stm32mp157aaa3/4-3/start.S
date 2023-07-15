.text
.global	_start

_start:
@ 异常向量表
	b reset
	ldr pc, _undefined_instruction
	ldr pc, _software_interrupt
	ldr pc, _prefetch_abort
	ldr pc, _data_abort
	ldr pc, _not_used
	ldr pc, _irq
	ldr pc, _fiq

_undefined_instruction:
	.word undefined_instruction
_software_interrupt:
	.word software_interrupt
_prefetch_abort:
	.word prefetch_abort
_data_abort:
	.word data_abort
_not_used:
	.word not_used
_irq:
	.word irq
_fiq:
	.word fiq

 /* The actual reset code */
reset:
	@ 重新映射异常向量表的入口地址
	/* Set Vector Base Address Register */

	ldr	r0,=0xc0008000
	mcr	p15,0,r0,c12,c0,0		@ Vector Base Address Register


	/* Disable mmu stuff and caches */
	mrc p15, 0, r0, c1, c0, 0
	bic r0, r0, #0x00000007
	mcr p15, 0, r0, c1, c0, 0
	
	ldr r0,stacktop
	mov sp,r0

	sub r0,#512
	msr	cpsr, #0xd2
	mov	sp, r0

	sub r0,#512
	msr	cpsr, #0x10
	mov sp,r0

	b main     @ 汇编调用C  跳转到main.c文件的main函数中


/*
 * Exception handlers
 */
	.align 2  // 2的5次方，=32bit 也就是4字节对其
undefined_instruction:
	b	.

	.align 2
software_interrupt:
	b	.

	.align 2
prefetch_abort:
	b	.

	.align 2
data_abort:
	b	.

	.align 2
not_used:
	b	.

	.align 2

.global irq
irq:
	sub  lr, lr, #4
	stmfd sp!, {r0-r12, lr}
.weak do_irq
	bl do_irq
	ldmfd sp!, {r0-r12, pc}^

	.align 2
.global fiq
fiq:
	b .

stacktop:    .word 		stack + 4 * 512
.data

stack:	 .space  4 * 512


