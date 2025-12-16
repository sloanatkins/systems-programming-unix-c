<HR><!-- -------------------------------------------------------------------------------------- -->
<H2>Fibonacci Interface-Pipe-Thread Server</H2>

Write a Fibonacci server program that:
<UL>
<LI> Creates a named pipe, named "FIBOPIPE" (if the pipe already exists, you can use it, or delete
     it before creating a new one)
<LI> Sets up a signal handler for <TT>SIGXCPU</TT>.
     The handler ignores any further <TT>SIGXCPU</TT> signals, and sends a <TT>SIGUSR1</TT> to the
     child process.
     If the <TT>SIGXCPU</TT> interrupted the system call to read off the pipe, that read should not
     be restarted.
<LI> Limits its CPU usage to the number of seconds given as the command line parameter.
<LI> Set a global counter of the number running threads 0.
<LI> Creates a child process.
     <UL>
     <LI> The child process runs the user interface program described below, passing the named
          pipe's name in as the command line parameter.
     </UL>
<LI> Opens the named pipe for reading.
<LI> Repeatedly
     <UL>
     <LI> Reports the CPU time used (not including the user interface time)
     <LI> Reads an integer <EM>N</EM> off the pipe (the integers are placed there by the user
          interface program).
     <LI> Starts and detaches a new thread that ...
          <UL>
          <LI> Calculates the <EM>N</EM>th Fibonacci number using the
               <A HREF="RecursiveFibonacci.c">recursive O(2<SUP>n</SUP>) algorithm</A>.
          <LI> Prints out the result
          <LI> Decrements the number of running threads
          </UL>
     <LI> Increment number of running threads
     </UL>
     Until the integer is 0.
<LI> Closes the pipe
<LI> Waits for number of running threads to get down to 0
<LI> Reports the CPU time used (not including the user interface time)
<LI> Cleans up the user interface program zombie
<LI> Deletes the named pipe
<LI> Exits
</UL>

The user interface program:
<UL>
<LI> Sets up a signal handler for <TT>SIGUSR1</TT>.
     The handler causes the loop below to end, including sending 0 to the server.
     If the <TT>SIGUSR1</TT> interrupted the system call to read from the user, that read should
     not be restarted.
<LI> Opens the named pipe given as the command line argument for writing.
<LI> Repeatedly
     <UL>
     <LI> Prompts the user and read an integer from the terminal (you may assume that the user will
          enter a positive integer).
     <LI> If the signal handler has stopped the loop, change the integer to 0.
     <LI> Write the integer up the pipe (and flush the pipe to make sure the integer gets to the
          Fibonacci server).
     </UL>
     Until the integer is 0.
<LI> Closes the pipe
<LI> Exits
</UL>

<H3> Sample Runs </H3>

The keyboard inputs are in <EM>italics</EM>.
<P>
This run does not reach the CPU limit. 
The user inputs were given in rapid succession.
<PRE>
> ThreadFibServer.out 100
S: Setting CPU limit to 100s
I: Which Fibonacci number do you want : <EM>44</EM>
I: Which Fibonacci number do you want : S: Server has used 0s 1756us
S: Received 44 from interface
S: Created and detached the thread for 44
<EM>43</EM>
I: Which Fibonacci number do you want : S: Server has used 0s 515572us
S: Received 43 from interface
S: Created and detached the thread for 43
<EM>33</EM>
I: Which Fibonacci number do you want : S: Server has used 2s 210572us
S: Received 33 from interface
S: Created and detached the thread for 33
S: Fibonacci 33 is 3524578
<EM>42</EM>
I: Which Fibonacci number do you want : S: Server has used 3s 795963us
S: Received 42 from interface
S: Created and detached the thread for 42
<EM>0</EM>
I: Interface is exiting
S: Waiting for 3 threads
S: Waiting for 3 threads
S: Fibonacci 43 is 433494437
S: Fibonacci 42 is 267914296
S: Waiting for 1 threads
S: Fibonacci 44 is 701408733
S: Server has used 11s 654368us
S: Child 3948743 completed with status 0 </PRE>
<P>
This run does reach the CPU limit. 
The user inputs were given in rapid succession.
<PRE>
> ThreadFibServer.out 4
S: Setting CPU limit to 4s
I: Which Fibonacci number do you want : <EM>44</EM>
I: Which Fibonacci number do you want : S: Server has used 0s 1727us
S: Received 44 from interface
S: Created and detached the thread for 44
<EM>43</EM>
I: Which Fibonacci number do you want : S: Server has used 0s 602763us
S: Received 43 from interface
S: Created and detached the thread for 43
<EM>33</EM>
I: Which Fibonacci number do you want : S: Server has used 1s 793560us
S: Received 33 from interface
S: Created and detached the thread for 33
S: Fibonacci 33 is 3524578
<EM>42</EM>
I: Which Fibonacci number do you want : S: Server has used 2s 906340us
S: Received 42 from interface
S: Created and detached the thread for 42
<EM>0</EM>
S: Received a SIGXCPU, ignoring any more
S: Received a SIGXCPU, sending SIGUSR1 to interface
I: Received a SIGUSR1, stopping loop
I: Reading from user abandoned
I: Interface is exiting
S: Waiting for 3 threads
S: Waiting for 3 threads
S: Waiting for 3 threads
S: Fibonacci 42 is 267914296
S: Fibonacci 43 is 433494437
S: Waiting for 1 threads
S: Fibonacci 44 is 701408733
S: Server has used 12s 845677us
S: Child 3949093 completed with status 0 </PRE>
<P>
This run does reach the CPU limit. 
The user inputs were given slowly.
<PRE>
> ThreadFibServer.out 4
S: Setting CPU limit to 4s
I: Which Fibonacci number do you want : <EM>44</EM>
I: Which Fibonacci number do you want : S: Server has used 0s 1668us
S: Received 44 from interface
S: Created and detached the thread for 44
<EM>43</EM>
I: Which Fibonacci number do you want : S: Server has used 2s 71053us
S: Received 43 from interface
S: Created and detached the thread for 43
S: Received a SIGXCPU, ignoring any more
S: Received a SIGXCPU, sending SIGUSR1 to interface
I: Received a SIGUSR1, stopping loop
I: Reading from user abandoned
I: Interface is exiting
S: Waiting for 2 threads
<EM>33</EM>
S: Waiting for 2 threads
S: Waiting for 2 threads
S: Fibonacci 43 is 433494437
S: Waiting for 1 threads
S: Fibonacci 44 is 701408733
S: Server has used 9s 474782us
S: Child 3949066 completed with status 0 </PRE>

The project is due by 8am on 10th December.
You may sit with the TA when (s)he runs your program in the lab session so you can see together
how well it works.
<P>
Your project is worth 15% of the course grade.
It will be assessed for functionality and programming style using
<A HREF="ThreadFibMarkingScheme.md">this marking scheme</A>.
Please review the policies on assessment in the administration document.
<HR><!-- -------------------------------------------------------------------------------------- -->
