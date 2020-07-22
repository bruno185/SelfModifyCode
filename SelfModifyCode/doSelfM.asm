MySegment segment read write execute

DoSelf proc
	mov eax,ecx
	mov bl,byte ptr modif+1
	cmp bl,0C0h
	jnz	LabelA8						; = C0 ?
	mov byte ptr modif+1, 0E8h	; ouii ==> transforme code machine : add en sub (= C0 ==> A8)
	jmp modif
LabelA8:	
	mov byte ptr modif+1, 0C0h

modif:
	add eax,11
	ret

DoSelf endp

Mysegment ends

end