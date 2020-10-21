const prompt = require('prompt');

const properties = [
    {
        name: 'firstInteger',
        validator: /[\d]/,
        warning: 'Input should only be an integer'
    },
    {
        name: 'secondInteger',
        validator: /[\d]/,
        warning: 'Input should only be an integer'
    },
    {
        name: 'operator',
        validator: /[+\-\*\/\%]/,
        warning: 'Operator should be either of these: +,-,*,/,%'
    }
];

prompt.start();

prompt.get(properties, function (error, result) {
    if (error) {
        return onError(error);
    }
    console.log("Commandline inputs received");
    console.log("First input: " + result.firstInteger);
    console.log("Second input: " + result.secondInteger);
    console.log("Operator: " + result.operator);
    console.log("Answer is");
    if (result.operator === '+') {
        return console.log(result.firstInteger + " + " + result.secondInteger + " = " + (parseInt(result.firstInteger) + parseInt(result.secondInteger)));
    } else if (result.operator === '-') {
        return console.log(result.firstInteger + " - " + result.secondInteger + " = " + (parseInt(result.firstInteger) - parseInt(result.secondInteger)));
    } else if (result.operator === '*') {
        return console.log(result.firstInteger + " * " + result.secondInteger + " = " + parseInt(result.firstInteger) * parseInt(result.secondInteger));
    } else if (result.operator === '/') {
        return console.log(result.firstInteger + " / " + result.secondInteger + " = " + parseInt(result.firstInteger) / parseInt(result.secondInteger));
    } else if (result.operator === '%') {
        return console.log(result.firstInteger + " % " + result.secondInteger + " = " + parseInt(result.firstInteger) % parseInt(result.secondInteger));
    } else {
        console.log("Something went wrong, cannot compute answer");
    }
});

function onError(error) {
    console.log(error);
    return 1;
}
