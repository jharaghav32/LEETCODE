First Approach:
run a two loop and for compare the each element with other element and it is found to equal to any of
element then return that element
​
Time Complexity -- O(n2)
Space  Complexity---O(1)
​
Second Approach:
sort the array and check if any two consecutive element are equal then return that element
​
TC--O(nlogn)
SC--O(1)
​
Third Approach:
use unordered map and store the element if any element is found which has been already present in map
it means it is repeated number so return that element
TC--O(n)
SC-O(n)
​
Forth Approach : Flyod Algorithm
Here two equal element poiniting to same position and other  element completes the cycle which helps
us to apply above algorithm one thing to notes cycle alwyas start from that reapeating element
0  1 2 3 4
1  3 4 2 2                                 |------|