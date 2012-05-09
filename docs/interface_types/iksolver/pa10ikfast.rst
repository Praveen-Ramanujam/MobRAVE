.. _iksolver-pa10ikfast:

pa10ikfast - ikfastsolvers
--------------------------

:Type: :ref:`interface-iksolver`

:Plugin: :ref:`plugin-ikfastsolvers`

:Interface Author: Rosen Diankov

An OpenRAVE wrapper for the ikfast generated files.
If 6D IK is used, will check if the end effector and other independent links are in collision before manipulator link collisions. If they are, the IK will terminate with failure immediately.
Because checking collisions is the slowest part of the IK, the custom filter function run before collision checking.


pa10ikfast Commands
===================


.. _iksolver-pa10ikfast-help:


help
~~~~

display help commands.

~~~~


.. _iksolver-pa10ikfast-setikthreshold:


SetIkThreshold
~~~~~~~~~~~~~~

sets the ik threshold for validating returned ik solutions

~~~~

