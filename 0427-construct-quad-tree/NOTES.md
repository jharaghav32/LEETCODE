Here , for every grid we traverse recursively into topLeft,top right and.......
after that if we found that all subgrid leaft is true , it means as a parent all the
element of subgrid is equal  and if it has same value
so parent node is a node whose leaft node is true and value is equal to same value
​
​
If it is not
then that means in any subgrid the element are diffrent so
in this case call a recursive function for diffrent child
taking that child as parent node this process continue
​
​
and base case is if only single element exist
then that must be ndoe whose leaf is true and value is equal to that element