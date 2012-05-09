.. _iksolver-ikfast_katana5d_trans:

ikfast_katana5d_trans - ikfastsolvers
-------------------------------------

:Type: :ref:`interface-iksolver`

:Plugin: :ref:`plugin-ikfastsolvers`

:Interface Author: Rosen Diankov

An OpenRAVE wrapper for the ikfast generated files.
If 6D IK is used, will check if the end effector and other independent links are in collision before manipulator link collisions. If they are, the IK will terminate with failure immediately.
Because checking collisions is the slowest part of the IK, the custom filter function run before collision checking.


ikfast_katana5d_trans Commands
==============================


.. _iksolver-ikfast_katana5d_trans-help:


help
~~~~

display help commands.

~~~~


.. _iksolver-ikfast_katana5d_trans-setikthreshold:


SetIkThreshold
~~~~~~~~~~~~~~

sets the ik threshold for validating returned ik solutions

~~~~

