# OperatingSystemLAB1
This program simulates the process through which the MBT manages what processes can be run and how it manages their free blocks.
The way that I implemented it, the PCBs are nodes and the Ready queue class is just the linked list class.
PCBs are connected to their respective tables through a pointer that is set using a setter upon instantiation.
From there as more process are added a singly linked list is generated in the Ready Queue with unique PID numbers that will allow them to be differentiated when selected for termination.
This program also prints the MBT in a grid to see which blocks are free or being used using 0s and 1s.
When a process is terminated I made sure to actually delete it from heap as well as flipping the blocks back from 1s to 0s.
No matter how many processes are added or deleted the Ready Queue is monitored using the head and tail pointers and from there the final option of ending can determine if processes are still active and ask the user if they would like to terminate all processes. 
