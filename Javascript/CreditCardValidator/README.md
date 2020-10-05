## Credit card validator

This is a simple credit card validator with these checks:
► It must start with a 4, 5 or 6.
► It must contain exactly 16 digits.
► It must only consist of digits (0-9).
► It may have digits in groups of 4, separated by one hyphen "-".
► It must NOT use any other separator like ' ' , '_', etc.
► It must NOT have 4 or more consecutive repeated digits.

### Installation
```sh
~ $ cd Javascript/CreditCardValidator
~ $ npm install
~ $ node index.js
```

### Usage:
```sh
~ $ node index.js
prompt: creditCardNumber:  4253625879615786
Yes
```

```sh
~ $ node index.js
prompt: creditCardNumber:  5122-2368-7954-3214
Yes
```

```sh
~ $ node index.js
prompt: creditCardNumber:  42536258796157867
No
```

```sh
~ $ node index.js
prompt: creditCardNumber:  44244x4424442444
No
```

### Contributor
[comrade-om](https://github.com/comrade-om)