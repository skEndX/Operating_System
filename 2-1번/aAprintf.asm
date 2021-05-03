MAIN   SEGMENT
   ASSUME   CS:MAIN, DS:MAIN
   MOV AX,CS
   MOV DS,AX

   MOV DI, OFFSET string ;연속된 메모리 주소
   MOV CX, 100 ; 입력 100개

COMPARE:
   MOV AL, [DI]	;string 문자 하나 이동
   CMP AL, 97	;'a'의 값이 97
   JB PRINTF	;작으면 출력
   SUB AL,32	;'a'-'A'의 값이 32z

PRINTF:
   MOV [DI], AL 
   ADD DI, 1 ;string을 하나씩 옮겨가며 비교
   LOOP COMPARE
 
   MOV AH, 09      ;문자열 출력 명령
   MOV DX, OFFSET string
   INT 21H

   MOV AH, 4CH	;종료
   INT 21H

string DB '201801730 KimDaHee$'
MAIN   ENDS
   END