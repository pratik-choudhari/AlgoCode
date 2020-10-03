function isValidCreditCard(creditCard) {
  return /(^[4-6])[0-9]{3}-?[0-9]{4}-?[0-9]{4}-?[0-9]{4}$/.test(creditCard);
}

console.log(isValidCreditCard("4253625879615786"));
console.log(isValidCreditCard("5122-2368-7954-3214"));
console.log(isValidCreditCard("42536258796157867"));
console.log(isValidCreditCard("44244x4424442444"));
