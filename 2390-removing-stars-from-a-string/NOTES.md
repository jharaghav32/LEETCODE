First Approach
create a new string
traverse from left if it character add it to string
and else if it is star remove the last character that is leftmost character according
to star
after than return the newstring
​
TC-O(n)  SC-O(n)
​
Second Approach
using two pointer
we traverse from left and we have one another pointer j initially points to 0;
case 1: if char is nonstar
then replace the char at i (that is current position) to j pointer
case2: if it is star
that means we have to remove character so instead of removing we decrement our j pointer and if next time nonstar appears then there is that nonstar char so automatically we remove so
here we performing the operation in string given so no extra space required
at the end return the string from 0 to j