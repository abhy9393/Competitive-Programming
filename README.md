/*
=========================================================
Problem : Equal Elements
Platform : CodeChef
Difficulty : 1738

Approach :
- Greedy + Map
- Traverse from right to left.

Observation :
- Left se future decisions lene padte hain.
- Right se last pair ko fix kar sakte hain.
- Map current segment ke pending elements store karta hai.
- Pair milte hi ans += 2 aur mp.clear().
- mp.clear() ka matlab current segment khatam.

Why this works :
- Last pair fix ho jaane ke baad us segment ke andar ke pending
  elements future answer improve nahi kar sakte.

Time Complexity :
- O(N log N)

Space Complexity :
- O(N)

Mistakes / Learning :
- Frequency alone is not sufficient.
- Reverse traversal made the greedy obvious.
=========================================================
*/
