    var intInp = prompt("Input 4 comma-seperated integers...");
		var inpArr = intInp.split(",");
		
		while (inpArr.some(isNaN) || inpArr.length != 4) {
			intInp = prompt("Input 4 integers only. No Strings. Comma-seperated. Ex: 3,1,1,1");
			inpArr = intInp.split(",");
		}

		function calcEle(N,S,P,Q) {
			var res;
			var a = [];
			a[0] = S % Math.pow(2,31);
			for(i=1; i<N; i++) {
				a[i] = a[i-1]*P+(Q % Math.pow(2,31));
				res = a[i];
			}
			return res;
		}
		
		alert(calcEle(...inpArr));
