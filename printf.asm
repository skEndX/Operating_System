CODE   SEGMENT
   ASSUME CS:CODE, DS:CODE

   MOV   AX, CS ;코드세그먼트를 ax에 이동
   MOV   DS, AX ;ax를 데이터 세그먼트에 이동
   MOV   CX, string ;루프 카운트

scanf:         
   MOV   AH, 1   ;키보드 입력 받기
   INT   21H
   
   PUSH   AX
   LOOP   scanf

   MOV CX, string

   MOV DL, 32 ;한칸 공백 입력
   MOV AH,2
   INT 21H

printf:
   POP   AX ;스택 값 pop하고 출력
   MOV   DL, AL
   MOV   AH, 2
   INT   21H
   LOOP printf

   MOV AH, 4CH
   INT   21H

string   DW   10
CODE   ENDS
   END