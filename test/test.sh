#!/bin/bash

fails=0

function test_lexer 
{
	result=$(mktemp test/tmp.XXXX)
	error=$(mktemp test/err.XXXX)
	test=test/$1
	expected_res=test/$2
	expected_err=test/$3

	./miniC -l $result -e $error $test >/dev/null 2>&1
	diferencias_res=$(diff -U 0 $result $expected_res | grep -v ^@ | wc -l)
   
	if [ $diferencias_res -ne 0 ]; 
	then
		fails=$(expr $fails + 1)
		echo Lexer test on $1 has fail! oops...
	fi

	diferencias_err=$(diff -U 0 $error $expected_err | grep -v ^@ | wc -l)

	if [ $diferencias_err -ne 0 ]; 
	then
		fails=$(expr $fails + 1)
		echo "Lexer test (errors) on $1 has fail! oops..."
	fi
 
	rm $result
	rm $error

	if [ $diferencias_err -eq 0 -a $diferencias_res -eq 0 ]
	then
		echo Lexer test on $1 passed.
		return
	fi
}

function test_syntax 
{
	result=$(mktemp test/tmp.XXXX)
	error=$(mktemp test/err.XXXX)
	test=test/$1
	expected_res=test/$2
	expected_err=test/$3

	./miniC -s $result -e $error -o /dev/null -w $test >/dev/null 2>&1
	diferencias_res=$(diff -U 0 $result $expected_res | grep -v ^@ | wc -l)
   
	if [ $diferencias_res -ne 0 ]; 
	then
		fails=$(expr $fails + 1)
		echo Syntax test on $1 has fail! oops...
	fi

	diferencias_err=$(diff -U 0 $error $expected_err | grep -v ^@ | wc -l)

	if [ $diferencias_err -ne 0 ]; 
	then
		fails=$(expr $fails + 1)
		echo "Syntax test (errors) on $1 has fail! oops..."
	fi
 
	rm $result
	rm $error

	if [ $diferencias_err -eq 0 -a $diferencias_res -eq 0 ]
	then
		echo Syntax test on $1 passed.
		return
	fi
}

function test_semantic 
{
	result=$(mktemp test/tmp.XXXX)
	error=$(mktemp test/err.XXXX)
	test=test/$1
	expected_res=test/$2
	expected_err=test/$3

	./miniC -t $result -e $error -o /dev/null -w $test >/dev/null 2>&1
	diferencias_res=$(diff -U 0 $result $expected_res | grep -v ^@ | wc -l)
   
	if [ $diferencias_res -ne 0 ]; 
	then
		fails=$(expr $fails + 1)
		echo Semantic test on $1 has fail! oops...
	fi

	diferencias_err=$(diff -U 0 $error $expected_err | grep -v ^@ | wc -l)

	if [ $diferencias_err -ne 0 ]; 
	then
		fails=$(expr $fails + 1)
		echo "Semantic test (errors) on $1 has fail! oops..."
	fi
 
	rm $result
	rm $error

	if [ $diferencias_err -eq 0 -a $diferencias_res -eq 0 ]
	then
		echo Semantic test on $1 passed.
		return
	fi
}

function test_codegen
{
	result=$(mktemp test/tmp.XXXX)
	error=$(mktemp test/err.XXXX)
	test=test/$1
	expected_res=test/$2
	expected_err=test/$3

	./miniC -e $error -o $result -w $test >/dev/null 2>&1
	diferencias_res=$(diff -U 0 $result $expected_res | grep -v ^@ | wc -l)
   
	if [ $diferencias_res -ne 0 ]; 
	then
		fails=$(expr $fails + 1)
		echo Code generation test on $1 has fail! oops...
	fi

	diferencias_err=$(diff -U 0 $error $expected_err | grep -v ^@ | wc -l)

	if [ $diferencias_err -ne 0 ]; 
	then
		fails=$(expr $fails + 1)
		echo "Code generation test (errors) on $1 has fail! oops..."
	fi
 
	rm $result
	rm $error

	if [ $diferencias_err -eq 0 -a $diferencias_res -eq 0 ]
	then
		echo Code generation test on $1 passed.
		return
	fi
}

test_lexer test1.mc test1.lexer test1.lexer_error # Basic tokens. 
test_lexer test2.mc test2.lexer test2.lexer_error # Comments
test_lexer test3.mc test3.lexer test3.lexer_error # Strings 1
test_lexer test4.mc test4.lexer test4.lexer_error # Strings 2
test_lexer test5.mc test5.lexer test5.lexer_error # Strings 3
test_lexer test6.mc test6.lexer test6.lexer_error # Unrecognized characters and other.
test_lexer test7.mc test7.lexer test7.lexer_error # Generic lexer test.
test_lexer test8.mc test8.lexer test8.lexer_error # Valid program lexer test.
test_lexer test9.mc test9.lexer test9.lexer_error # Invalid codegen program lexer test.
test_lexer test10.mc test10.lexer test10.lexer_error # Lexer test on program with syntax errors.
test_lexer test11.mc test11.lexer test11.lexer_error # Lexer test en programa de prueba de los profesores.

test_syntax test7.mc test7.syntax test7.syntax_error # Generic syntax test.
test_syntax test8.mc test8.syntax test8.syntax_error # Valid program syntax test.
test_syntax test9.mc test9.syntax test9.syntax_error # Invalid codegen program syntax test.
test_syntax test10.mc test10.syntax test10.syntax_error # Syntax test on program with syntax errors.
test_syntax test11.mc test11.syntax test11.syntax_error # Syntax test en programa de prueba de los profesores.

test_semantic test7.mc test7.semantic test7.semantic_error # General semantic test.
test_semantic test8.mc test8.semantic test8.semantic_error # Valid program semantic test.
test_semantic test9.mc test9.semantic test9.semantic_error # Invalid program semantic test.
test_semantic test10.mc test10.semantic test10.semantic_error # Semantic test on program with syntax errors both recoverable and not recoverable.
test_semantic test11.mc test11.semantic test11.semantic_error # Semantic test en programa de prueba de los profesores.

test_codegen test8.mc test8.codegen test8.codegen_error # Valid program output test.
test_codegen test9.mc test9.codegen test9.codegen_error # Invalid program output test.
test_codegen test10.mc test10.codegen test10.codegen_error # Generation test on program with syntax errors both recoverable and not recoverable.
test_codegen test11.mc test11.codegen test11.codegen_error # Generation test en programa de prueba de los profesores.


if [ $fails -ne 0 ];
then
	echo The miniC compiler has failed $fails tests!
	exit 0
fi

echo All test passed!

exit 0
