void main() 
{
	var max;
	var cuenta, check;

	var comparado, comparador;
	var res = 0;

	const true = 1, false = 0;

	var a,b,c;

	var if_num = 0;
	var while_num = 0, n = 0, res_while = 1;

	var contador, iteraciones, pasos, otra_variable;

	print "Demostración de validez y composición de la precedencia de operaciones aritméticas\n";

	print "Introduce un valor: ";
	read max;

	check = ((!max) + (-(-(max))))*max/((-max)+(!(max)));
	cuenta = (!max + max)*max/-max+!max;

	print "La igualdad a continuación debe ser cierta: ", check, " = ", cuenta,".\n";

	print "\nDemostración de operadores relacionales y su composición.\nIntroduce un valor que comparar: ";
	read comparado;
	print "Introduce un valor con el que comparar: ";
	read comparador;

	if (comparado*comparado == comparador*comparador) res = 1;
	print comparado*comparado, " == ", comparador*comparador, " -> ", res, "\n";
	res = 0;
	if (comparado +- comparado != comparador +- comparador) res = 1;
	print comparado +- comparado, " != ", comparador +- comparador, " -> ", res, "\n";
	res = 0;
	if (comparado+comparado <= comparador+comparador) res = 1;
	print comparado+comparado, " <= ", comparador+comparador, " -> ", res, "\n";
	res = 0;
	if (comparado-comparado >= comparador-comparador) res = 1;
	print comparado-comparado, " >= ", comparador-comparador, " -> ", res, "\n";
	res = 0;
	if ((comparado<=comparado) < (comparador<=comparador)) res = 1;
	print comparado<=comparado, " <  ", comparador<=comparador, " -> ", res, "\n";
	res = 0;
	if (comparado>!comparado > comparador>!comparador) res = 1;
	print comparado>!comparado, " >  ", comparador>!comparador, " -> ", res, "\n";
	res = 0;

	print "\nDemostración de la negación lógica.\n";
	print "La constante true vale ",true, "\n";
	print "La constante false vale ",false, "\n";
	print "La expresion !true vale ",!true, "\n";
	print "La expresion !false vale ",!false, "\n";
	print "Cualquier número distinto de 0 se evalua a 0 y 0 se evalua a 1.\n";
	print "La variable comparador vale ", comparador, "\n";
	print "La expresion !comparador vale ", !comparador, "\n";
	print "La expresion !!comparador vale ", !!comparador, "\n";
	print "La variable comparado vale ", comparado, "\n";
	print "La expresion !comparado vale ", !comparado, "\n";
	print "La expresion !!comparado vale ", !!comparado, "\n";

	print "\nDemostración de la negación unaria.\n";
	print "La variable comparador vale ", comparador, "\n";
	print "La expresion -comparador vale ", -comparador, "\n";
	print "La expresion --comparador vale ", --comparador, "\n";
	print "La variable comparado vale ", comparado, "\n";
	print "La expresion -comparado vale ", -comparado, "\n";
	print "La expresion --comparado vale ", --comparado, "\n";

	print "\nDemostración de lectura múltiple.\n";
	print "Introduce 3 números:\n";
	read a,b,c;
	print "a = ",a,",\tb = ",b,",\tc = ",c,".\n";


	print "\nDemostración de la sentencia if.\n";
	print "Introduce un número, si es mayor que 0 se imprimirá su cuadrado, si es menor o igual que 0 se imprimirá su cubo: ";
	read if_num;

	if (if_num > 0)
		print "El cuadrado de ", if_num, " es ", if_num*if_num, ".\n";
	if (if_num <= 0)
		print "El cubo de ", if_num, " es ", if_num*if_num*if_num, ".\n";
	
	print "\nDemostración de la sentencia if-else.\n";
	print "Introduce un número, si es 0 se imprimirá su negación, si es distinto de 0 se imprimirá su cubo: ";
	read if_num;

	if (!if_num)
		print "La negación de ", if_num, " es ", !if_num, ".\n";
	else
		print "El cubo de ", if_num, " es ", if_num*if_num*if_num, ".\n";
	
	print "\nDemostración de la sentencia while.\n";
	print "Introduce un número para calcular la potencia enésima: ";
	read while_num;
	print "Introduce la potencia deseada: ";
	read n;

	if (n < 0)
		print "No se permiten potencias negativas!\n";
	else
	{
		if (n == 0)
			res_while = 1;
		else
		{
			cuenta = n;

			while (cuenta > 0)
			{	
				res_while = while_num * res_while;
				cuenta = cuenta - 1;
			}
		}

		print "El resultado es: ", res_while, ".\n";
	}

	print "\nDemostración de la sentencia do-while.\n";
	print "Introduce un número para calcular la potencia enésima: ";
	read while_num;
	print "Introduce la potencia deseada: ";
	read n;

	res_while = 1;
	if (n < 0)
		print "No se permiten potencias negativas!\n";
	else
	{
		if (n == 0)
			res_while = 1;
		else
		{
			cuenta = n;

			do
			{	
				res_while = while_num * res_while;
				cuenta = cuenta - 1;
			}
			while (cuenta > 0)
		}

		print "El resultado es: ", res_while, ".\n";
	}

	print "\nDemostración de la sentencia for normal.\n";
	print "Introduce la cantidad de iteraciones deseadas: ";
	read iteraciones;

	for (contador = 0; contador < iteraciones)
	{
		print "Iteración: ", contador,".\n";
	}

	print "\n";
	for (contador = 1; contador <= iteraciones)
	{
		print "Iteración: ", contador, ".\n";
	}

	// Véase que las condiciones de finalización tamnbién admiten expresiones que no usan la variable de iteración.
	print "\n";
	otra_variable = 1;
	for (contador = 1; otra_variable < iteraciones)
	{
		otra_variable = contador;
		print "Iteración: ", otra_variable, ".\n";

	}

	print "\nDemostración de la sentencia for extendida.\n";
	print "Introduce la cantidad de iteraciones deseadas: ";
	read iteraciones;
	print "Introduce los pasos de incremento: ";
	read pasos;

	for (contador = 1; contador <= iteraciones; pasos)
		print "Iteración: ", contador, ".\n";

	// Los pasos de incremento admiten cualquier tipo de expresion del lenguaje.
	print "\n";
	for (contador = 1; contador <= iteraciones; 1 + (contador <= iteraciones/2))
		print "Iteración: ", contador, ".\n";
}
