.. _module-ikfast:

ikfast - ikfastsolvers
----------------------

:Type: :ref:`interface-module`

:Plugin: :ref:`plugin-ikfastsolvers`

:Interface Author: Rosen Diankov

Allows dynamic loading and registering of ikfast shared objects to openrave plugins.
Also contains several test routines for inverse kinematics.


ikfast Commands
===============


.. _module-ikfast-addiklibrary:


AddIkLibrary
~~~~~~~~~~~~

Dynamically adds an ik solver to openrave by loading a shared object (based on ikfast code generation).
Usage::

  AddIkLibrary iksolvername iklibrarypath

return the type of inverse kinematics solver (IkParamterization::Type)

~~~~


.. _module-ikfast-debugik:


DebugIK
~~~~~~~

Function used for debugging and testing an IK solver. Input parameters are:

* string readfile - file containing joint values to read, starts with number of entries.

* int numtests - if file not specified, number of random tests to perform (defualt is 1000).

* float sampledegeneratecases - probability in [0,1] specifies the probability of sampling joint values on [-pi/2,0,pi/2] (default is 0.2).

* int selfcollision - if true, will check IK only for non-self colliding positions of the robot (default is 0).

* string robot - name of the robot to test. the active manipulator of the roobt is used.



~~~~


.. _module-ikfast-help:


help
~~~~

display help commands.

~~~~


.. _module-ikfast-iktest:


IKTest
~~~~~~

Tests for an IK solution if active manipulation has an IK solver attached

~~~~


.. _module-ikfast-loadikfastsolver:


LoadIKFastSolver
~~~~~~~~~~~~~~~~

Dynamically calls the inversekinematics.py script to generate an ik solver for a robot, or to load an existing one
Usage::

  LoadIKFastSolver robotname iktype_id [free increment]

return nothing, but does call the SetIKSolver for the robot

~~~~


.. _module-ikfast-perftiming:


PerfTiming
~~~~~~~~~~

Times the ik call of a given library.
Usage::

  PerfTiming [options] iklibrarypath

return the set of time measurements made in nano-seconds

~~~~

