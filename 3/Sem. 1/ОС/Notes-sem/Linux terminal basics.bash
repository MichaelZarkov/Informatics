# This file is not for compilation.
# These are my (Michael Zarkov) notes for the course "Operating systems" in FMI.
# You should view it as a shell script file for best visual experience :)
# This file mainly consists of often used commands and other useful stuff for the Linux terminal.

# Things to write/read/learn:
    # Linux file system.
    # Ask assistant Rado if the other assistants' folders are meant to be accessible by us.
    # Symlinks and hard links.
    # Environment variables, shell variables.
    # When and how to use '*'.
    # Regular expressions.
    # The difference between single and double quotes.

# List of some basic commands that we use in exercises, with commonly used flags.
# Commands are ordered alphabetically.
# Notation: I use <> for the necessary parameters of a function, and [] for the optional parameters,
#           but there may be errors so consult the man page when in doubt.

    # Pattern scanning and processing language (AWK).
    # The name AWK is derived from the family names of its authors − Alfred Aho, Peter Weinberger,
    # and Brian Kernighan.
    # AWK is an interpreted programming language. It is also Turing complete.
    #
    # The AWK language is a data-driven scripting language consisting of a set of actions to be taken
    # against streams of textual data – either run directly on files or used as part of a pipeline –
    # for purposes of extracting or transforming text, such as producing formatted reports.
    #
    # AWK reads the input a line at a time. A line is scanned for each pattern in the program, and
    # for each pattern that matches, the associated action is executed.
    # An AWK program is a series of pattern action pairs, written as:
    #   condition { action }
    #   condition { action }
    #   ...
    # where condition is typically an expression and action is a series of commands (condition is a 
    # boolean expression). The input is split into records, where by default records are separated by
    # newline characters so that the input is split into lines. The program tests each record against
    # each of the conditions in turn, and executes the action for each expression that is true. Either
    # the condition or the action may be omitted. The condition defaults to matching every record. The
    # default action is to print the record. This is the same pattern-action structure as sed.
    #   The key words 'BEGIN' and 'END' are matched respectively before the beginning of the execution 
    # of the program on the text input and after the end of execution.'BEGIN {action-1}', the first thing 
    # that is executed is 'action-1', 'END {action-2}' the last thing executed will be 'action-2'.
    # 'BEGIN' and 'END' blocks are not necessary and can be omitted. 'BEGINFILE' and 'ENDFILE' blocks are
    # similar but are executed before and after the processing of each file.
    #
    # We can also declare variables which are interpreted as either strings or numbers.
    #
    # We also have Built-in variables for certain useful values: 
    #   NR - Number of Records. Keeps a current count of the number of input records read so far from
    #        all data files. Starts at zero
    #   FNR - File Number of Records. Keeps a current count of the number of input records read so far
    #         in the current file. This variable is automatically reset to zero each time a new file
    #         is started.
    #   NF - Number of Fields. Contains the number of fields in the current input record. The last
    #        field in the input record can be designated by $NF, the 2nd-to-last field by $(NF-1), the
    #        3rd-to-last field by $(NF-2), etc.
    #   $1, $2, $3 ... - They hold the text or values in the individual text-fields in the current record.
    #   $0 - Holds the entire record.
    #   ... and so on.
    #
    # Regular expressions in AWK are enclosed in '/'. For example /mike/ matches the word 'mike'. See the 
    # examples section for more examples. See also the solved tasks file for more examples.
    awk
    print  # print command in AWK.
    

    # Concatenate files and print on the standard output.
    cat [file]  # If a file is specified, this prints the whole file to the standard output.
                # If a file is not specified, cat just reads from the standard input and upon seeing
                # the first new line stops reading and prints the line. To exit this mode just hit
                # Ctrl + D.
    -n  # Prints the file with line numbers.

    # Change file mode bits (read, write, execute permissions).
    chmod <mode> <file>
    # 'mode' is in the form {ugoa}{+-=}{rwx, ugoa}.
    # 'u' user, 'g' group, 'o' other users, 'a' all users.
    # '+' add permissions, '-' remove permissions, '=' set permissions the same as the given user.
    
    # Clears all text from the terminal window.
    clear
    
    # Copy files and directories.
    cp <src> <dest>  # Copy single file from 'src' to 'dest'.
    cp <src-1> ... <src-n> <dir>  # Copy all given files to 'dir'.
    # Note that both of the above without warning overwrite the files in the destination, if they exist.
    # We can use the wildcard pattern '*' to match filenames. For example if we have a lot of .txt files in 
    # a directory and we want to copy them all, we can write 'cp *.txt <dest_dir>' and this will copy them 
    # all to 'dest_dir'.
    -r  # Copy directories recursively.

    # Remove sections from each line of files.
    cut 
    -f <list>   # Select only the specified fields (columns). <list> is comma-separated list of numbers.
                # Numbering starts from 1.
    -d <delim>  # Set field delimiter.
    -b <list>   # Select only the specified bytes from each line (<list> is comma-separated list of numbers).
    -c <list>   # Select only the specified characters from each line.

    # Bring process to foreground.
    fg
    # For example if you're in vim and type 'CTRL + z' this will suspend the process and return you to the
    # shell vim was originally started in. You can return to vim by typing 'fg'.

    # Search for files in a directory hierarchy. Very powerful command. 'find' basically does DFS on
    # the directory tree with root the given directory. If no arguments are specified prints every
    # file and directory name from the given subtree.
    find [dir]  # If 'dir' is not given the current working directory is used.
    -mindepth <int>  # Don't apply actions on levels less that the given ('int' >= 0). The given 'dir'
                     # is considered level 0 so for example '-mindepth 1' means skip only the
                     # starting 'dir'.
    -maxdepth <int>  # Same as '-mindepth' but don't apply actions on levels more than the given
                     # ('int' >= 0).
    -mmin [+-]<num>  # Apply actions only if file's data was last modified less than, more than or
                     # exactly 'num' minutes ago.
                     # If '+', then more than 'num' minutes ago.
                     # If '-', then less than 'num' minutes ago.
                     # If nothing, then exactly 'num' minutes ago.
                     # There are more flags of this type that let you filter by time.
    -type <arg>  # Specify the type of files to apply actions to. For example argument 'f' is for regular
                 # file 'd' is for directory and so on.
    -size <agr>  # Specify the size of the files to apply actions to (can be in different units: B, KB, MB ...).
    -perm <agr>  # Specify the permissions.

    # Wrap each input line to fit in specified width.
    fold [file] 
    -w <num>  # Use 'num' as width instead of default 80.

    # Print lines that match patterns. 'grep' stands for global search for regular expression and printout.
    grep <regular_expression> <file-1> <file-n>
    <regular_expression>  # Enclosed in "".
    -A <num>  # Print 'num' lines of trailing context after matching lines.
    -B <num>  # Print 'num' lines of leading context before matching lines.
    -v  # Invert the sense of matching, to select non-matching lines.
    -c  # Print the number of matching lines.
    -i  # Case insensitive search.
    -o  # Print only the matched (non-empty) parts of a matching line, with each such part on a separate output
        # line. Useful for counting how many occurrences of the match.
    
    # Print group memberships for each USERNAME or, if no USERNAME is specified, for the current process.
    groups [username-1] ... [username-n]  

    # Output the first part of a file.
    head [file-1] ... [file-n]  # Outputs the first 10 lines of each file to the standard output.
                                # Can be called without arguments and it does a similar thing to 'cat'.
                                # Note that we can give it as many files as we want. That is very useful.
    -n <num>  # 'num' is a whole number.
              # If 'num' is positive, prints the first 'num' number of lines.
              # If 'num' is negative, prints all but the last abs('num') number of lines.
    -c <num>  # Print the first 'num' bytes of each file.
    -q        # Don't print file names.
    
    # Make links between files (hard links and symbolic links).
    # Note: Hard links can only by links to files, not directories. Symlinks can be links to files
    # or directories.
    # Note: When 'ls' is called, usually symlinks will be a different colour from the files and hard
    # links will be the same colour as the files.
    ln <target> <link-name>  # Creates a hard link to 'target' with 'link-name' in the current directory.
    -s  # Creates a symbolic link.

    # List directory contents.
    ls [dir]  # Lists the files and directories in 'dir'.
              # If 'dir' is not given the current working directory is used.
    -a  # Do not ignore filenames starting with '.'.
    -l  # Extended information is printed for each file/directory like the file type, 
        # file mode bits, number of hard links, owner name, group name, size, and timestamp.
    -S  # Sort by file size, largest first.

    # Manual pages (man page).
    # 'man' command in Linux is used to display the user manual of any command that we can run on the terminal.
    man <command>  # And yes, you can do 'man man'.

    # Make a folder/directory (note: folder and directory are synonyms).
    mkdir <path-1> ... <path-n>  # Creates n folders in the specified locations.
    -p  # No error if existing, make parent directories as needed, with their file modes unaffected by any -m option.

    # To add explanation ...    
    printf

    # Remove(delete) files.
    rm <src-1> ... <src-n>  # Deletes the given files. If one or more are directories gives an error.
    rm -r <src>  # Removes EVERYTHING down the directory tree including <src>.
    
    # Stream editor. 
    # A stream editor is used to perform basic text transformations on an input stream (a file or input from a
    # pipeline).
    sed
    
    # Sort lines of text files.
    sort [file_path]  # When we give it a file, it sorts its rows lexicographically.
    -t <separator>    # Use <separator> instead of non-blank to blank transition (set separator for the columns).
    -k <num>          # Select which column to sort by (numbering starts from 1).
    -n                # Compare according to string numerical value (not lexicographically as by default).
    
    # Compress and archive files (archiving utility).
    tar
    --create  # Create an archive.
    --list    # List contents of an archive.
    
    # Create files.
    touch <path-1> ... <path-n>  # Creates n files in the specified locations.
    
    # Translate,  squeeze,  and/or delete characters from standard input, writing to standard output.
    # Useful if we want to remove certain characters form a stream.
    tr  # ... to write useful stuff.
    
    
    # Print newline, word, and byte counts for each file
    wc [file-1] ... [file-n]
    -c  # Print byte counts. 
    -m  # Print the character counts.
    -l  # Print newline counts.
    -w  # Print the word counts.
    
    # The non-interactive network downloader.
    # You can download files from GitHub for example.
    wget <URL>
    
