# png_to_video
This c program will generate an *.mp4 file from a set of *.png files that capture sequential time steps

#Basic information

This program utilizes the package ffmpeg, which needs to be installed for compilation to be succesful.

A Matlab script is also included to create a series of flood depth png images.

#Compilation

gcc -o png_to_video png_to_video.c

#Usage

Assuming you have a set of *.png files that you seek to animate, you'll need to name them using a pattern such as this:

flood_0001.png, flood_0002.png, flood_0003.png, ... and so on

Note that here, the root of the name is "flood". Alas, usage proceeds as follows:

./png_to_video flood

and this will automatically load all of the "flood" image files, and create one output file,

flood.mp4


