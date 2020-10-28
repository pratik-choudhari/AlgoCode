# Problem Statement
We are given a string ,the problem is to find out all the distinct possible permutations of the string. 

### Time Complexity
If we take the length of string to be N, then the complexity of the code will be O(N log N) \
for sorting and O( N * N! ) for the permutation. 
Total time complexity would be O(N log N + N * N!) which is effectively only O(N * N!).

### Samaple Input 
abca

### Sample Output 
aabc
aacb
abac
abca
acba
acab
baac
baca
bcaa
caba
caab
cbaa
Total distinct permutations = 12

##### Contributed by 
[Nishit Khaitan](https://github.com/Nishitk-20)
