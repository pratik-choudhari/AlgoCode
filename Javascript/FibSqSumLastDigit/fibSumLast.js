var intInp = prompt("Input a number");

while (intInp.isNaN) {
	intInp = prompt("Input an integer only.");
}

function fibSumLast(N) {
	var resSum =0;
	var a = 0, b=1, c=0;
	for(i=1; i<=N; i++) {
		resSum += Math.pow(b,2);
		c = a + b;
		a = b;
		b = c;
	}
	return resSum%10;
}

alert(fibSumLast(intInp));