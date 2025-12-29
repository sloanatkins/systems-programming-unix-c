[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-22041afd0340ce965d47ae6ef1cefeee28c7c493a6346c4f15d667ab976d596c.svg)](https://classroom.github.com/a/1NT_D6fa)
<HR><!-- -------------------------------------------------------------------------------------- -->
<P>
I set this labtask at <A HREF="http://www.timeanddate.com/worldclock/">10:40am on the 19th of
March 2003</A>.
The deadline for <A HREF="http://news.bbc.co.uk/1/hi/world/middle_east/1100529.stm">Saddam
Hussein</A> to react to the demands of the "coalition of allies" (or as the
<A HREF="http://www.cbs.com/latenight/lateshow/">Late Show</A> named them, "Britain and Spain") was
8pm that night.
It seemed likely that the demands would not be met, and the USA would wage
<A HREF="https://war.com">war</A> (what?) on <A HREF="http://www.iraqfoundation.org/">Iraq</A>.
At times like that it is useful to record the perceived "best ally" of each country involved.
<P>
Write a program that allows a user to:
<UL>
<LI> Enter the names of the countries of interest, terminated by a blank entry.
<LI> For each country entered, enter the name of its best ally.
     You can assume that the best ally exists in the list.
<LI> Print out the "best allies"
</UL>

A sample run should look something (order is not important) like (the keyboard input is in
italics) ...
<PRE>
Enter nation name : <EM>USA</EM>
Enter nation name : <EM>Britain</EM>
Enter nation name : <EM>Egypt</EM>
Enter nation name : <EM>Iraq</EM>
Enter nation name : <EM>Kuwait</EM>
Enter nation name : <EM>France</EM>
Enter nation name :
Enter best ally name for France  : <EM>Britain</EM>
Enter best ally name for Kuwait  : <EM>USA</EM>
Enter best ally name for Iraq    : <EM>Egypt</EM>
Enter best ally name for Egypt   : <EM>France</EM>
Enter best ally name for Britain : <EM>USA</EM>
Enter best ally name for USA     : <EM>Britain</EM>
The best ally of France is Britain
The best ally of Kuwait is USA
The best ally of Iraq is Egypt
The best ally of Egypt is France
The best ally of Britain is USA
The best ally of USA is Britain </PRE>

<H3>You must ...</H3>
<UL>
<LI> Implement the program in C.
     <UL>
     <LI> Each country name entered must be stored in a <TT>malloc</TT>ed node of a linked list.
     <LI> Each node of the linked list must contain (only) the country name, a pointer to the
          node for its best ally, and a pointer to the next node in the list.
     <LI> Before the program completes it must explicitly <TT>free</TT> the <TT>malloc</TT>ed
          memory.
     </UL>
</UL>
<P>
<HR><!-- -------------------------------------------------------------------------------------- -->
