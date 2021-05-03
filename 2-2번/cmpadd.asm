CODE   SEGMENT
	ASSUME CS:CODE, DS:CODE

	MOV AX, CS
	MOV DS, AX
	MOV DI, OFFSET numbers
 	MOV CX,3		; 숫자 3개

SCANF:
	MOV AH, 01	;10의 자리 문자 입력 명령
	INT   21H
	MOV BH, AL 	;10의 자리
	SUB BH, 48; 	;'0'값이 48 아스키코드 숫자로 변경

	MOV AH, 01	;1의 자리 문자 입력 명령
	INT 21H
	MOV BL, AL 	;1의 자리
	SUB BL, 48; 	;'0'값이 48

	MOV AL, 10	;10의 자리 수에 10을 곱함
	MUL BH
	ADD BL, AL   	;더해서 10진수 생성

	MOV [DI], BL	;DI에 저장
	ADD DI, 2		;다음 숫자로 넘어감
	LOOP SCANF
  
	MOV DL, 10    	;줄바꿈
	MOV AH, 02	;문자 출력 명령
	INT 21H
;--------------------------------------------------------------------

	MOV DI, OFFSET numbers

	MOV AX,[DI]	;첫번째 숫자 꺼내기
	MOV MAX,AX

COMPARE1:
	ADD DI,2		; 다음 숫자로 넘어감
	MOV AX,[DI]	; 두번째 숫자 꺼내기
	MOV TMP,AX

	CMP AX, MAX	;첫번째와 두번째 비교
	JBE SE1		;작거나 같으면
	JA G1		;크다면
SE1:
	MOV MIN, AX	;작은 값 MIN에 저장
	JMP COMPARE2
G1:
	MOV CX, MAX	;MAX의 값 변경
	MOV MIN, CX
	MOV MAX, AX	;작은 값 MIN에 저장

COMPARE2:
	ADD DI,2	; 다음 숫자로 넘어감
	MOV AX,[DI]	; 세번째 숫자 꺼내기
	MOV TMP, AX

	CMP AX, MIN	; 작은 값과 비교
	JBE SE2	;작거나 같으면
	JA G2	;크면
SE2: 
	MOV AX, MAX	;MAX와 MIN 더하여 출력
	ADD AX, MIN
	JMP PRINTF
G2:
	MOV AX, MAX	;MAX와 TEMP 더하여 출력
	ADD AX, TMP
;--------------------------------------------------------------------

PRINTF:   
	MOV DL, 10	;10으로 나눔
	DIV DL
    
	MOV CX, AX

	MOV DL, CL	;10의 자리
	ADD DL, 48	; '0'의 값이 48
	MOV AH, 02	; 문자 출력 명령
	INT 21H

	MOV DL, CH	;1의 자리
	ADD DL, 48	
	MOV AH, 02	
	INT 21H

	MOV AH, 4CH
	INT 21H

numbers	DW 0,0,0
MAX	DW ?
MIN	DW ?
TMP	DW ?
CODE	ENDS
	END