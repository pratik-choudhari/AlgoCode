const prompt = require('prompt');
  
prompt.start();
//the below line checks all the conditions except for consecutive numbers
var card = /^((^[4-6])[0-9]{3}-[0-9]{4}-[0-9]{4}-[0-9]{4})$|^((^[4-6])[0-9]{15})$/;

var counter = 0;
var x;
var y = '0';

prompt.get(['creditCardNumber'], function(error, result) {
    if (error) {
        return onError(error);
    } else if(result.creditCardNumber.match(card)) {
        //this if statement removes hyphens
        if(result.creditCardNumber.length === 19){
            result.creditCardNumber = result.creditCardNumber.replace(/-/g, "");
        }
        //converts the string to character array
        const array = [...result.creditCardNumber];
        if(consecutive(array)){
            console.log("Yes");
        }
        console.log("No");
    } else {
        console.log("No");
    }
    
});

//this function checks if there are repeated consecutive digits greater than or equal to 4
function consecutive(array){
    for (var i=0; i<array.length; i++){
        if(x === y) {
            counter++;
        } else {
            y = x;
            counter = 1;
        }
        if (counter >= 4){
            return false;
        }
    }
    return true;
}

// this function prints out the error is something unexpected happens
function onError(error) {
    console.log(error);
    return 1;
}