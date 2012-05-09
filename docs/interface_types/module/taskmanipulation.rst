.. _module-taskmanipulation:

TaskManipulation - rmanipulation
--------------------------------

:Type: :ref:`interface-module`

:Plugin: :ref:`plugin-rmanipulation`

:Interface Author: Rosen Diankov

Task-based manipulation planning involving target objects. A lot of the algorithms and theory are covered in:

- Rosen Diankov. "Automated Construction of Robotic Manipulation Programs". PhD Thesis, CMU-RI-TR-10-29, Carnegie Mellon University, Robotics Institute, August 2010.



TaskManipulation Commands
=========================


.. _module-taskmanipulation-closefingers:


CloseFingers
~~~~~~~~~~~~

Closes the active manipulator fingers using the grasp planner.

~~~~


.. _module-taskmanipulation-createsystem:


CreateSystem
~~~~~~~~~~~~

creates a sensor system and initializes it with the current bodies

~~~~


.. _module-taskmanipulation-evaluateconstraints:


EvaluateConstraints
~~~~~~~~~~~~~~~~~~~

Instantiates a jacobian constraint function and runs it on several examples.
The constraints work on the active degress of freedom of the manipulator starting from the current configuration

~~~~


.. _module-taskmanipulation-graspplanning:


GraspPlanning
~~~~~~~~~~~~~

Grasp planning is the ultimate function that puts together many planners achieving a robust and general pick and place motiotions with grasp sets. It first chooses grasps from a grasp set and use it for manipulation. In order for the arm to reach the grasps, it must have a Transform6D or TranslationDirection5D IK solver, anything with less DOF will not work.
Parameters:

* grasps
* outputtraj
* execute
* randomdests
* writetraj
* maxiter
* igraspdir
* igrasppos
* igrasproll
* igraspstandoff
* igrasppreshape
* igrasptrans
* target
* approachoffset
* quitafterfirstrun
* matdests
* posedests
* seedgrasps
* seeddests
* seedik
* savepreshapetraj


~~~~


.. _module-taskmanipulation-help:


help
~~~~

display help commands.

~~~~


.. _module-taskmanipulation-releaseactive:


ReleaseActive
~~~~~~~~~~~~~

Moves the active DOF using the grasp planner.

~~~~


.. _module-taskmanipulation-releasefingers:


ReleaseFingers
~~~~~~~~~~~~~~

Releases the active manipulator fingers using the grasp planner.
Also releases the given object.

~~~~


.. _module-taskmanipulation-switchmodels:


SwitchModels
~~~~~~~~~~~~

Switches between thin and fat models for planning.

~~~~

