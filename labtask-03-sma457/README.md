[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-22041afd0340ce965d47ae6ef1cefeee28c7c493a6346c4f15d667ab976d596c.svg)](https://classroom.github.com/a/X__ngwB_)
<HR><!-- -------------------------------------------------------------------------------------- -->
<P>
Use <TT>vi</TT> or <TT>emacs</TT> session to create a file called <TT>ICanDoIt.txt</TT> containing
commands to do the following (not a script, just a file for the TA to grade):
<OL>
<LI> A <TT>touch</TT> command to create a file called <TT>Help! I've run out of $s</TT> (0.25%)
<P>
<LI> An <TT>ls</TT> command that lists all the files (in the current directory) that start with an
     alphabetic character, contain a digit, and end with a dot followed by a lowercase character
     then one more character. Use only globbing (no piping to <TT>grep</TT>). (0.25%)
<P>
<LI> A series of commands that (0.75%)
     <UL>
     <LI> Compile <TT>Ticker.c</TT> to a binary called <TT>Ticker</TT>
     <LI> In one go, start <TT>Ticker 5</TT> in the background and <TT>Ticker 7</TT> in the
          foreground.
     <LI> Suspend <TT>Ticker 7</TT>
     <LI> List the jobs
     <LI> Activate <TT>Ticker 7</TT> in the background
     <LI> Bring <TT>Ticker 5</TT> into the foreground
     <LI> Suspend <TT>Ticker 5</TT>
     <LI> Kill <TT>Ticker 5</TT>
     <LI> Kill <TT>Ticker 7</TT>
     </UL>
<P>
<LI> A pipeline command from <TT>head</TT> to <TT>tail</TT> to <TT>grep</TT>, that will extract
     lines containing Computer Science course codes as distinct words from the 5th to 12th lines
     of <TT>CSCCodes.txt</TT>.
     The "CSC" must start with an uppercase "C" but the "SC" may be written in any combination of
     uppercase and lowercase.
     A correct solution extracts lines numbered 5, 7, 10, and 12. (0.75%)
</OL>
<HR><!-- -------------------------------------------------------------------------------------- -->
