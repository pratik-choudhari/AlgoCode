
function NumberFreq (aString) {
    var arr = new Array(10).fill(0);
    for (var i = 0; i < aString.length; i++) {
        if(aString.charAt(i) >= '0' && aString.charAt(i) <= '9'){
            arr[aString.charAt(i)] += 1;
        }
    }
    console.log(arr);
}

NumberFreq("a11472o5t6");
NumberFreq("a012452o5t9");
NumberFreq("a1231o54t9");
NumberFreq("0123456789");
NumberFreq("abcdefg");