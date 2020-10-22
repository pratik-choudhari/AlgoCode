# Bit array  
  
Contributed by [Tom Kittel](https://github.com/kitteltom)  
  
The Java program calculates the number of distinct elements in an array `a` calculated using the following pseudo code:

```
a[0] = S (modulo 2^31)
for i = 1 to N-1
    a[i] = a[i-1]*P+Q (modulo 2^31)
 ```
 
## How to use

You can compile and run the script like this:

```bash
javac BitArray.java
java BitArray 3 1 1 1
```

The 4 arguments are integers `N`, `S`, `P` and `Q` as given in the pseudo code.
