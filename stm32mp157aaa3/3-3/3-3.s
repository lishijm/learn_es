	LDR R0,=ARR1
	LDR R1,=ARR2
	MOV R9,#0
	MOV R12,#3
	MOV R10,R0
BCMP:
	MOV R5,R0
	LDRB R2,[R0],#1
	CMP R2,#0
	BEQ BRL1
BCMPL2:
	MOV R6,R0
	LDRB R3,[R0],#1
	CMP R3,#0
	BEQ BRL2
	B BCMPC
BCMPC:
	CMP R12,#1
	BEQ ENDI
	CMP R2,R3
	BGE BGST
	ADD R11,#1
	MOV R4,R3
	MOV R7,R6
	CMP R11,R12
	BEQ INAR
CMPN:
	MOV R5,R0
	LDRB R2,[R0],#1
	CMP R2,#0
	BEQ RL
	B CMPNC
CMPNC:
	CMP R2,R4
	BGE BGST
	ADD R11,#1
	CMP R11,R12
	BEQ INAR
	B CMPN
BRL1:
	MOV R5,R0
	LDRB R2,[R0],#1
	CMP R2,#0
	BEQ BRL1
	B BCMPL2
BRL2:
	MOV R6,R0
	LDRB R3,[R0],#1
	CMP R3,#0
	BEQ BRL2
	B BCMPC
RL:
	MOV R5,R0
	LDRB R2,[R0],#1
	CMP R2,#0
	BEQ RL
	B CMPNC
BGST:
	ADD R11,#1
	MOV R7,R5
	MOV R4,R2
	B CMPN
INAR:
	STRB R4,[R1],#1
	MOV R0,R7
	STRB R9,[R0]
	MOV R0,R10
	SUB R12,#1
	MOV R11,#0
	B BCMP
ENDI:
	CMP R2,R3
	BGE ENDII
	STRB R3,[R1],#1
	STRB R2,[R1],#1
ENDII:
	STRB R2,[R1],#1
	STRB R3,[R1],#1
.DATA
	ARR1: .BYTE 0X04,0X02,0X03,0X01
	ARR2: .SPACE 4