# Operators:
# Contents 
# 01. Input and output redirection.
# 02. Command substitution.
# 03. Piping.

    # 01. Input and output redirection operators.
        # For more in-depth explanation check out: https://homepages.uc.edu/~thomam/Intro_Unix_Text/IO_Redir_Pipes.html
        # See examples in "Examples operators" section below.
        #
        # In typical Unix installations, commands are entered at the keyboard and output resulting from
        # these commands is displayed on the computer screen. Thus, input (by default) comes from the
        # terminal and the resulting output (stream) is displayed on (or directed to) the monitor
        # (also the terminal). Commands typically get their input from a source referred to as standard
        # input (stdin) and typically display their output to a destination referred to as standard output (stdout).
        #
        # Unix provides the capability to change where standard input comes from, or where output goes using a
        # concept called Input/Output (I/O) redirection. I/O redirection is accomplished using a redirection
        # operator which allows the user to specify the input or output data be redirected to (or from) a file.
        # Note that redirection always results in the data stream going to or coming from a file (the terminal is
        # also considered a file).
        #
        # For every Unix command there are 3 channels: standard input, standard output and standard error.
        # The following are the operators which redirect these channels.
        #
        # '>' and '>>' are the standard output redirection operators.
        # The basic syntax for using these is:
        #   command > output_file
        #   command >> output_file
        # The only difference is that '>' overwrites the contents and '>>' appends to the end of the file.
        # In both cases 'output_file' is created if it doesn't already exist.
        # Note that if 'output_file' doesn't exist, it is created before the execution of 'command'.
        #
        # '<' is the standard input redirection operator.
        # General syntax:
        #   command < input_file
        # Pretty self explanatory. We specify a file for the input of a command.
        #
        # '2>' and '2>>' are the standard error redirection operators.
        # Same as standard output redirection operators but for the error channel
        
    # 02. Command substitution.
        # Command substitution allows the output of a command to replace the command itself. Command substitution
        # occurs when a command is enclosed as follows:
        #   $(command)
        # or 
        #   `command`
        # Bash performs the expansion by executing command in a subshell environment and replacing the command
        # substitution with the standard output of the command, with any trailing newlines deleted. Embedded
        # newlines are not deleted, but they may be removed during word splitting.
        # When the old-style backquote form of substitution is used, backslash retains its literal meaning except
        # when followed by ‘$’, ‘`’, or ‘\’. The first backquote not preceded by a backslash terminates the command
        # substitution. When using the $(command) form, all characters between the parentheses make up the command,
        # none are treated specially.
        # Command substitutions may be nested. To nest when using the backquoted form, escape the inner backquotes
        # with backslashes.
        # If the substitution appears within double quotes, word splitting and filename expansion are not performed
        # on the results.
    
    # 03. Piping.
        # The pipe operator is the | character (typically located above the enter key). This operator serves to
        # join the standard output stream from one process to the standard input stream of another process in the
        # following manner:
        #   command-1 | command-2 | ... | command-n

