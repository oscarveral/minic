void main () {

	// Declaraciones estandar de variables.

	var a1;
	var a2 = 2;
	var b1, b2, b3, b4;
	var c1 = 1, c2 = 2, c3 = 3, c4 = 4;
	var d1 = 1, d2, d3 = 3, d4;

	// Declaraciones estandar de constantes.

	const e1;
	const e2 = 2;
	const f1, f2, f3, f4;
	const g1 = 1, g2 = 2, g3 = 3, g4 = 4;
	const h1 = 1, h2, h3 = 3, h4;

	// Comporbación de dobles declaraciones.

	var a;
	var a;

	var b;
	const b;

	const c;
	const c;

	const d;
	var d;

	// Comporbación de dobles inicializaciones.

	var e = 1;
	var e = 2;

	var f = 1;
	const f = 2;

	const g = 1;
	const g = 2;

	const h = 1;
	var h = 2;

	// Comporbación de mezcla de declaraciones e inicializaciones dobles.

	var i;
	var i = 1;
	const i = 2;

	const j;
	var j = 1;
	const j = 2;

	var k = 1;
	var k;
	const k;

	const l = 1;
	var l;
	const l;

	// Comprobación de asignación.

	var variable = 0;
	const constante = 0;

	variable = 1 + 2;
	variable = a + b;

	// Asignación a variable no declarada.

	inexistente = 1 + 2;

	// Asignación a constante.

	constante = 1 + 2;

	// Uso de símbolos inexistentes.

	variable = variable + inexistente;
	constante = constante + inexistente;

	// Otros.

	variable = a + b - c * d / g <= -a + !b - (!inexistente);

	// Lectura de variables.
	read a, b;
	
	// Lectura de constantes.
	read c, d;

	// Lectura de inexistentes.
	read inexistente;

	// Impresión de variables y constantes.
	print a, b, c, d;

	// Impresión de inexistentes.
	print a, b, c, inexistente;

	// Impresión de cadenas de texto.
	print "Cadena1", "Cadena2";


// Impresión de cadenas multilínea.

print "Cadena\
3";

print "Cadena\
3\
3";

	// Impresión mezclada.
	print "Primera parte: ", a, b, ". Segunda parte: ", c , d, ". Tercera parte: ", inexistente, ".";

	// Comprobación de que la duplicidad de cadenas de texto no duplica entradas en la tabla de símbolos.
	print "Cadena que no se debe duplicar.";
	print "Cadena que no se debe duplicar.";
	print "Cadena que no se debe duplicar 2.", "Cadena que no se debe duplicar 2.";

}