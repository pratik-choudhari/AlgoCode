:wave: Hello! I'm [Nimesha Dilini](https://github.com/EANimesha) <br><br>

<h1>Max Array Sum</h1>
<h2>Description</h2>

Given an array of integers, find the subset of non-adjacent elements with the maximum sum. Calculate the sum of that subset.
For example, given an array [-2,1,3,-4,5] we have the following possible subsets:

<table>
<tr><th>Subset</th><th>Sum</th></tr>
<tr><td>[-2, 3, 5]</td><td>6</td></tr>
<tr><td>[-2, 3]</td><td>1</td></tr>
<tr><td>[-2, -4]</td><td>-6</td></tr>
<tr><td>[-2, 5]</td><td>3</td></tr>
<tr><td>[1, -4]</td><td>-3</td></tr>
<tr><td>[1, 5]</td><td>6</td></tr>
<tr><td>[3, 5]</td><td>8</td></tr>
</table>

Our maximum subset-sum is 8.

<br>
<h2>Example</h2>

<h5>Input Format</h5>
The first line contains an integer, n.
The second line contains n space-separated integers arr[i].

<h5>Output Format</h5>
Return the maximum sum described in the statement.

<h5>Input</h5>
5
3 7 4 6 5

<h5>Output</h5>
13

<h5>Explanation</h5>
Our possible subsets are [3,4,5], [3,4], [3,6], [3,5], [7,5], [7,6] and [4,5]. The largest subset sum is 13 from subset [7,6]
