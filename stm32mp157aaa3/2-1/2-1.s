.IF 1
	MOV R1,#0X01
	RSB R0,R1,#0XFF @反减
.ENDIF

.IF 0
	MRS R0,CPSR
	BIC R0,#0X3 @按位清零
	MSR CPSR,R0
	NOP
	NOP
.ENDIF
.IF 0
	MOV R0,#0X2
	MOV R1,#0X1
	MOV R2,#0X1
	MOV R3,#0XFFFFFFFF
	
	SUB R5,R1,R3
	SBC R4,R0,R2  @借位
	NOP
	NOP
.ENDIF	

.IF 0
	MOV R0,#0X1
	MOV R1,#0XFFFFFFFF
	MOV R2,#0X1
	MOV R3,#0X1
	
	ADDS R5,R3,R1
	ADC R4,R0,R2   @进位
	NOP
	NOP
.ENDIF

.IF 0
	MOV R0,#5
	MOV R1,#3
	CMP R0,R1      @ CPSR
	SUBHI R0,R0,R1 @ R0<-(R0-R1)
	SUBLS R1,R1,R0 
.ENDIF

@compare command
.IF 0
	MOV R0,#2
	CMP R0,#2
	CMP R0,#3
	
	MOV R0,#2
	CMN R0,#-2
	
	MOV R0,#16
	TST R0,#(1<<4)
	
	MOV R0,#234
	TEQ R0,#234
.ENDIF

@transmit commmand
.IF 0
	MOV R0,#1
	MVN R0,#1
.ENDIF
	