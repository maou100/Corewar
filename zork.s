.name "zork"
.comment "I'M ALIIIIVE"



ldi		%25, %42, r8
and		%42, %255, r4
st		r4, 200
aff		r4
st		r8, 2000
st		r4, 200
st		r4, 200
st		r4, 200
st		r4, 200
st		r4, 200
st		r4, 200
st		r4, 200
st		r4, 200
st		r4, 200
live	%4
zjmp	%4
