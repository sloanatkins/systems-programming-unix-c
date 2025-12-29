[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-22041afd0340ce965d47ae6ef1cefeee28c7c493a6346c4f15d667ab976d596c.svg)](https://classroom.github.com/a/Ss1aJgRs)
<HR><!-- -------------------------------------------------------------------------------------- -->
<P>
A <A HREF="https://education.nationalgeographic.org/resource/charles-darwin/">naturalist</A> is off
to explore the <A HREF="https://rainforests.mongabay.com/amazon/">amazon jungle</A>, and wants a
computer program to record information about all the new
<A HREF="https://kids.nationalgeographic.com/animals">species</A> discovered.
For each new species it is necessary to store the name (max 128 characters), size (a real number),
and the type of animal (an <TT>enum</TT> type, one of mammal, insect, bird, or fish).
Write a program to store and print out the information.
<P>
An array of 10 structures must be used, so that each new species can be recorded in an element
of the array.
Here's the <A HREF="EnumStringConversion.c">boring code</A> to convert between strings and enums.
<P>
Here what a sample run should look like (with the keyboard input shown in italics) ...
<PRE>
> NewSpecies.out
Enter animal information ("exit" to exit)
What is the name : <EM>bloatfish</EM>
What is the size : <EM>12.47</EM>
What is the type : <EM>fish</EM>
Enter animal information ("exit" to exit)
What is the name : <EM>stingybeasty</EM>
What is the size : <EM>0.13</EM>
What is the type : <EM>insect</EM>
Enter animal information ("exit" to exit)
What is the name : <EM>toothfulsloth</EM>
What is the size : <EM>33.33</EM>
What is the type : <EM>mammal</EM>
Enter animal information ("exit" to exit)
What is the name : <EM>exit</EM>

The following new species were found:
bloatfish            has size  12.47 and is a fish
stingybeasty         has size   0.13 and is a insect
toothfulsloth        has size  33.33 and is a mammal </PRE>

<STRONG>Full marks</STRONG> requires a beautiful program, with full attention to programming style.
<P>
<STRONG>For bonus marks</STRONG>,
rather than using a fixed size array, <TT>malloc</TT> for an initial array of size 1, and use
<TT>realloc</TT> to extend the array for each animal after the first one.
<P>
<HR><!-- -------------------------------------------------------------------------------------- -->
