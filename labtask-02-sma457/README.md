[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-22041afd0340ce965d47ae6ef1cefeee28c7c493a6346c4f15d667ab976d596c.svg)](https://classroom.github.com/a/U13TMhac)
<HR><!-- -------------------------------------------------------------------------------------- -->
<P>
Use a terminal session to:
<OL>
<LI> Find the following files and directories:
     <UL>
     <LI> The <TT>gcc</TT> compiler.
     <LI> The file that lists all the user groups.
     <LI> The directory that is used for print spooling.
     </UL>
     Put the full path names in a file called <TT>Eureka.txt</TT>. (0.75%)
<P>
<LI> Write a shell script called <TT>ChangeExtensions.sh</TT> that accepts two file 
     name extensions as arguments, and renames all files in the current working directory with 
     the first extension to have the second extension. 
     For example, <TT>ChangeExtensions.sh txt text</TT> would change all <TT>.txt</TT> files to 
     be <TT>.text</TT> files.
     The script must check that two arguments have been provided, and exit with an error message 
     if not.
     The script must check if there are any files with the first extension, and exit with an 
     error message if there are none.
     Otherwise a message must be output for each filename that is changed.
     Hint: read the <TT>man</TT> pages for <TT>basename</TT>.
     (1.0%)
<P>
<LI> Making files and directories 
     <UL>
     <LI> Make a directory called <TT>LabTask2</TT> off your home directory.
     <LI> Off <TT>LabTask2</TT>, a subdirectory called <TT>Originals</TT>
     <LI> In <TT>Originals</TT> two files, <TT>HardStuff.txt</TT> and <TT>SoftStuff.txt</TT> 
          (put any garbage in them)
     <LI> Off <TT>LabTask2</TT>, a subdirectory called <TT>Links</TT>
     <LI> In <TT>Links</TT> 
          <UL>
          <LI> A hard link named <TT>LinkToHardStuff.txt</TT> that links to <TT>HardStuff.txt</TT>
               in <TT>Originals</TT>.
          <LI> A relative soft (symbolic link) link named 
               <TT>RelativeToSoftStuff.txt</TT> to <TT>SoftStuff.txt</TT> in <TT>Originals</TT>.
          </UL>
     </UL>
     Put the commands that you used to do these (including making the directories and files) 
     into a file named <TT>MakingLinks.txt</TT>. (0.75%)
<P>
<LI> Create a directory called <TT>IveGotRights</TT> off <TT>LabTask2</TT>.
     Set its permissions to:
     <UL>
     <LI> Read, write, and execute permission for the owner
     <LI> Read and execute permission for the group
     <LI> Execute permission for others
     </UL>
     Put the commands that you used to do these into a file named <TT>Permissions.txt</TT>. (0.5%)
</OL>
<P>
<HR><!-- -------------------------------------------------------------------------------------- -->
