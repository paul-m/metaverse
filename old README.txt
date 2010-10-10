$Id: README.txt,v 1.3 2007/11/28 15:46:08 kbahey Exp $

Copyright 2007 Khalid Baheyeldin http://2bits.com

This module is a simple Second Life framework, allowing objects inside 
Second Life to interact with your web server and do neat things.

Installation
------------
To install this module, Upload or copy the the entire secondlife directory and 
all its contents to your modules directory.

Configuration
-------------
To enable this module do the following:

1. Go to Administer -> Site Building -> Modules, and enable second life.

Developing for Second Life
---------------------------
Second Life objects are written in a language called llscript (Linden Lab
Script). For more on how to use this language, refer to this wiki:
http://wiki.secondlife.com/wiki/LSL_Portal

The Second Life framework module interfaces with Second Life using the
llHTTPRequest function. 

See details here:
http://rpgstats.com/wiki/index.php?title=LlHTTPRequest

In order to write a Drupal application that interfaces with Second Life, you
need to create a new module. See the sltest module in the samples directory
for an example.

The app is the application name, and is also the module name. The cmd is
a command that your module/app must handle. The args vary from one cmd
to the other.

The $sl object contains the Second Life info you need to know, such as region,
location in the grid, user name, user key, ...etc. The $args is an array that
is passed from the llScript to you.

Debugging
---------
A test client emulator script is provided, called slclient.php. It is designed
to run from the command line, and takes two arguments: the server name, and
the handler.

    $ php slclient.php localhost /secondlife

Modify the app and cmd array to the application you are developing. The app
will be your module name, and /secondlife should remain the same.

A variable called secondlife_debug can be set in your settings.php in the $conf
array. Set it to a path writable to your web server to see what is going on
between your web server and your Second Life object.

TO DO
-----

- Limit IP address range to accept requests from to Linden Labs servers.
- Map Second Life users to Drupal users.

Bugs/Features/Patches:
----------------------
If you want to report bugs, feature requests, or submit a patch, please do so
at the project page on the Drupal web site.

Author
------
Khalid Baheyeldin (http://2bits.com)

The author can also be contacted for paid customizations of this and other modules.
