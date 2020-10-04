# Credit card validator
Checks if credit card number is valid by given parameters:
► It must start with a 4, 5 or 6.
► It must contain exactly 16 digits.
► It must only consist of digits (0-9).
► It may have digits in groups of 4, separated by one hyphen "-".
► It must NOT use any other separator like ' ' , '_', etc.
► It must NOT have 4 or more consecutive repeated digits.
## Examples
```Input your card number: 5123847512398432
Valid
```
```
Input your card number: 6213-9540-8576-2313
Valid
```
```
Input your card number: 3512322254445231
Invalid
```
```
Input your card number: 5432-4311-1123-5432
Invalid
```
```
Input your card number: 4321-5432-6543_1234
Invalid
```

[XoMute] (https://github.com/XoMute)
