[Matthew Brown](https://github.com/everspy)

# Problem

In a party of N people, only one person is known to everyone. Such a person may be present in the party, if yes, (s)he doesn’t know anyone in the party. We can only ask questions like “does A know B? “. Find the stranger (celebrity) in the minimum number of questions.

We can describe the problem input as an array of numbers/characters representing persons in the party. We also have a hypothetical function HaveAcquaintance(A, B) which returns true if A knows B, false otherwise. How can we solve the problem.

# Example Input

[[ 0 0 1 0]
 [ 0 0 1 0]
 [ 0 0 0 0]
 [ 0 0 1 0]]

Output: "id = 2"

The person in index 2 is known by everybody, but knows nobody. So id 2 is the celebrity


[[ 0 0 1 0]
 [ 0 0 1 0]
 [ 1 0 0 0]
 [ 0 0 1 0]]

Output: No celebrity

Now, the celebrity knows one person (id 0) so id 2 can no longer be a celebrity
