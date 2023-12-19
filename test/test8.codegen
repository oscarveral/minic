##################
# Seccion de datos
	.data

# Cadenas del programa
$str1:
	.asciiz "Demostración de validez y composición de la precedencia de operaciones aritméticas\n"
$str2:
	.asciiz "Introduce un valor: "
$str3:
	.asciiz "La igualdad a continuación debe ser cierta: "
$str4:
	.asciiz " = "
$str5:
	.asciiz ".\n"
$str6:
	.asciiz "\nDemostración de operadores relacionales y su composición.\nIntroduce un valor que comparar: "
$str7:
	.asciiz "Introduce un valor con el que comparar: "
$str8:
	.asciiz " == "
$str9:
	.asciiz " -> "
$str10:
	.asciiz "\n"
$str11:
	.asciiz " != "
$str12:
	.asciiz " <= "
$str13:
	.asciiz " >= "
$str14:
	.asciiz " <  "
$str15:
	.asciiz " >  "
$str16:
	.asciiz "\nDemostración de la negación lógica.\n"
$str17:
	.asciiz "La constante true vale "
$str18:
	.asciiz "La constante false vale "
$str19:
	.asciiz "La expresion !true vale "
$str20:
	.asciiz "La expresion !false vale "
$str21:
	.asciiz "Cualquier número distinto de 0 se evalua a 0 y 0 se evalua a 1.\n"
$str22:
	.asciiz "La variable comparador vale "
$str23:
	.asciiz "La expresion !comparador vale "
$str24:
	.asciiz "La expresion !!comparador vale "
$str25:
	.asciiz "La variable comparado vale "
$str26:
	.asciiz "La expresion !comparado vale "
$str27:
	.asciiz "La expresion !!comparado vale "
$str28:
	.asciiz "\nDemostración de la negación unaria.\n"
$str29:
	.asciiz "La expresion -comparador vale "
$str30:
	.asciiz "La expresion --comparador vale "
$str31:
	.asciiz "La expresion -comparado vale "
$str32:
	.asciiz "La expresion --comparado vale "
$str33:
	.asciiz "\nDemostración de lectura múltiple.\n"
$str34:
	.asciiz "Introduce 3 números:\n"
$str35:
	.asciiz "a = "
$str36:
	.asciiz ",\tb = "
$str37:
	.asciiz ",\tc = "
$str38:
	.asciiz "\nDemostración de la sentencia if.\n"
$str39:
	.asciiz "Introduce un número, si es mayor que 0 se imprimirá su cuadrado, si es menor o igual que 0 se imprimirá su cubo: "
$str40:
	.asciiz "El cuadrado de "
$str41:
	.asciiz " es "
$str42:
	.asciiz "El cubo de "
$str43:
	.asciiz "\nDemostración de la sentencia if-else.\n"
$str44:
	.asciiz "Introduce un número, si es 0 se imprimirá su negación, si es distinto de 0 se imprimirá su cubo: "
$str45:
	.asciiz "La negación de "
$str46:
	.asciiz "\nDemostración de la sentencia while.\n"
$str47:
	.asciiz "Introduce un número para calcular la potencia enésima: "
$str48:
	.asciiz "Introduce la potencia deseada: "
$str49:
	.asciiz "No se permiten potencias negativas!\n"
$str50:
	.asciiz "El resultado es: "
$str51:
	.asciiz "\nDemostración de la sentencia do-while.\n"
$str52:
	.asciiz "\nDemostración de la sentencia for normal.\n"
$str53:
	.asciiz "Introduce la cantidad de iteraciones deseadas: "
$str54:
	.asciiz "Iteración: "
$str55:
	.asciiz "\nDemostración de la sentencia for extendida.\n"
$str56:
	.asciiz "Introduce los pasos de incremento: "

# Variables y constantes
_max:
	.word 0
_cuenta:
	.word 0
_check:
	.word 0
_comparado:
	.word 0
_comparador:
	.word 0
_res:
	.word 0
_true:
	.word 0
_false:
	.word 0
_a:
	.word 0
_b:
	.word 0
_c:
	.word 0
_if_num:
	.word 0
_while_num:
	.word 0
_n:
	.word 0
_res_while:
	.word 0
_contador:
	.word 0
_iteraciones:
	.word 0
_pasos:
	.word 0
