.. _module-viewerrecorder:

ViewerRecorder - logging
------------------------

:Type: :ref:`interface-module`

:Plugin: :ref:`plugin-logging`

:Interface Author: Rosen Diankov

Records the images produced from a viewer into video file. The recordings can be synchronized to real-time or simulation time, by default simulation time is used. Each instance can record only one file at a time. To record multiple files simultaneously, create multiple VideoRecorder instances


ViewerRecorder Commands
=======================


.. _module-viewerrecorder-getcodecs:


GetCodecs
~~~~~~~~~

Return all the possible codecs, one codec per line:[video_codec id] [name]

~~~~


.. _module-viewerrecorder-help:


help
~~~~

display help commands.

~~~~


.. _module-viewerrecorder-setwatermark:


SetWatermark
~~~~~~~~~~~~

Set a WxHx4 image as a watermark. Each color is an unsigned integer ordered as A|B|G|R. The origin should be the top left corner

~~~~


.. _module-viewerrecorder-start:


Start
~~~~~

Starts recording a file, this will stop all previous recordings and overwrite any previous files stored in this location. Format::

  Start [width] [height] [framerate] codec [codec] timing [simtime/realtime] viewer [name]\n filename [filename]\n

Because the viewer and filenames can have spaces, the names are ready until a newline is encountered

~~~~


.. _module-viewerrecorder-stop:


Stop
~~~~

Stops recording and saves the file. Format::

  Stop



~~~~

