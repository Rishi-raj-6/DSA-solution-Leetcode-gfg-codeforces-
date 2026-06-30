# Max sum subarray by removing at most one element

## Difficulty: Medium

## Platform: GeeksForGeeks

## Problem Link
[View Problem](https://www.geeksforgeeks.org/problems/max-sum-subarray-by-removing-at-most-one-element/1)

## Solved On
01 Jul 2026 at 12:17 am

<h2><a href="https://www.geeksforgeeks.org/problems/max-sum-subarray-by-removing-at-most-one-element/1">Max sum subarray by removing at most one element</a></h2><h3>Difficulty Level: Medium</h3><hr><p><span style="font-size: 14pt;">Given an array&nbsp;<strong>arr[],</strong> find the <strong>maximum sum</strong> of a non-empty subarray. You are allowed to skip&nbsp;<strong data-start="112" data-end="135">at most one element</strong>&nbsp;in the subarray.</span></p>
<p><span style="font-size: 18px;"><strong>Note:</strong>&nbsp;</span><span style="font-size: 14pt;">After skipping the element, the subarray must still be <strong data-start="210" data-end="223">non-empty</strong>.</span></p>
<p><span style="font-size: 18px;"><strong>Examples:</strong></span></p>
<pre><span style="font-size: 18px;"><strong>Input: </strong>arr[] = [1, 2, 3, -4, 5]
<strong>Output: </strong>11<strong>
Explanation: </strong>We can get maximum sum subarray by skipping -4.</span></pre>
<pre><span style="font-size: 18px;"><strong>Input: </strong>arr[] = [-2, -3, 4, -1, -2, 1, 5, -3]
<strong>Output: </strong>9<strong>
Explanation: </strong>We can get maximum sum subarray by skipping -2 as [4,-1,1,5] sums to 9, which is the maximum achievable sum.</span></pre>
<p><span style="font-size: 18px;"><strong>Constraints:</strong><br>1&nbsp;<span style="color: #273239; font-family: Nunito; font-size: 17px; background-color: #ffffff;">≤</span>&nbsp;arr.size()&nbsp;<span style="color: #273239; font-family: Nunito; font-size: 17px; background-color: #ffffff;">≤</span>&nbsp;10<sup>6</sup><br>-10<sup>3</sup>&nbsp;<span style="color: #273239; font-family: Nunito; font-size: 17px; background-color: #ffffff;">≤</span>&nbsp;arr[i]&nbsp;<span style="color: #273239; font-family: Nunito; font-size: 17px; background-color: #ffffff;">≤</span>&nbsp;10<sup>3</sup></span></p>