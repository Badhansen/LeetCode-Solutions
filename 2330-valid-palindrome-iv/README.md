<h2><a href="https://leetcode.com/problems/valid-palindrome-iv/">2330. Valid Palindrome IV</a></h2><h3>Medium</h3><hr><div><p>You are given a <strong>0-indexed</strong> string <code>s</code> consisting of only lowercase English letters. In one operation, you can change <strong>any</strong> character of <code>s</code> to any <strong>other</strong> character.</p>

<p>Return <code>true</code><em> if you can make </em><code>s</code><em> a palindrome after performing <strong>exactly</strong> one or two operations, or return </em><code>false</code><em> otherwise.</em></p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre><strong>Input:</strong> s = "abcdba"
<strong>Output:</strong> true
<strong>Explanation:</strong> One way to make s a palindrome using 1 operation is:
- Change s[2] to 'd'. Now, s = "abddba".
One operation could be performed to make s a palindrome so return true.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre><strong>Input:</strong> s = "aa"
<strong>Output:</strong> true
<strong>Explanation:</strong> One way to make s a palindrome using 2 operations is:
- Change s[0] to 'b'. Now, s = "ba".
- Change s[1] to 'b'. Now, s = "bb".
Two operations could be performed to make s a palindrome so return true.
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre><strong>Input:</strong> s = "abcdef"
<strong>Output:</strong> false
<strong>Explanation:</strong> It is not possible to make s a palindrome using one or two operations so return false.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 10<sup>5</sup></code></li>
	<li><code>s</code> consists only of lowercase English letters.</li>
</ul>
</div>