_otra_variable:
	.word 0

###################
# Seccion de codigo
	.text
	.globl main
main:

	li $t0,0
	sw $t0,_res
	li $t0,1
	sw $t0,_true
	li $t0,0
	sw $t0,_false
	li $t0,0
	sw $t0,_if_num
	li $t0,0
	sw $t0,_while_num
	li $t0,0
	sw $t0,_n
	li $t0,1
	sw $t0,_res_while
	li $v0,4
	la $a0,$str1
	syscall
	li $v0,4
	la $a0,$str2
	syscall
	li $v0,5
	syscall
	sw $v0,_max
	lw $t0,_max
	seq $t0,$t0,$zero
	lw $t1,_max
	neg $t1,$t1
	neg $t1,$t1
	add $t0,$t0,$t1
	lw $t1,_max
	mul $t0,$t0,$t1
	lw $t1,_max
	neg $t1,$t1
	lw $t2,_max
	seq $t2,$t2,$zero
	add $t1,$t1,$t2
	div $t0,$t0,$t1
	sw $t0,_check
	lw $t0,_max
	seq $t0,$t0,$zero
	lw $t1,_max
	add $t0,$t0,$t1
	lw $t1,_max
	mul $t0,$t0,$t1
	lw $t1,_max
	neg $t1,$t1
	div $t0,$t0,$t1
	lw $t1,_max
	seq $t1,$t1,$zero
	add $t0,$t0,$t1
	sw $t0,_cuenta
	li $v0,4
	la $a0,$str3
	syscall
	lw $t0,_check
	li $v0,1
	move $a0,$t0
	syscall
	li $v0,4
	la $a0,$str4
	syscall
	lw $t0,_cuenta
	li $v0,1
	move $a0,$t0
	syscall
	li $v0,4
	la $a0,$str5
	syscall
	li $v0,4
	la $a0,$str6
	syscall
	li $v0,5
	syscall
	sw $v0,_comparado
	li $v0,4
	la $a0,$str7
	syscall
	li $v0,5
	syscall
	sw $v0,_comparador
	lw $t0,_comparado
	lw $t1,_comparado
	mul $t0,$t0,$t1
	lw $t1,_comparador
	lw $t2,_comparador
	mul $t1,$t1,$t2
	seq $t0,$t0,$t1
	beqz $t0,$et0
	li $t1,1
	sw $t1,_res
$et0:
	lw $t0,_comparado
	lw $t1,_comparado
	mul $t0,$t0,$t1
	li $v0,1
	move $a0,$t0
	syscall
	li $v0,4
	la $a0,$str8
	syscall
	lw $t0,_comparador
	lw $t1,_comparador
	mul $t0,$t0,$t1
	li $v0,1
	move $a0,$t0
	syscall
	li $v0,4
	la $a0,$str9
	syscall
	lw $t0,_res
	li $v0,1
	move $a0,$t0
	syscall
	li $v0,4
	la $a0,$str10
	syscall
	li $t0,0
	sw $t0,_res
	lw $t0,_comparado
	lw $t1,_comparado
	neg $t1,$t1
	add $t0,$t0,$t1
	lw $t1,_comparador
	lw $t2,_comparador
	neg $t2,$t2
	add $t1,$t1,$t2
	sne $t0,$t0,$t1
	beqz $t0,$et1
	li $t1,1
	sw $t1,_res
$et1:
	lw $t0,_comparado
	lw $t1,_comparado
	neg $t1,$t1
	add $t0,$t0,$t1
	li $v0,1
	move $a0,$t0
	syscall
	li $v0,4
	la $a0,$str11
	syscall
	lw $t0,_comparador
	lw $t1,_comparador
	neg $t1,$t1
	add $t0,$t0,$t1
	li $v0,1
	move $a0,$t0
	syscall
	li $v0,4
	la $a0,$str9
	syscall
	lw $t0,_res
	li $v0,1
	move $a0,$t0
	syscall
	li $v0,4
	la $a0,$str10
	syscall
	li $t0,0
	sw $t0,_res
	lw $t0,_comparado
	lw $t1,_comparado
	add $t0,$t0,$t1
	lw $t1,_comparador
	lw $t2,_comparador
	add $t1,$t1,$t2
	sle $t0,$t0,$t1
	beqz $t0,$et2
	li $t1,1
	sw $t1,_res
