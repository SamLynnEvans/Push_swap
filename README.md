# Push_swap
Implementation of a non-recursive quick-sort algorithm to sort one stack by use of another stack.

The aim of push swap is to sort a stack of numbers using another stack in the least commands possible. The educational aim of the project was to introduce students to advanced sorting algorithms and the concept of complexity. This project earned maximum available marks for the algortihm's efficacy.

The stacks can be rotated, have their top two elements swapped, or be pushed onto each other, the full command list is as follows:

Rotating commands<br/>
RA - rotate stack A (send top number on stack to bottom)<br/>
RB - rotate stack B (send top number on stack to bottom)<br/>
RR - rotate both stack A and B at the same time<br/>
RRA - counter-rotate stack A (send bottom number of stack to top)<br/>
RRB - counter-rotate stack B (send bottom number of stack to top)<br/>
RRR - counter-rotate stack A and stack B at the same time<br/>
<br/>
Swapping commands<br/>
SA - swap top two numbers at top of stack A<br/>
SB - swap top two numbers at top of stack B<br/>
<br/>
Pushing commands<br/>
PA - push top element from stack A onto stack B<br/>
PB - push stack B<br/>

<b>How to run the program</b>

Push_swap usage:
./push_swap list_of_numbers_given_as_parameters

A list of numbers is entered as the parameters and these make up stack A (with the order of their input maintained), push_swap then prints the list of commands required to sort this stack.

To check the commands we use the checker, which could be called in this manner:

./push_swap number_list | ./checker number_list

The checker prints OK if the first stack is sorted and the second stack empty, and KO if anything else.

The full pdf for the project can be seen <a href="https://github.com/SamLynnEvans/Push_swap/blob/master/push_swap.pdf">here</a>.

<b>The algortihm</b>

While the aim of the project was to introduce students to complexity, the project did not actually favour algorithms with lowest complexity. Given that highest marks were achieved by using the least amount of commands, slower algorithms that read the data more times could be more precise than algortihms optimised for speed or least passes over the numbers. For this reason, computationally slower processes like finding the true median for each split in quick sort achieved better results.

In my implementation, I repeatedy split stack A around the true median, putting the lower numbers onto stack B, and maintaining the higher numbers in stack A. Partitions were recorded in stack B each time this process occurred as so: 

Start<br/>
stack A: 1 7 9 4 10 3 2 11 25  (median = 7)<br/>
Stack B:<br/>

First split:

stack A: 9 10 11 25 <br/>
Stack B: 2 3 4 7 1

Second split:

stack A: 25 11 10<br/>
stack B: 2 3 4 7 1 | 9<br/>
 
| = partition

Once Stack A was reduced to three or less numbers, it was sorted. Stack B would then find the median of the numbers up until the last partition in stack B, and push the higher values onto stack A until it reached the next partition in stack B. 

If three or less numbers were pushed back on to stack A, these numbers would be sorted using the swap and rotate commands, and a partition would be marked at the end of stack A too, signalling that stack A is sorted until this point. Stack B would then push onto A again as above.

If more than three numbers were pushed from B to A, stack A would then repeat the process at beginning, repeatedly splitting around a median of all the numbers after the last partition in A, maintaining the higher values and pushing the lower values onto B.

The whole above process would be repeated until stack A was sorted.

While many projects implemented a similar algortihm recursively, I employed a faster and less computationally expensive method by computing the problem iteratively. Two additional stacks kept a record of the position of the partitions, and allowed the algorithm to know when to stop pushing onto stack B or stack A, and from which point to calculate the medians. I based this implementation on an idea I read about here.

<b>Learnings</b>

1. I represented the stacks in two-way linked lists, and I had to develop a strong grasp of list manipulation to managed both the sorting stacks, and also the linked-list stacks I used to mark the partitions.

2. I learnt about complexity and (O)n notation.

3. I studied all major sorting algorithms in order to pick the one I felt best fit the task. It was very interesting to get my head around how they working recursively, and particularly enjoyable to then try and figure out how one could dissect the algorithm to perform it iteratively.
