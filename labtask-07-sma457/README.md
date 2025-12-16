[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-22041afd0340ce965d47ae6ef1cefeee28c7c493a6346c4f15d667ab976d596c.svg)](https://classroom.github.com/a/VaKy054x)
<HR><!-- -------------------------------------------------------------------------------------- -->
<P>
<OL>
<LI> The <TT>BitOps.c</TT> program already has a macro that determines whether or
     not an <TT>unsigned int</TT> is odd by examining the least significant binary digit.
     It is missing the macros for determining if the Nth least significant bit is set (counting
     N from the least significant bit, starting from 0), and for determining if all bits are on
     in a range of positions.
     <P>
     You must add those macros (1.0%)
     <P>
     A couple of sample runs are ...
     <PRE>
> BitOps.out
Enter an integer : 31
31 is odd
Enter an integer and a bit number : 31 3
31 has bit 3 on
Enter an integer, start and end bit numbers : 31 2 4
31 has all those bits on
     </PRE>
     <PRE>
> BitOps.out
Enter an integer : 30
30 is even
Enter an integer and a bit number : 30 6
30 has bit 6 off
Enter an integer, start and end bit numbers : 30 4 6
30 has not all those bits on
     </PRE>
<P>
<LI> It's so common to hear people start sentences with "I am" (as opposed to
     <A HREF="http://www.utm.edu/research/iep/d/descarte.htm">Ren&eacute; Descartes</A>, who is
     famous for ending a sentence like that).
     The <A HREF="http://www.as.miami.edu/sociology/">Department of Sociology</A> might be
     interested in a study of the qualities that people believe they possess.
     With the <A HREF="http://www.cia.gov/">careful use</A> of
     <A HREF="https://www.zetronix.com/record-a-conversation.html">
     hidden microphones</A> and IBM's <A HREF="https://www.ibm.com/cloud/watson-speech-to-text"> 
     Watson Speech to Text</A> software, it has been possible to obtain transcripts of several conversations.
     Let's see what people think of themselves ...
<P>
Write a program called <TT>IAm.c</TT> that:
<UL>
<LI> Repeatedly ...
     <UL>
     <LI> Reads a sentence from the keyboard (using <TT>fgets</TT>).
     <LI> Checks if the sentences starts with "I am " (using <TT>strstr</TT>)
     <LI> If it does, then extracts the substring starting at the 5th character, i.e., the
          substring containing the quality the person believes they possess. (using
          <TT>strncpy</TT>).
     <LI> Concatenates the substring onto a growing string containing all such qualities, with a
          comma separator (using <TT>strncat</TT> - the growing string has a maximal length of
          1024 characters).
     <LI> Stops looping when a string containing just a "." is entered (check using
          <TT>strcmp</TT>).
     </UL>
<LI> Outputs the grown string of qualities to the screen. (1.0%)
</UL>
     Here's what a sample run should look like (with the keyboard input shown in italics) ...
     <PRE>
Please enter sentences, . to end.</EM>
<EM>Hello everyone</EM>
<EM>I am very clever</EM>
<EM>Most people are not</EM>
<EM>I am good looking too</EM>
<EM>I am really good looking</EM>
<EM>You are ugly</EM>
<EM>I am confident</EM>
<EM>.</EM>
The qualities are very clever, good looking too, really good looking, confident.
     </PRE>
</OL>
<HR><!-- -------------------------------------------------------------------------------------- -->