$et2:
	lw $t0,_comparado
	lw $t1,_comparado
	add $t0,$t0,$t1
	li $v0,1
	move $a0,$t0
	syscall
	li $v0,4
	la $a0,$str12
	syscall
	lw $t0,_comparador
	lw $t1,_comparador
	add $t0,$t0,$t1
	li $v0,1
	move $a0,$t0
	syscall
	li $v0,4
	la $a0,$str9
	syscall
	lw $t0,_res
	li $v0,1
	move $a0,$t0
	syscall
	li $v0,4
	la $a0,$str10
	syscall
	li $t0,0
	sw $t0,_res
	lw $t0,_comparado
	lw $t1,_comparado
	sub $t0,$t0,$t1
	lw $t1,_comparador
	lw $t2,_comparador
	sub $t1,$t1,$t2
	sge $t0,$t0,$t1
	beqz $t0,$et3
	li $t1,1
	sw $t1,_res
$et3:
	lw $t0,_comparado
	lw $t1,_comparado
	sub $t0,$t0,$t1
	li $v0,1
	move $a0,$t0
	syscall
	li $v0,4
	la $a0,$str13
	syscall
	lw $t0,_comparador
	lw $t1,_comparador
	sub $t0,$t0,$t1
	li $v0,1
	move $a0,$t0
	syscall
	li $v0,4
	la $a0,$str9
	syscall
	lw $t0,_res
	li $v0,1
	move $a0,$t0
	syscall
	li $v0,4
	la $a0,$str10
	syscall
	li $t0,0
	sw $t0,_res
	lw $t0,_comparado
	lw $t1,_comparado
	sle $t0,$t0,$t1
	lw $t1,_comparador
	lw $t2,_comparador
	sle $t1,$t1,$t2
	slt $t0,$t0,$t1
	beqz $t0,$et4
	li $t1,1
	sw $t1,_res
$et4:
	lw $t0,_comparado
	lw $t1,_comparado
	sle $t0,$t0,$t1
	li $v0,1
	move $a0,$t0
	syscall
	li $v0,4
	la $a0,$str14
	syscall
	lw $t0,_comparador
	lw $t1,_comparador
	sle $t0,$t0,$t1
	li $v0,1
	move $a0,$t0
	syscall
	li $v0,4
	la $a0,$str9
	syscall
	lw $t0,_res
	li $v0,1
	move $a0,$t0
	syscall
	li $v0,4
	la $a0,$str10
	syscall
	li $t0,0
	sw $t0,_res
	lw $t0,_comparado
	lw $t1,_comparado
	seq $t1,$t1,$zero
	sgt $t0,$t0,$t1
	lw $t1,_comparador
	sgt $t0,$t0,$t1
	lw $t1,_comparador
	seq $t1,$t1,$zero
	sgt $t0,$t0,$t1
	beqz $t0,$et5
	li $t1,1
	sw $t1,_res
