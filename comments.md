# Media class:
It's supposed to be the class that processes the data based on the input selected. I'll write a main that works for it to make it easier to understand. I think it's way more efficient that typing all of it out. The media class processes the user input and spits out the sorted media the way the user specified it. It works with templated AVL tree class to sort data alphabetically. I'll change that AVL tree class to a heap and do it again for merge sort. Media class alredy splits our data points into the valid sets that just need to be sorted and printed.

# Comments on main:
The main can be done a lot more efficiently based on the files I created for the genre. I've also made the Media class work in a way that would make it efficient for us. It will have ultimately the same output, but it's easier to code. 

# Comments on  algorithms:
So far, the AVL tree works. However, since we can't use it, I'll create a templated heapSort() function that will sort the data using the heapsort algorithm. The second algorithm that we can use because of it's efficiency is merge sort. It should probably also be a templated function to sort our titles alphabetically.
