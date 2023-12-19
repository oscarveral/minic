#!/bin/bash

fails=0

function memtest_lexer 
{
	test=test/$1

	error=$(valgrind -s --leak-check=full --show-leak-kinds=all ./miniC -l /dev/null $test 2>&1 | awk -F " " ' /^.*ERROR SUMMARY/{print $4}')

	errors=0

	for e in $error
	do
		if [ $e -ne 0 ]
		then
			errors=$(expr $errors + $e)
		fi
	done

	if [ $errors -ne 0 ]
	then
		fails=$(expr $fails + $errors)
		echo "The program has $errors leak(s) on lexer $test."
		return
	fi

	echo "No leaks on lexer $test."
	return
}

function memtest_syntax 
{
	test=test/$1

	error=$(valgrind -s --leak-check=full --show-leak-kinds=all ./miniC -s /dev/null -o /dev/null -w $test 2>&1 | awk -F " " ' /^.*ERROR SUMMARY/{print $4}')

	errors=0

	for e in $error
	do
		if [ $e -ne 0 ]
		then
			errors=$(expr $errors + $e)
		fi
	done

	if [ $errors -ne 0 ]
	then
		fails=$(expr $fails + $errors)
		echo "The program has $errors leak(s) on syntax $test."
		return
	fi

	echo "No leaks on syntax $test."
	return
}

function memtest_semantic 
{
	test=test/$1

	error=$(valgrind -s --leak-check=full --show-leak-kinds=all ./miniC -t /dev/null -o /dev/null -w $test 2>&1 | awk -F " " ' /^.*ERROR SUMMARY/{print $4}')

	errors=0

	for e in $error
	do
		if [ $e -ne 0 ]
		then
			errors=$(expr $errors + $e)
		fi
	done

	if [ $errors -ne 0 ]
	then
		fails=$(expr $fails + $errors)
		echo "The program has $errors leak(s) on semantic $test."
		return
	fi

	echo "No leaks on semantic $test."
	return
}

function memtest_codegen 
{
	test=test/$1

	error=$(valgrind -s --leak-check=full --show-leak-kinds=all ./miniC -o /dev/null -w $test 2>&1 | awk -F " " ' /^.*ERROR SUMMARY/{print $4}')

	errors=0

	for e in $error
	do
		if [ $e -ne 0 ]
		then
			errors=$(expr $errors + $e)
		fi
	done

	if [ $errors -ne 0 ]
	then
		fails=$(expr $fails + $errors)
		echo "The program has $errors leak(s) on code generation $test."
		return
	fi

	echo "No leaks on code generation $test."
	return
}

memtest_lexer test1.mc
memtest_lexer test2.mc
memtest_lexer test3.mc
memtest_lexer test4.mc
memtest_lexer test5.mc
memtest_lexer test6.mc
memtest_lexer test7.mc
memtest_lexer test8.mc
memtest_lexer test9.mc
memtest_lexer test10.mc
memtest_lexer test11.mc

memtest_syntax test7.mc
memtest_syntax test8.mc
memtest_syntax test9.mc
memtest_syntax test10.mc # Leaks por errores sintácticos.
memtest_syntax test11.mc

memtest_semantic test7.mc
memtest_semantic test8.mc
memtest_semantic test9.mc
memtest_semantic test10.mc # Genera leaks debido a la gestion de errores sintácticos.
memtest_semantic test11.mc

memtest_codegen test8.mc
memtest_codegen test9.mc
memtest_codegen test10.mc # Genera leaks debidos a la gestion de errores sintácticos.
memtest_codegen test11.mc

if [ $fails -ne 0 ];
then
	echo The miniC compiler has produced $fails leaks!
	exit 0
fi

echo "The compiler is not leaking memory. All good!"

exit 0