$et5:
	lw $t0,_comparado
	lw $t1,_comparado
	seq $t1,$t1,$zero
	sgt $t0,$t0,$t1
	li $v0,1
	move $a0,$t0
	syscall
	li $v0,4
	la $a0,$str15
	syscall
	lw $t0,_comparador
	lw $t1,_comparador
	seq $t1,$t1,$zero
	sgt $t0,$t0,$t1
	li $v0,1
	move $a0,$t0
	syscall
	li $v0,4
	la $a0,$str9
	syscall
	lw $t0,_res
	li $v0,1
	move $a0,$t0
	syscall
	li $v0,4
	la $a0,$str10
	syscall
	li $t0,0
	sw $t0,_res
	li $v0,4
	la $a0,$str16
	syscall
	li $v0,4
	la $a0,$str17
	syscall
	lw $t0,_true
	li $v0,1
	move $a0,$t0
	syscall
	li $v0,4
	la $a0,$str10
	syscall
	li $v0,4
	la $a0,$str18
	syscall
	lw $t0,_false
	li $v0,1
	move $a0,$t0
	syscall
	li $v0,4
	la $a0,$str10
	syscall
	li $v0,4
	la $a0,$str19
	syscall
	lw $t0,_true
	seq $t0,$t0,$zero
	li $v0,1
	move $a0,$t0
	syscall
	li $v0,4
	la $a0,$str10
	syscall
	li $v0,4
	la $a0,$str20
	syscall
	lw $t0,_false
	seq $t0,$t0,$zero
	li $v0,1
	move $a0,$t0
	syscall
	li $v0,4
	la $a0,$str10
	syscall
	li $v0,4
	la $a0,$str21
	syscall
	li $v0,4
	la $a0,$str22
	syscall
	lw $t0,_comparador
	li $v0,1
	move $a0,$t0
	syscall
	li $v0,4
	la $a0,$str10
	syscall
	li $v0,4
	la $a0,$str23
	syscall
	lw $t0,_comparador
	seq $t0,$t0,$zero
	li $v0,1
	move $a0,$t0
	syscall
	li $v0,4
	la $a0,$str10
	syscall
	li $v0,4
	la $a0,$str24
	syscall
	lw $t0,_comparador
	seq $t0,$t0,$zero
	seq $t0,$t0,$zero
	li $v0,1
	move $a0,$t0
	syscall
	li $v0,4
	la $a0,$str10
	syscall
	li $v0,4
	la $a0,$str25
	syscall
	lw $t0,_comparado
	li $v0,1
	move $a0,$t0
	syscall
	li $v0,4
	la $a0,$str10
	syscall
	li $v0,4
	la $a0,$str26
	syscall
	lw $t0,_comparado
	seq $t0,$t0,$zero
	li $v0,1
	move $a0,$t0
	syscall
	li $v0,4
	la $a0,$str10
	syscall
	li $v0,4
	la $a0,$str27
	syscall
	lw $t0,_comparado
	seq $t0,$t0,$zero
	seq $t0,$t0,$zero
	li $v0,1
	move $a0,$t0
	syscall
	li $v0,4
	la $a0,$str10
	syscall
	li $v0,4
	la $a0,$str28
	syscall
	li $v0,4
	la $a0,$str22
	syscall
	lw $t0,_comparador
	li $v0,1
	move $a0,$t0
	syscall
	li $v0,4
	la $a0,$str10
	syscall
	li $v0,4
	la $a0,$str29
	syscall
	lw $t0,_comparador
	neg $t0,$t0
	li $v0,1
	move $a0,$t0
	syscall
	li $v0,4
	la $a0,$str10
	syscall
	li $v0,4
	la $a0,$str30
	syscall
	lw $t0,_comparador
	neg $t0,$t0
	neg $t0,$t0
	li $v0,1
	move $a0,$t0
	syscall
	li $v0,4
	la $a0,$str10
	syscall
	li $v0,4
	la $a0,$str25
	syscall
	lw $t0,_comparado
	li $v0,1
	move $a0,$t0
	syscall
	li $v0,4
	la $a0,$str10
	syscall
	li $v0,4
	la $a0,$str31
	syscall
	lw $t0,_comparado
	neg $t0,$t0
	li $v0,1
	move $a0,$t0
	syscall
	li $v0,4
	la $a0,$str10
	syscall
	li $v0,4
	la $a0,$str32
	syscall
	lw $t0,_comparado
	neg $t0,$t0
	neg $t0,$t0
	li $v0,1
	move $a0,$t0
	syscall
	li $v0,4
	la $a0,$str10
	syscall
	li $v0,4
	la $a0,$str33
	syscall
	li $v0,4
	la $a0,$str34
	syscall
	li $v0,5
	syscall
	sw $v0,_a
	li $v0,5
	syscall
	sw $v0,_b
	li $v0,5
	syscall
	sw $v0,_c
	li $v0,4
	la $a0,$str35
	syscall
	lw $t0,_a
	li $v0,1
	move $a0,$t0
	syscall
	li $v0,4
	la $a0,$str36
	syscall
	lw $t0,_b
	li $v0,1
	move $a0,$t0
	syscall
	li $v0,4
	la $a0,$str37
	syscall
	lw $t0,_c
	li $v0,1
	move $a0,$t0
	syscall
	li $v0,4
	la $a0,$str5
	syscall
	li $v0,4
	la $a0,$str38
	syscall
	li $v0,4
	la $a0,$str39
	syscall
	li $v0,5
	syscall
	sw $v0,_if_num
	lw $t0,_if_num
	li $t1,0
	sgt $t0,$t0,$t1
	beqz $t0,$et6
	li $v0,4
	la $a0,$str40
	syscall
	lw $t1,_if_num
	li $v0,1
	move $a0,$t1
	syscall
	li $v0,4
	la $a0,$str41
	syscall
	lw $t1,_if_num
	lw $t2,_if_num
	mul $t1,$t1,$t2
	li $v0,1
	move $a0,$t1
	syscall
	li $v0,4
	la $a0,$str5
	syscall