# Regular expressions.
    # To do ...
    
# Shell parameters.
    # To do ...

# Collection of different bits of information:
    
    # When executing a bash command which takes a directory as an argument, if no directory is specified
    # by default the current working directory is used (actually there might be some obscure command
    # which doesn't work this way, but in general the above is true).
    
    # In Linux we can have white spaces as part of file and directory names but we have to use the 
    # escape character '\' to specify the white space character is part of the name. Example:
    touch my\ file  # This creates a file named "my file" in the current working directory.
    
    # 'Shift + Insert' is the key combination for pasting (on our version of Linux).
    
    # Когато имаме флаг, който приема параметри, можем да "залепим" параметрите за флага, тоест да няма бяло
    # поле. На пример флагът '-f' на командата 'cut' приема списък от числа и можем да го запишем по два
    # начина: '-f 1,2,4,9' и '-f1,2,4,9'.
   
# Examples commands:
    
    # Change file mode bits (read, write, execute permissions).
        # Example:
        chmod u=g f1  # Set the permissions of the owner of the file 'f1' the same as the group.
        chmod a+x f1  # Give permission to all users to execute the file.
        chmod ug-r f1 # Remove read permission for user and group.
        
    # 'cp' examples:
        cp *.txt <dest_dir>  # Copies all .txt files from the current directory to 'dest_dir'.
    
    # 'ls' examples:
        ls c*     # Print all files in current directory starting with the letter 'c'.
        ls *.txt  # Prints all files ending in '.txt' (except the file '.txt').
    
    # 'tar' examples:
        tar --create --file=myArchive f1 f2 f3  # Creates an archive called 'myArchive' with the files
                                                # f1, f2 and f3.
        tar --list --file=myArchive  # Lists the contents of 'myArchive'.
    
