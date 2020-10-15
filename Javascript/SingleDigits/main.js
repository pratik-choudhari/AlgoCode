
number = Number(process.argv[2])

dict = {}

while (number > 0) {
    digit = number % 10;
    if (dict.hasOwnProperty(digit.toString())) {
        dict[digit] = dict[digit] + 1;
    } else {
        dict[digit] = 1;
    }
    number = Math.floor(number / 10);
}
let result = 0;
for (let key in dict) {
    if (dict[key] == 1) {
        result += 1;
    }
}

console.log(result);