[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-22041afd0340ce965d47ae6ef1cefeee28c7c493a6346c4f15d667ab976d596c.svg)](https://classroom.github.com/a/rH1YfSCZ)
<HR><!-- -------------------------------------------------------------------------------------- -->
The Marina Manager of <A HREF="https://www.nauticalventures.com/marina">Nautical Ventures</A>
needs a simple program to track the various boats stored and being repaired at the marina, and
the charges being levied on each:
<UL>
<LI> Boats in
     <A HREF="https://www.shoremaster.com/about-shoremaster/news-events/articles/boat-dock-vs-boat-slip/">slips</A>
     - $12.50/foot/month
<LI> Boats on
     <A HREF="https://www.boatus.com/expert-advice/expert-advice-archive/2014/april/how-long-does-boat-bottom-paint-last">land for work</A>
     - $14.00/foot/month
<LI> Boats on
     <A HREF="http://www.ezloader.com">trailors</A>
     - $25.00/foot/month
<LI> Boats in
     <A HREF="https://www.rmimarina.com/dry-storage">storage</A>
     - $11.20/foot/month
</UL>
The program must allow for up to 20 boats, and must hold the following information about each
boat (hint: use a <TT>struct</TT>):
<UL>
<LI> The <A HREF="https://www.veranda.com/luxury-lifestyle/a41001953/best-boat-names/">name</A>
     of the boat (up to 128 characters long, not containing a comma)
<LI> The length in feet - up to 100' (hint: choose a suitable data type)
<LI> Which type of place (slip/land/trailor/storage) (hint: use an <TT>enum</TT>)
<LI> Depending on the type, extra relevant information (hint: use a <TT>union</TT>):
     <UL>
     <LI> Slip - the slip number 1-85
     <LI> Land - the bay letter, A-Z
     <LI> Trailor - the trailor license tag
     <LI> Storage - the storage space number 1-50
     </UL>
<LI> The amount of <A HREF="https://www.discoverboating.com/buying/costs-of-boat-ownership">
     money owed</A> to the marina.
</UL>
The data for each boat must be held in a <TT>malloc</TT>ed <TT>struct</TT> that is pointed to
by an element of an array of 20 pointers.
The array must be kept sorted by boat name (hint: use <TT>qsort</TT>).
<P>
While the program is not running the data about the boats is stored in a
<A HREF="https://en.wikipedia.org/wiki/Comma-separated_values">Comma Separated Values</A> file
such as <A HREF="BoatData.csv"><TT>BoatData.csv</TT></A>.
When the program starts it must load the data (hint: use <TT>strtok</TT>) from the file whose
name is provided as the command line argument, and when the program exits it must store the data
back to that file.
<P>
Once the boat data is loaded the program must offer a
<A HREF="https://www.pizzahut.com/index.php?menu=#/menu">menu</A> of options:
<OL>
<LI> Print the boat inventory, sorted alphabetically by boat name (hint: keep the array packed and
     sorted by boat name)
<LI> Add a boat by providing as a string that looks like one line of the <TT>.csv</TT> file
<LI> Remove a boat by name
<LI> Accept a payment for the boat, up to the amount owed
<LI> Update the amount owed because a new month has started
<LI> Exit
</OL>
The program must be user friendly, but you can assume that the user will enter reasonable data
values:
<UL>
<LI> Menu options must be accepted in upper and lower case.
     The user might enter an invalid option, which results in an error message and is ignored.
<LI> Boat data in <TT>.csv</TT> format will be correctly formatted and within limits
<LI> Numeric input will be syntactically correct.
<LI> The user might enter a non-existent boat name for removal and payment, or an amount too
     large for payment, in which case the action is not completed.
</UL>
<P>
Here's what a run should look like (with the keyboard input shown in italics) ...
<PRE>
> BoatManagement BoatData.csv

Welcome to the Boat Management System

(I)nventory, (A)dd, (R)emove, (P)ayment, (M)onth, e(X)it : <EM>Q</EM>
Invalid option Q

(I)nventory, (A)dd, (R)emove, (P)ayment, (M)onth, e(X)it : <EM>i</EM>
Big Brother           20'    slip   # 27   Owes $1200.00
Magic                 38' trailor 7KZ099   Owes $   0.00
Moon Glow             30'    slip   # 13   Owes $ 500.00
Osita                 40'    land      C   Owes $1000.07
Run About             18' storage   # 13   Owes $ 200.50

(I)nventory, (A)dd, (R)emove, (P)ayment, (M)onth, e(X)it : <EM>A</EM>
Please enter the boat data in CSV format                 : <EM>Brooks,34,trailor,AAR666,99.00</EM>

(I)nventory, (A)dd, (R)emove, (P)ayment, (M)onth, e(X)it : <EM>I</EM>
Big Brother           20'    slip   # 27   Owes $1200.00
Brooks                34' trailor AAR666   Owes $  99.00
Magic                 38' trailor 7KZ099   Owes $   0.00
Moon Glow             30'    slip   # 13   Owes $ 500.00
Osita                 40'    land      C   Owes $1000.07
Run About             18' storage   # 13   Owes $ 200.50

(I)nventory, (A)dd, (R)emove, (P)ayment, (M)onth, e(X)it : <EM>r</EM>
Please enter the boat name                               : <EM>Lost Soul</EM>
No boat with that name

(I)nventory, (A)dd, (R)emove, (P)ayment, (M)onth, e(X)it : <EM>R</EM>
Please enter the boat name                               : <EM>MAGIC</EM>

(I)nventory, (A)dd, (R)emove, (P)ayment, (M)onth, e(X)it : <EM>i</EM>
Big Brother           20'    slip   # 27   Owes $1200.00
Brooks                34' trailor AAR666   Owes $  99.00
Moon Glow             30'    slip   # 13   Owes $ 500.00
Osita                 40'    land      C   Owes $1000.07
Run About             18' storage   # 13   Owes $ 200.50

(I)nventory, (A)dd, (R)emove, (P)ayment, (M)onth, e(X)it : <EM>P</EM>
Please enter the boat name                               : <EM>Broke Boater</EM>
No boat with that name

(I)nventory, (A)dd, (R)emove, (P)ayment, (M)onth, e(X)it : <EM>P</EM>
Please enter the boat name                               : <EM>Moon Glow</EM>
Please enter the amount to be paid                       : <EM>2000</EM>
That is more than the amount owed, $500.00

(I)nventory, (A)dd, (R)emove, (P)ayment, (M)onth, e(X)it : <EM>P</EM>
Please enter the boat name                               : <EM>Moon Glow</EM>
Please enter the amount to be paid                       : <EM>200</EM>

(I)nventory, (A)dd, (R)emove, (P)ayment, (M)onth, e(X)it : <EM>i</EM>
Big Brother           20'    slip   # 27   Owes $1200.00
Brooks                34' trailor AAR666   Owes $  99.00
Moon Glow             30'    slip   # 13   Owes $ 300.00
Osita                 40'    land      C   Owes $1000.07
Run About             18' storage   # 13   Owes $ 200.50

(I)nventory, (A)dd, (R)emove, (P)ayment, (M)onth, e(X)it : <EM>m</EM>

(I)nventory, (A)dd, (R)emove, (P)ayment, (M)onth, e(X)it : <EM>I</EM>
Big Brother           20'    slip   # 27   Owes $1450.00
Brooks                34' trailor AAR666   Owes $ 949.00
Moon Glow             30'    slip   # 13   Owes $ 675.00
Osita                 40'    land      C   Owes $1560.07
Run About             18' storage   # 13   Owes $ 402.10

(I)nventory, (A)dd, (R)emove, (P)ayment, (M)onth, e(X)it : <EM>x</EM>

Exiting the Boat Management System
</PRE>
Here's what the saved <TT>.csv</TT> file could look like:
<PRE>
Big Brother,20,slip,27,1450.00
Brooks,34,trailor,AAR666,949.00
Moon Glow,30,slip,13,675.00
Osita,40,land,C,1560.07
Run About,18,storage,13,402.10
</PRE>

The project is due by 8am on 25th November.
You may sit with the TA when (s)he runs your program in the lab session so you can see together
how well it works.
<P>
Your project is worth 20% of the course grade.
It will be assessed for functionality and programming style using
<A HREF="BoatManagementMarkingScheme.html">this marking scheme</A>.
Please review the policies on assessment in the administration document.
<HR><!-- -------------------------------------------------------------------------------------- -->
