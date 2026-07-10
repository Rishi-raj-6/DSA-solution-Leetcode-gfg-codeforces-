# Longest Possible Route in a Matrix with Hurdles

## Difficulty: Medium

## Platform: GeeksForGeeks

## Problem Link
[View Problem](https://www.geeksforgeeks.org/problems/longest-possible-route-in-a-matrix-with-hurdles/1)

## Solved On
11 Jul 2026 at 02:07 am

<h2><a href="https://www.geeksforgeeks.org/problems/longest-possible-route-in-a-matrix-with-hurdles/1">Longest Possible Route in a Matrix with Hurdles</a></h2><h3>Difficulty Level: Medium</h3><hr><p><span style="font-size: 14pt;">Given a binary matrix <strong>mat[][]</strong> of size<strong> n × m</strong> containing values 0 and 1, and four integers <strong>xs</strong>, <strong>ys</strong>, <strong>xd</strong>, and <strong>yd</strong> representing the source cell (xs, ys) and destination cell (xd, yd), find the length of the longest possible path from the source cell to the destination cell. From any cell, you can move to its adjacent cells in the up, down, left, and right directions.</span></p>
<ul>
<li><span style="font-size: 14pt;">1 represents a traversable cell.</span></li>
<li><span style="font-size: 18.6667px;">0 represents a blocked cell that cannot be visited.</span></li>
<li><span style="font-size: 14pt;">A cell can be visited at most once in a path.</span></li>
<li><span style="font-size: 14pt;">If the destination cannot be reached from the source, return -1.</span></li>
</ul>
<p><strong><span style="font-size: 18px;">Examples:</span></strong></p>
<pre><strong><span style="font-size: 18px;">Input: </span></strong><span style="font-size: 18px;">mat[][] = [[1, 1, 1, 1, 1, 1, 1, 1, 1, 1], [1, 1, 0, 1, 1, 0, 1, 1, 0, 1],[1, 1, 1, 1, 1, 1, 1, 1, 1, 1]], xs = 0, ys = 0, xd = 1, yd = 7</span>
<strong><span style="font-size: 18px;">Output: </span></strong><span style="font-size: 18px;">24 </span>
<strong><span style="font-size: 18px;">Explanation: </span></strong><span style="font-size: 18px;">The longest valid path from (0, 0) to (1, 7) without revisiting any cell has length 24.</span> <br><img src="https://media.geeksforgeeks.org/img-practice/prod/addEditProblem/930022/Web/Other/blobid1_1782119611.png" width="496" height="124"></pre>
<pre><strong><span style="font-size: 18px;">Input: </span></strong><span style="font-size: 18px;">mat[][] = [[1, 0, 0, 1, 0],[0, 0, 0, 1, 0],[0, 1, 1, 0, 0]], xs = 0, ys = 3, xd = 2, yd = 2</span>
<strong><span style="font-size: 18px;">Output: </span></strong><span style="font-size: 18px;">-1</span>
<strong><span style="font-size: 18px;">Explanation: </span></strong><span style="font-size: 18px;">The destination cell (2, 2) cannot be reached from the source cell (0, 3), so the answer is -1.<br></span><img src="https://media.geeksforgeeks.org/img-practice/prod/addEditProblem/930022/Web/Other/blobid2_1782119632.png" width="314" height="122"> </pre>
<p><span style="font-size: 18px;"><strong>Constraints:<br></strong></span><span style="font-size: 18px;">1 ≤ n, m ≤ 10<br></span><span style="font-size: 18px;">mat[i][j] == 0 or mat[i][j] == 1<br></span><span style="font-size: 18px;">The source and destination cells are always inside the matrix.</span></p>