$et6:
	lw $t0,_if_num
	li $t1,0
	sle $t0,$t0,$t1
	beqz $t0,$et7
	li $v0,4
	la $a0,$str42
	syscall
	lw $t1,_if_num
	li $v0,1
	move $a0,$t1
	syscall
	li $v0,4
	la $a0,$str41
	syscall
	lw $t1,_if_num
	lw $t2,_if_num
	mul $t1,$t1,$t2
	lw $t2,_if_num
	mul $t1,$t1,$t2
	li $v0,1
	move $a0,$t1
	syscall
	li $v0,4
	la $a0,$str5
	syscall
$et7:
	li $v0,4
	la $a0,$str43
	syscall
	li $v0,4
	la $a0,$str44
	syscall
	li $v0,5
	syscall
	sw $v0,_if_num
	lw $t0,_if_num
	seq $t0,$t0,$zero
	beqz $t0,$et8
	li $v0,4
	la $a0,$str45
	syscall
	lw $t1,_if_num
	li $v0,1
	move $a0,$t1
	syscall
	li $v0,4
	la $a0,$str41
	syscall
	lw $t1,_if_num
	seq $t1,$t1,$zero
	li $v0,1
	move $a0,$t1
	syscall
	li $v0,4
	la $a0,$str5
	syscall
	b $et9
$et8:
	li $v0,4
	la $a0,$str42
	syscall
	lw $t1,_if_num
	li $v0,1
	move $a0,$t1
	syscall
	li $v0,4
	la $a0,$str41
	syscall
	lw $t1,_if_num
	lw $t2,_if_num
	mul $t1,$t1,$t2
	lw $t2,_if_num
	mul $t1,$t1,$t2
	li $v0,1
	move $a0,$t1
	syscall
	li $v0,4
	la $a0,$str5
	syscall
$et9:
	li $v0,4
	la $a0,$str46
	syscall
	li $v0,4
	la $a0,$str47
	syscall
	li $v0,5
	syscall
	sw $v0,_while_num
	li $v0,4
	la $a0,$str48
	syscall
	li $v0,5
	syscall
	sw $v0,_n
	lw $t0,_n
	li $t1,0
	slt $t0,$t0,$t1
	beqz $t0,$et14
	li $v0,4
	la $a0,$str49
	syscall
	b $et15
$et14:
	lw $t1,_n
	li $t2,0
	seq $t1,$t1,$t2
	beqz $t1,$et12
	li $t2,1
	sw $t2,_res_while
	b $et13
$et12:
	lw $t2,_n
	sw $t2,_cuenta
$et10:
	lw $t2,_cuenta
	li $t3,0
	sgt $t2,$t2,$t3
	beqz $t2,$et11
	lw $t3,_while_num
	lw $t4,_res_while
	mul $t3,$t3,$t4
	sw $t3,_res_while
	lw $t3,_cuenta
	li $t4,1
	sub $t3,$t3,$t4
	sw $t3,_cuenta
	b $et10
$et11:
$et13:
	li $v0,4
	la $a0,$str50
	syscall
	lw $t1,_res_while
	li $v0,1
	move $a0,$t1
	syscall
	li $v0,4
	la $a0,$str5
	syscall
$et15:
	li $v0,4
	la $a0,$str51
	syscall
	li $v0,4
	la $a0,$str47
	syscall
	li $v0,5
	syscall
	sw $v0,_while_num
	li $v0,4
	la $a0,$str48
	syscall
	li $v0,5
	syscall
	sw $v0,_n
	li $t0,1
	sw $t0,_res_while
	lw $t0,_n
	li $t1,0
	slt $t0,$t0,$t1
	beqz $t0,$et19
	li $v0,4
	la $a0,$str49
	syscall
	b $et20
$et19:
	lw $t1,_n
	li $t2,0
	seq $t1,$t1,$t2
	beqz $t1,$et17
	li $t2,1
	sw $t2,_res_while
	b $et18
