https://www.youtube.com/watch?v=4kFgfAv4ESY
​
example array hai 3 7 1 6
to actual mai jitna bhi increase decrease kre sum of element same rhega thik
3    7     1    6
3    7      2    5
3    8      1    5
4    7     1     5
we cna't decrease first element
now what we saw is in second step 6 decreases and 1 increase
in third step 2 decrease and 7 increase
and further 8 decrease 3 increase
we saw on decreasing the element 6 by 1 we can increase any element left to it
similarily  because in last step we saw 1 and 7 reamins same we increase 3
so we can increase anyone element left to it
so what we do is we know our value is in the range of minof array to max of array
we take an optimal value
and compare it from start if value is less than optimal then we try to equla to optimal
so we increase it value by optimal-value and add it to extra
similiary if it is greater than optimal then we have to remove it the val-optimal
so decrease extra to optimal
because we can decrease and only and if we have increased any other element
so in case extra is less than value we want to decrease it and here return false it means the given value is not optimal and optimal value is higher than this
if all element satisfied condition and return true put it into answer
and then check for lower value
time complexity is O(nlogn)
​