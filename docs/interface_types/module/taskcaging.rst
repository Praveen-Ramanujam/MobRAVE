.. _module-taskcaging:

TaskCaging - rmanipulation
--------------------------

:Type: :ref:`interface-module`

:Plugin: :ref:`plugin-rmanipulation`

:Interface Author: Rosen Diankov

.. image:: ../../../images/interface_taskcaging.jpg
  :width: 500

Implements various algorithms to open and close doors by having the hand cage the handles instead of tightly grip. This greatly relaxes the constraints on the robot (see the door manipluation example). The relevant paper is:

- Rosen Diankov, Siddhartha Srinivasa, Dave Ferguson, James Kuffner. Manipulation Planning with Caging Grasps. IEEE-RAS Intl. Conf. on Humanoid Robots, December 2008.


TaskCaging Commands
===================


.. _module-taskcaging-bodytraj:


bodytraj
~~~~~~~~

Starts a body to follow a trajectory. The trajrectory must contain timestamps
Options: target targettraj

~~~~


.. _module-taskcaging-graspset:


graspset
~~~~~~~~

Creates a grasp set given a robot end-effector floating in space.
Options: step exploreprob size target targetjoint contactconfigdelta cagedconfig

~~~~


.. _module-taskcaging-help:


help
~~~~

display help commands.

~~~~


.. _module-taskcaging-simpleconstraintplan:


simpleconstraintplan
~~~~~~~~~~~~~~~~~~~~

Invokes a simple one grasp planner

~~~~


.. _module-taskcaging-taskconstraintplan:


taskconstraintplan
~~~~~~~~~~~~~~~~~~

Invokes the relaxed task constrained planner

~~~~

