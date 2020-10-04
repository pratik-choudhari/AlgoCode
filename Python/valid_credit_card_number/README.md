# validCreditCardNumber
Checks if credit card number is valid by the parameters:\
► It must start with a 4, 5 or 6.\
► It must contain exactly 16 digits.\
► It must only consist of digits (0-9).\
► It may have digits in groups of 4, separated by one hyphen "-".\
► It must NOT use any other separator like ' ' , '_', etc.\
► It must NOT have 4 or more consecutive repeated digits.\
## Examples
```
Input: 4253625879615786
Output: Yes
```
```
Input: 5122-2368-7954-3214
Output: Yes
```
```
Input: 42536258796157867
Output: No
```
```
Input: 44244x4424442444
Output: No
```
## Contributor

[Diegoslourenco](https://github.com/Diegoslourenco)
