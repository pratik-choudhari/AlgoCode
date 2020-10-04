# IP Validator using RegEx

## Regular Expression

```
\b(?:\d{1,3}\.){3}\d{1,3}\b
```
- `\b`: Matches a word boundary position between a word character and non-word character or position (start/end of string).
- `\?`: Groups multiple tokens together without creating a capture group.
- `\d`: Matches any digit character (0-9). Equivalent to `[0-9]`.
- `{1,3}`: Matches the specified quantity of the previous token. `{1,3}` will match 1 to 3. `{3}` will match exactly 3. `{3,}` will match 3 or more.
- `\.`: Escapes the `.` character.

## Sample Input

```
6
000.12.12.034
121.234.12.12
23.45.12.56
00.12.123.123123.123
122.23
Hello.IP
```

## Sample Output

```
true
true
true
false
false
false
```

[Sudipto Ghosh](https://github.com/sudiptog81)
