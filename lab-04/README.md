[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-22041afd0340ce965d47ae6ef1cefeee28c7c493a6346c4f15d667ab976d596c.svg)](https://classroom.github.com/a/XcdbFRpl)
<HR><!-- -------------------------------------------------------------------------------------- -->
<P>
<OL>
<LI> Make a subdirectory called <TT>Labtask4</TT>, and change into <TT>Labtask4</TT>.
     Devise a sequence command to copy <TT>Ticker.c</TT> from the parent directory into the
     current directory (<TT>Labtask4</TT>), then compile it with all warnings, and output the
     executable to <TT>Ticker</TT>.
     Put the sequence command into a file called <TT>MakeTheTicker.txt</TT>. (0.25%)
<P>
<LI> Use <TT>vi</TT> or <TT>emacs</TT> to type in the <TT>FahrCelciusWhile.c</TT> program.
     Compile it and run it.
     Submit the source code, and the output from the run in a file named
     <TT>FahrCelciusWhile.out</TT>. (0.25%)
<P>
<LI> <A HREF="https://www.youtube.com/watch?v=8BbZTCdB2X4">Kangaroos</A>, native animals of
     Australia, are not known for their intelligence.
     In fact they're pretty stupid.
     Only slightly smarter than sheep, and that's not saying much.
     In the outback kangaroos regularly
     <A HREF="https://www.drive.com.au/news/how-to-avoid-hitting-a-kangaroo-20130812-2rrw8/">
     jump onto the road</A> just when a car is coming along (especially at night, because the
     car headlights scare them).
     This makes a serious mess of your car, unless you have a
     <A HREF="http://en.wikipedia.org/wiki/Roo_bars">roo-bar</A>" on the front.
     Sadly, many 'roos get killed in these collisions.
     The <A HREF="http://www.rac.com.au">Royal Automobile Club</A> of Australia needs a computer
     program to calculate the expected number of kills each year.
     This will be done for square parcels of land, each of which has roads of known length running
     through.
     <P>
     The program must get the following information from the user:
     <UL>
     <LI> The length of the side of the square of land (in kilometers).
     <LI> The length of roads running through the square (in kilometers).
     <LI> The number of kangaroos living in that square.
     </UL>
     <P>
     The calulation of the expected number of kills has two phases.
     First, the kangaroo density has to be calculated - this is the number of kangaroos per square
     kilometer.
     Second, the road surface area has to be calculated, using the average Australian road width
     which is 10 meters.
     These are multiplied with the well known roadkill probablility constant, which is 1.47.
     <P>
     Here's what a sample run should look like, with the keyboard input in
     <EM>italics</EM> ...
     <PRE>
     Enter side of square in km  : <EM>3.5</EM>
     Enter roads length in km    : <EM>10</EM>
     Enter number of 'roos       : <EM>150</EM>
     Expected number of kills is : 1.8
     </PRE>
     <P>
     The program can be a single <TT>main</TT> function, or if you're feeling confident, use extra
     functions appropriately.
     <EM>Don't use any features of C that have not been explained in class.</EM>
     (1.5%)
     <P>
     Of course ChatGPT can provide <A HREF="RooKillChatGPT.c"> an answer that uses bad
     programming style</A> (ask Google about <TT>good C programming style</TT>).
     I have instructed the TAs to be ruthless and vicious about programming style.
     They will have no mercy - and you will not get the 1.5% unless your code is a thing of
     elegance and beauty.
     Submit your source code in a file named <TT>RooKill.c</TT> (1.5%)
</OL>
<HR><!-- -------------------------------------------------------------------------------------- -->
