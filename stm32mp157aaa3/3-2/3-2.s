.text
.global _start
_start:
@0
	b reset
@4
	b undef_handler
@8
	b swi_handler
	b perfetch_handler
	b databort_handler
	nop
	b irq_handler
	b fiq_handler
	

reset:
	ldr r0,=svc_stack
	add r0,#128
	mov sp,r0	@初始化sv的sp
	
	mrs r0,cpsr
	bic r0,#3
	msr cpsr,r0 @进入user模式
	
	ldr r0,=user_stack
	add r0,#128
	mov sp,r0	@初始化user的sp
	
	mov r1,#11
	mov r2,#12
	mov r3,#13
	
	swi 10
	nop
	nop
	nop
	
	b .
undef_handler:
swi_handler:
	stmfd sp!,{r0-r12,lr}
	mov r1,#1
	mov r2,#2
	mov r3,#3
	
	sub lr,#4
	ldr r4,[lr]
	bic r4,#0xff000000
	cmp r4,#10
	beq swi_10
	cmp r4,#1
	b swi_end
	
	nop
	nop
	nop
	
	movs pc,lr	@跳转回reset

swi_10:
	ldmfd sp!,{r0-r12,pc}^
swi_end:
	movs r0,#0
	ldmfd sp!,{r0-r12,pc}^	@^ 出栈的同时将当前的spsr->cpsr
perfetch_handler:
databort_handler:
irq_handler:
fiq_handler:
	
.data
svc_stack: .space 128
user_stack: .space 128
.end
