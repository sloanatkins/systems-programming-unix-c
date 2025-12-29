[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-22041afd0340ce965d47ae6ef1cefeee28c7c493a6346c4f15d667ab976d596c.svg)](https://classroom.github.com/a/GAmSe1AC)
<HR><!-- -------------------------------------------------------------------------------------- -->
<P>
It's so common to hear people start sentences with "I am" (as opposed to
<A HREF="http://www.utm.edu/research/iep/d/descarte.htm">Ren&eacute; Descartes</A>, who is
famous for ending a sentence like that).
The <A HREF="http://www.as.miami.edu/sociology/">Department of Sociology</A> might be
interested in a study of the qualities that people believe they possess.
With the <A HREF="http://www.cia.gov/">careful use</A> of
<A HREF="[https://stealthyninjas.com/best-spy-microphones/](https://www.zetronix.com/record-a-conversation.html)">
hidden microphones</A> and IBM's <A HREF="https://www.ibm.com/cloud/watson-speech-to-text">
Watson Speech to Text</A> software, it has been possible to obtain transcripts of several conversations.
Let's see what people think of themselves ...
<P>
Write a program that:
<UL>
<LI> Declares an array of 20 pointers to <TT>char</TT>
<LI> Repeatedly ...
     <UL>
     <LI> Reads a sentence from the keyboard (using <TT>fgets</TT>).
     <LI> Checks if the sentence starts with "I am " (using <TT>strstr</TT>)
     <LI> If it does, then extracts the substring starting at the 5th character, i.e., the
          substring containing the quality the person believes they possess. (using
          <TT>strncpy</TT>).
     <LI> Dynamically allocates enough memory for the quality string, and copies in the quality.
     <LI> Sets the next unused pointer of the array to point at that memory.
     <LI> Stops looping when a string containing just a "." is entered (check using
          <TT>strcmp</TT>).
     </UL>
<LI> Prints out the qualities
<LI> Sorts the array according to the quality strings, alphabetically, using <TT>qsort</TT>
<LI> Prints out the sorted qualities
<LI> Writes the sorted qualities out to a file named <TT>MyQualities.txt</TT>
</UL>
Here's what a sample run should look like (with the keyboard input shown in italics) ...
<PRE>
> MyQualities.out
Please enter sentences, . to end.</EM>
<EM>Hello everyone</EM>
<EM>I am very clever</EM>
<EM>Most people are not</EM>
<EM>I am good looking too</EM>
<EM>I am really good looking</EM>
<EM>You are ugly</EM>
<EM>I am confident</EM>
<EM>.</EM>
<P>
confident
good looking too
really good looking
very clever
<P>
> cat MyQualities.txt
confident
good looking too
really good looking
very clever
</PRE>
<P>
<HR><!-- -------------------------------------------------------------------------------------- -->
