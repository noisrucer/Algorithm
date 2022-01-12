'''Example 1:

Input: s = "abc", t = "ahbgdc"
Output: true
Example 2:

Input: s = "axc", t = "ahbgdc"
Output: false

(Question)
Given two strings s and t, return true if s is a subsequence of t, or false otherwise.

A subsequence of a string is a new string that is formed from the original string by deleting some (can be none) 
of the characters without disturbing the relative positions of the remaining characters. (i.e., "ace" is a subsequence of "abcde" while "aec" is not).
'''
string s, t -> idx 

m = len(s)
n = len(t)
'''
1) 문제 재정의/일반화: s가 t의 subsequence 인가? (true/false)
   => s[0 ~ m-1]이 t[0 ~ n-1]의 subseuqnece인가를 구하여라
2) f(i,j) = s[0 ~ i]이 t[0 ~ j]의 subseuqnece인가

3-1) Base Case
1) i > j: false
2) i < 0: true
3) j < 0: false

3-2) General Case
f(i,j) = 
if s[i] == s[j]:
    f(i,j) = f(i-1,j-1)
else s[i] != s[j]:
    f(i,j) = f
------------------------
       i
s = 'abc'
            j  
t = 'affddbcz'   
------------------------
f(2,10): s의 index 0~2까지 가 t의 index 0~10까지의 subseuqnce인지를 구하여라
f(1,3): 'ab'가 'afff'의 subsequence인지를 구하여라


'''