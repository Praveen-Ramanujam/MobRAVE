.. _iksolver-ikfast_pr2_rightarm:

ikfast_pr2_rightarm - ikfastsolvers
-----------------------------------

:Type: :ref:`interface-iksolver`

:Plugin: :ref:`plugin-ikfastsolvers`

:Interface Author: Rosen Diankov

An OpenRAVE wrapper for the ikfast generated files.
If 6D IK is used, will check if the end effector and other independent links are in collision before manipulator link collisions. If they are, the IK will terminate with failure immediately.
Because checking collisions is the slowest part of the IK, the custom filter function run before collision checking.


ikfast_pr2_rightarm Commands
============================


.. _iksolver-ikfast_pr2_rightarm-help:


help
~~~~

display help commands.

~~~~


.. _iksolver-ikfast_pr2_rightarm-setikthreshold:


SetIkThreshold
~~~~~~~~~~~~~~

sets the ik threshold for validating returned ik solutions

~~~~

