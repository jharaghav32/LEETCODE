As we have to reach 0
first we mark all the edges as undirected
so that we can reach every  pair node if there is an road
now first we call for 0
and to reach zero we know that we should have all its neighbour nodes directed towards
zero then only that node reaches zero
we call for dfs for 0
and check if there is an edges from neighbour to zero if it is not
then increment the change because we have to change it to reach zero
now call for dfs for neighbour nodes
no again do same as now neighbour nodes has path to reach zero
we will traverse all its neighbours and check whther it reaches to that node because
if  it reaches that node and then obviously it reaches zero
so again do same proces as above till all nodes are mark visited
Implementation
First make the graph undirected
create a set which consist of pair {a,b} indicate that there is a edge from a to b
now call for dfs of src  node and if {src,neighbor} exist in set increment the change
as we want the node from neghboru to source to reach zero