$et17:
	lw $t2,_n
	sw $t2,_cuenta
$et16:
	lw $t2,_while_num
	lw $t3,_res_while
	mul $t2,$t2,$t3
	sw $t2,_res_while
	lw $t2,_cuenta
	li $t3,1
	sub $t2,$t2,$t3
	sw $t2,_cuenta
	lw $t2,_cuenta
	li $t3,0
	sgt $t2,$t2,$t3
	bnez $t2,$et16
$et18:
	li $v0,4
	la $a0,$str50
	syscall
	lw $t1,_res_while
	li $v0,1
	move $a0,$t1
	syscall
	li $v0,4
	la $a0,$str5
	syscall
$et20:
	li $v0,4
	la $a0,$str52
	syscall
	li $v0,4
	la $a0,$str53
	syscall
	li $v0,5
	syscall
	sw $v0,_iteraciones
	li $t0,0
	sw $t0,_contador
	b $et21
$et22:
	li $v0,4
	la $a0,$str54
	syscall
	lw $t2,_contador
	li $v0,1
	move $a0,$t2
	syscall
	li $v0,4
	la $a0,$str5
	syscall
	lw $t2,_contador
	addi $t2,$t2,1
	sw $t2,_contador
$et21:
	lw $t1,_contador
	lw $t2,_iteraciones
	slt $t1,$t1,$t2
	bnez $t1,$et22
	li $v0,4
	la $a0,$str10
	syscall
	li $t0,1
	sw $t0,_contador
	b $et23
$et24:
	li $v0,4
	la $a0,$str54
	syscall
	lw $t2,_contador
	li $v0,1
	move $a0,$t2
	syscall
	li $v0,4
	la $a0,$str5
	syscall
	lw $t2,_contador
	addi $t2,$t2,1
	sw $t2,_contador
$et23:
	lw $t1,_contador
	lw $t2,_iteraciones
	sle $t1,$t1,$t2
	bnez $t1,$et24
	li $v0,4
	la $a0,$str10
	syscall
	li $t0,1
	sw $t0,_otra_variable
	li $t0,1
	sw $t0,_contador
	b $et25
$et26:
	lw $t2,_contador
	sw $t2,_otra_variable
	li $v0,4
	la $a0,$str54
	syscall
	lw $t2,_otra_variable
	li $v0,1
	move $a0,$t2
	syscall
	li $v0,4
	la $a0,$str5
	syscall
	lw $t2,_contador
	addi $t2,$t2,1
	sw $t2,_contador
$et25:
	lw $t1,_otra_variable
	lw $t2,_iteraciones
	slt $t1,$t1,$t2
	bnez $t1,$et26
	li $v0,4
	la $a0,$str55
	syscall
	li $v0,4
	la $a0,$str53
	syscall
	li $v0,5
	syscall
	sw $v0,_iteraciones
	li $v0,4
	la $a0,$str56
	syscall
	li $v0,5
	syscall
	sw $v0,_pasos
	li $t0,1
	sw $t0,_contador
	b $et27
$et28:
	li $v0,4
	la $a0,$str54
	syscall
	lw $t3,_contador
	li $v0,1
	move $a0,$t3
	syscall
	li $v0,4
	la $a0,$str5
	syscall
	lw $t2,_pasos
	lw $t3,_contador
	add $t3,$t3,$t2
	sw $t3,_contador
$et27:
	lw $t1,_contador
	lw $t2,_iteraciones
	sle $t1,$t1,$t2
	bnez $t1,$et28
	li $v0,4
	la $a0,$str10
	syscall
	li $t0,1
	sw $t0,_contador
	b $et29
$et30:
	li $v0,4
	la $a0,$str54
	syscall
	lw $t4,_contador
	li $v0,1
	move $a0,$t4
	syscall
	li $v0,4
	la $a0,$str5
	syscall
	li $t2,1
	lw $t4,_contador
	lw $t5,_iteraciones
	li $t6,2
	div $t5,$t5,$t6
	sle $t4,$t4,$t5
	add $t2,$t2,$t4
	lw $t4,_contador
	add $t4,$t4,$t2
	sw $t4,_contador
$et29:
	lw $t1,_contador
	lw $t2,_iteraciones
	sle $t1,$t1,$t2
	bnez $t1,$et30

###################
# Fin
	li $v0,10
	syscall
