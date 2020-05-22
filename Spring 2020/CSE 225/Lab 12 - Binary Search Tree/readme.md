### Problem description

- Given a sequence of integers, determine the best ordering of
  the integers to insert them into a binary search tree. The best
  order is the one that will allow the binary search tree to have
  the minimum height.
  
  Input starts with and integer n and the next n integers will be the values to be inserted in a binary search tree.  
  Your program should print the numbers in the proper sequence in a single line separated by a single whitespace.  
  
  Hint: Sort the sequence (use the inorder traversal) and put it in an array.
  The middle element is the root. Similar way the middle element among the rest of the elements on the left is the root
  of the left subtree and the middle element among the rest of the elements on the right of the array is the root of the
  right subtree. Recursively print all of them.
  
    - Sample input:  
        10  
        11 9 4 2 7 3 17 0 5 1  
    - Sample output:  
        4 1 0 2 3 9 5 7 11 17