.. _sensor-basespinninglaser2d:

BaseSpinningLaser2D - basesensors
---------------------------------

:Type: :ref:`interface-sensor`

:Plugin: :ref:`plugin-basesensors`

:Interface Author: Rosen Diankov

Provides a simulated spinning 2D laser range finder. Includes all the XML parameters from :ref:`sensor-baselaser2d` along with:
* spinaxis - the second axis to spin on
* spinpos - center of rotation of second spin axis
* spinspeed - how fast to spin in rad/s

.. image:: ../../../images/interface_basespinninglaser.jpg
  :width: 400



BaseSpinningLaser2D Commands
============================


.. _sensor-basespinninglaser2d-collidingbodies:


collidingbodies
~~~~~~~~~~~~~~~

Returns the ids of the bodies that the laser beams have hit.

~~~~


.. _sensor-basespinninglaser2d-help:


help
~~~~

display help commands.

~~~~


.. _sensor-basespinninglaser2d-render:


render
~~~~~~

Set rendering of the plots (1 or 0).

~~~~

