// SelfModifyCode.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//
// Cette solution intègre un fichier .obj compilé pavec uasm, et fait appel aux fonction du fichier obj.
// Cf. source en fin de cette page

#include <iostream>
using namespace std;

extern "C" int DoSelf(int i);
extern "C" long  addValues64(long i, long j); // fonc extern dans fichier obj compilé pavec uasm64
int i;

int main()
{
    std::cout << "Hello World!\n";
    i = addValues64(1, 2);      // fonction externe du fichier obj
    cout << "Resultat de l'addition faite dans un obj externe : " << i << endl;

    for (i=0;i<10;i++){

    cout << DoSelf(100) << endl;
    }

}

/*  Source de asmFile64.obj (compilé avec uasm64)
; To compile with MASM
; <path>\ml64.exe asmFile64.asm
; Compile with JWASM
; <path>\jwasm - win64 asmFile64.asm

externdef MessageBoxW : NEAR


.data
myReturnString dw "I", " ", "a", "m", " ", "b", "a", "c", "k", " ", "i", "n"
dw " ", "D", "e", "l", "p", "h", "i", "!", 0
endOfString dw 0

.code

; General rule : Integer and pointer arguments are passed
; left to right in RCX, RDX, R8and R9
; Simple results are returned in RAX

addValues64 proc
mov rax, rcx
add rax, rdx
ret
addValues64 endp


; The general rule is integerand pointer arguments are passed
; left to right in RCX, RDX, R8and R9
; HOWEVER, when there is a large return value, this is the case here,
; RCX contains a pointer to the return space when the callee
; is calledand all Registers usage are pushed one to the right

showMsgGetArray64 proc
push rsi
push rdi
push rbx
push rbp
sub rsp, 28h

xor r9, r9
mov rbx, rcx
mov rax, rdx
mov rdx, r8
mov r8, rax
xor rcx, rcx
call MessageBoxW

mov rdi, rbx
mov rsi, offset myReturnString
mov ecx, offset endOfString - offset myReturnString
shr ecx, 1
rep movsw
add rsp, 28h
pop rbp
pop rbx
pop rdi
pop rsi
ret
showMsgGetArray64 endp

end
*/