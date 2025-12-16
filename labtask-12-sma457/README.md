[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-22041afd0340ce965d47ae6ef1cefeee28c7c493a6346c4f15d667ab976d596c.svg)](https://classroom.github.com/a/w0kw1MM5)
<HR><!-- -------------------------------------------------------------------------------------- -->
<P>
Write a program that starts two detached threads that communicate via a
global string variable.
<UL>
<LI> The main thread must
     <UL>
     <LI> Set the common global string to empty
     <LI> Start the communicating threads
     <LI> Detach the threads
     <LI> Exit
     </UL>
<LI> The <EM>producer</EM> thread must run a loop that:
     <UL>
     <LI> Yields the CPU until the global string is empty
     <LI> Prompts the user for a string
     <LI> Reads it into the global string
     </UL>
     until the user enters ^D (end of file). At that point the producer
     can cause the entire process to terminate.
<LI> The <EM>consumer</EM> thread must run an infinite loop that:
     <UL>
     <LI> Yields the CPU until the global string is non-empty
     <LI> Prints the global string to the screen
     <LI> Sets the global string to empty
     </UL>
</UL>
<P>
Here's what a sample run could look like, with user input in <EM>italics</EM>:
<PRE>
> L12_ThreadBuffer.out
Exiting the main program, leaving the threads running
Enter buffer data: Hello world!
The buffer contains Hello world!
Enter buffer data: Later alligator.
The buffer contains Later alligator.
Enter buffer data: ^D
</PRE>
<HR><!-- -------------------------------------------------------------------------------------- -->
