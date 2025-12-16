[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-22041afd0340ce965d47ae6ef1cefeee28c7c493a6346c4f15d667ab976d596c.svg)](https://classroom.github.com/a/UHSaIQlT)
<HR><!-- -------------------------------------------------------------------------------------- -->
<P>
Write two programs, a server and a client, that communicate via a socket.
<P>
The server must run an infinite loop that: (1.0%)
<UL>
<LI> Accepts a socket connection.
<LI> Uses the <TT>recv</TT> system call to read a single line off the
     socket.
<LI> Closes the socket.
<LI> Echos the line out to the screen.
</UL>
Note that the server does not <TT>fork</TT> a child to deal with the connection.

<P>
The client must: (1.0%)
<UL>
<LI> Connect to the server.
<LI> Use the <TT>send</TT> system call to write a line containing the
     client's machine.domain name <!--and IP number,--> down the socket.
<LI> Close the socket.
</UL>

You can use <A HREF="mysockets.h"><TT>mysockets.h</TT></A> and
<A HREF="mysockets.c"><TT>mysockets.c</TT></A> to do most of
the detailed socket manipulations (but you must not use the <TT>ReadData</TT> and
<TT>WriteData</TT> functions, use <TT>recv</TT> and <TT>send</TT>).
<P>
A sample run would look like:
<P>
<TABLE BORDER=0 WIDTH=80%>
<TR VALIGN=TOP> <TD TOP WIDTH=50%> <PRE>
&gt; SocketServer.out 5001
Listening socket : 127.0.1.1

SERVER: Received a connection
SERVER: That was armistead.(none)


SERVER: Received a connection
SERVER: That was armistead.(none)</PRE>
     <TD TOP WIDTH=50%> <PRE>
&gt; SocketClient.out armistead 5001
Calling socket : 127.0.1.1
  

&gt; SocketClient.out armistead 5001
Calling socket : 127.0.1.1</PRE>
</TABLE>
<P>
<HR><!-- -------------------------------------------------------------------------------------- -->
