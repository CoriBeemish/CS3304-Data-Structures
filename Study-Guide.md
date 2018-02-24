# C++ Data Structures Study Guide
### From Spring 2017

**What is a copy constructor?** 
- (From book) A copy constructor is a constructor with exactly one argument, and the data type of the argument is the same as the constructor’s class. (p56) 

**Purpose of the copy constructor?** 
- To initialize a new object as an exact copy of an existing object (p56)

**Why is it necessary to have a copy constructor when the class uses dynamic memory?** 
- What will happen is that when you copy the object, you will have more than one instance pointing to the same dynamically allocated array. It isn't clear which instance should take care of de-allocating it upon destruction.
- If the class is supposed to own the array, then it will be in charge of de-allocating its resources. In this case, it should have a copy constructor and assignment operator that make a copy of the contents of the array, plus a destructor calling delete[] on it. This is known as the rule of three. In C++11, it should also have move copy and move assignment operators too.
- If the class doesn't own the array, it probably shouldn't construct it in the first place. It could receive a pointer to an externally allocated array via its constructor.
- (by [juanchopanza](https://stackoverflow.com/users/661519/juanchopanza), from stackoverflow, http://stackoverflow.com/questions/13303319/why-do-we-need-a-copy-constructor-when-an-array-is-allocated-memory-dynamically ) 

**Discuss the purpose of a template in C++ and how that purpose is accomplished.**
- Purpose-Allows functions and classes to operate with [generic types](https://en.wikipedia.org/wiki/Generic_programming). This allows a function or class to work on many different [data types](https://en.wikipedia.org/wiki/Data_type) without being rewritten for each one. ([Wiki](https://en.wikipedia.org/wiki/Template_%28C%2B%2B%29))

**How that purpose is accomplished:**
- The variable type is decided by the compiler at runtime.

**Discuss the differences between the data structures (specification) bag, sequence, and set.**
- Bag: can be implemented as a class, along with member functions to add, remove, and examine items. This is a data type that is capable of holding a collection of items (may need reviewing).
- Sequence: a particular order in which related events, movements, or things follow each other. Like a [set](https://en.wikipedia.org/wiki/Set_%28mathematics%29), it contains [members](https://en.wikipedia.org/wiki/Element_%28mathematics%29) (also called elements, or terms). The number of elements (possibly infinite) is called the length of the sequence. Unlike a set, order matters, and exactly the same elements can appear multiple times at different positions in the sequence. ([wiki](https://en.wikipedia.org/wiki/Sequence))
- Set: Elements are unique,  the set adds a number of operations that combine two sets to produce a new set. 
- Essentially, bag stores anything and has no order, Sequence stores anything with order, set stores anything unique but does not need to be ordered.

**Compare the strengths and weaknesses of using a list or an array to store a collection of objects. Be sure to include the efficiency of each the standard (insert, delete, etc.) operations.**
- Array:
  - Weakness: has a predetermined size. Static structure, meaning that more memory is used up than what might be used. 
  - Strength:  Random access, used to implement other data structures, (like graphs) 
- List:
  - Weakness: no random access, front/back access only.
  - Strength: dynamic size (increase/decrease size) 
- Big O comparison here ([wiki](https://en.wikipedia.org/wiki/Linked_list#Linked_lists_vs._dynamic_arrays))
  
**Big O**
- [Big O cheat sheet](http://bigocheatsheet.com/)  

## Sorting

**Selection Sort**
- Start by finding the smallest entry.
- Swap the smallest entry with the first entry.
- Find the smallest element in the unsorted side.
- Swap with the front of the unsorted side. 
- We have increased the size of the sorted side by one element. 
- The process keeps adding one more number to the sorted side.  
- The sorted side has the smallest numbers, arranged from small to large. 
- We can stop when the unsorted side has just one number, since that number must be the largest number. 
- The array is now sorted.  
- We repeatedly selected the smallest element, and moved this element to the front of the unsorted side.

**Insertion Sort** 
- The Insertion Sort algorithm also views the array as having a sorted side and an unsorted side.
- The sorted side starts with just the first element, which is not necessarily the smallest element.
- The sorted side grows by taking the front element from the unsorted side and inserting it in the place that keeps the sorted side arranged from small to large.
- In this example, the new element goes in front of the element that was already in the sorted side.
- Sometimes we are lucky and the new inserted item doesn't need to move at all.
- Sometimes we are lucky twice in a row.


**Selection & Insertion Sort Details**
- Both Selectionsort and Insertionsort have a worst-case time of O(n2), making them impractical for large arrays. 
- But they are easy to program, easy to debug.
- Insertionsort also has **good performance** when the array is **nearly sorted** to begin with.
- But more sophisticated sorting algorithms are *needed when good performance is needed in all cases* for large arrays.

**Quick Sort Details**
- Recursive quicksort (with average-time O(n log n))
- Quick sort Running Time The worst-case running time of quicksort is O(n2 ).
- But the average-case running time and the best-case running time for quicksort are both O(n log n).
- Obtaining a good running time requires the choice of a good pivot element.

**Quick sort and merge sort**
- Similarities
    - It is similar to mergesort in many ways.
    - It divides the elements to be sorted into two groups,
    - sorts the two groups by two recursive calls,
    - and combines the two sorted groups into a single array of sorted values.
- Differences
    - see efficiencies (more infomation needed)  
    - quicksort is significantly faster in practice than other Θ(nlogn) algorithms, because its inner loop can be efficiently implemented on most architectures, and in most real-world data, it is possible to make design choices which minimize the probability of requiring quadratic time. (by [Benoît](https://stackoverflow.com/users/31640/beno%C3%AEt) at [StackOverflow](https://stackoverflow.com/questions/680541/quick-sort-vs-merge-sort))
 
**Note:** 
  - Quicksort: best at primitive data types,
  - Merge sort: best at moving objects. 
 
**Merge Sort**
- The worst-case running time, the average-case running time, and the best-case running time for mergesort are all O(n log n).
- The mergesort algorithm divides the array near its midpoint, sorts the two half-arrays by recursive calls to the algorithm, and then merges the two halves to get a new sorted array of elements. (from book) 

## Graphs

**Robert Prim's Algorithm**
- A [greedy algorithm](https://en.wikipedia.org/wiki/Greedy_algorithm) that finds a [minimum spanning tree](https://en.wikipedia.org/wiki/Minimum_spanning_tree) for a [weighted](https://en.wikipedia.org/wiki/Glossary_of_graph_theory_terms#weighted_graph) [undirected graph](https://en.wikipedia.org/wiki/Graph_(discrete_mathematics)#Undirected_graph). This means it finds a subset of the [edges](https://en.wikipedia.org/wiki/Glossary_of_graph_theory_terms#edge) that forms a [tree](https://en.wikipedia.org/wiki/Tree_%28graph_theory%29) that includes every [vertex](https://en.wikipedia.org/wiki/Vertex_%28graph_theory%29), where the total weight of all the [edges](https://en.wikipedia.org/wiki/Graph_theory) in the tree is minimized. The algorithm operates by building this tree one vertex at a time, from an arbitrary starting vertex, at each step adding the cheapest possible connection from the tree to another vertex. ([wiki](https://en.wikipedia.org/wiki/Prim%27s_algorithm)) 
  1. Initialize a tree with a single vertex, chosen arbitrarily from the graph
  2. Grow the tree by one edge: of the edges that connect the tree to vertices not yet in the tree, find the minimum-weight edge, and transfer it to the tree.
  3. Repeat step 2 (until all vertices are in the tree).
  
**More [pseudocode](https://en.wikipedia.org/wiki/Pseudocode)** 

1. Associate with each vertex v of the graph a number C[v] (the cheapest cost of a connection to v) and an edge E[v] (the edge providing that cheapest connection). To initialize these values, set all values of C[v] to +∞ (or to any number larger than the maximum edge weight) and set each E[v] to a special flag value indicating that there is no edge connecting v to earlier vertices.
2. Initialize an empty forest F and a set Q of vertices that have not yet been included in F (initially, all vertices).
3. Repeat the following steps until Q is empty:
    1. Find and remove a vertex v from Q having the minimum possible value of C[v].
    2. Add v to F and, if E[v] is not the special flag value, also add E[v] to F.
    3. Loop over the edges vw connecting v to other vertices w. For each such edge, if w still belongs to Q and vw has smaller weight than C[w], perform the following steps:
        1. Set C[w] to the cost of edge vw.
        2. Set E[w] to point to edge vw.
4. Return F

**Edsger Wybe Dijkstra Algorithm**
- An [algorithm](https://en.wikipedia.org/wiki/Algorithm) for finding the [shortest paths](https://en.wikipedia.org/wiki/Shortest_path_problem) between [nodes](https://en.wikipedia.org/wiki/Vertex_%28graph_theory%29) in a [graph](https://en.wikipedia.org/wiki/Graph_%28abstract_data_type%29), which may represent, for example, road networks. ([Wiki](https://en.wikipedia.org/wiki/Dijkstra%27s_algorithm))
1. Assign to every node a tentative distance value: set it to zero for our initial node and to infinity for all other nodes.
2. Set the initial node as current. Mark all other nodes unvisited. Create a set of all the unvisited nodes called the unvisited set.
3. For the current node, consider all of its neighbors and calculate their tentative distances. Compare the newly calculated tentative distance to the current assigned value and assign the smaller one. For example, if the current node A is marked with a distance of 6, and the edge connecting it with a neighbor B has length 2, then the distance to B (through A) will be 6 + 2 = 8. If B was previously marked with a distance greater than 8 then change it to 8. Otherwise, keep the current value.
4. When we are done considering all of the neighbors of the current node, mark the current node as visited and remove it from the unvisited set. A visited node will never be checked again.
5. If the destination node has been marked visited (when planning a route between two specific nodes) or if the smallest tentative distance among the nodes in the unvisited set is infinity (when planning a complete traversal; occurs when there is no connection between the initial node and remaining unvisited nodes), then stop. The algorithm has finished.
6. Otherwise, select the unvisited node that is marked with the smallest tentative distance, set it as the new "current node", and go back to step 3. 

**Tree Visuals**
- https://www.cs.usfca.edu/~galles/visualization/flash.html
- At the bottom there is a drop down bar, with in that drop down is all the BST, B-tree, heap, and more. 

**Data Stucture Visuals**
- https://visualgo.net/en

**Additional Links**
- https://github.com/gibsjose/cpp-cheat-sheet/blob/master/Data%20Structures%20and%20Algorithms.md

Websites I have found useful to study Big O Notation:
https://rob-bell.net/2009/06/a-beginners-guide-to-big-o-notation/

