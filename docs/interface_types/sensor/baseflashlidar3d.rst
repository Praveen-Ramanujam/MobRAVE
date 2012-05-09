.. _sensor-baseflashlidar3d:

BaseFlashLidar3D - basesensors
------------------------------

:Type: :ref:`interface-sensor`

:Plugin: :ref:`plugin-basesensors`

:Interface Author: Rosen Diankov

Provides a simulated 3D flash lidar sensor. A flash LIDAR instantaneously returns the depth measurements in the form of an image. It has the same projection parameters as a camera except each pixel is an active element that measures distance. The XML parameters are the same as :ref:`sensor-baselaser2d` along with:
* KK - 4 element vector that constructs the intrinsic matrix of the flash lidar (KK[0] 0 KK[2]; 0 KK[1] KK[3]; 0 0 1]. 
* width - the number of active elements along the x-axis.
* height - the number of active elements along the y-axis.

.. image:: ../../../images/interface_baseflashlidar.jpg
  :width: 400



BaseFlashLidar3D Commands
=========================


.. _sensor-baseflashlidar3d-collidingbodies:


collidingbodies
~~~~~~~~~~~~~~~

Returns the ids of the bodies that the laser beams have hit.

~~~~


.. _sensor-baseflashlidar3d-help:


help
~~~~

display help commands.

~~~~


.. _sensor-baseflashlidar3d-render:


render
~~~~~~

Set rendering of the plots (1 or 0).

~~~~