# Examples operators:
    
    # Examples '>' and '>>'.
        # Example:
        echo "I love Linux!" > f  # Creates a file 'f' with contents 'I love Linux!'.
        echo "Bananas!!!" > f     # Overwrites the contents of 'f' with 'Bananas!!!'.
        
        # Example:
        echo "I love Linux!" > f  # Creates a file 'f' with contents 'I love Linux!'.
        echo "Bananas!!!" >> f    # Appends 'Bananas!!!' to 'f' and the contents of 'f' become
                                  # 'I love Linux!Bananas!!!'.
        
        # Example:
        ls >> myFiles  # Writes the output of 'ls' in the file 'myFiles'.
        
        # Example:
        wc < file  # Does the same thing as 'wc file' but will not print the file name because in this case
                   # 'wc' is just given a stream of bytes and it doesn't know the file name.
                   
        # Example: 
        ls >> output_file 2>> error_output_file  # Both std error and std output are redirected to some files.
        
        # Example:
        some_command < file.txt > out.txt 2> error.txt  # 'some_command' gets its input from 'file.txt',
                                                        # saves its output to 'out.txt' and any error message
                                                        # goes to 'error.txt'.
    # Command substitution examples.
        # Example:
        cp $(ls) dir  # Copies all files from the current directory to the subdirectory 'dir'.
        # Example:
        rm $(ls)  # Removes all files in the current directory.
        
    # Piping examples:
        # Example: 
        ls | wc -l  # Prints how many files and directories in the current directory.