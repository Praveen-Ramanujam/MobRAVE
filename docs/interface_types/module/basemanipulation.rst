.. _module-basemanipulation:

BaseManipulation - rmanipulation
--------------------------------

:Type: :ref:`interface-module`

:Plugin: :ref:`plugin-rmanipulation`

:Interface Author: Rosen Diankov

Very useful routines for manipulation planning and planning in general. The planners use analytical inverse kinematics and search based techniques. Most of the MoveX commands by default execute the plan on the current robot by calling :meth:`.RobotBase.SetActiveMotion`. This can be disabled by adding 'execute 0' to the command line


BaseManipulation Commands
=========================


.. _module-basemanipulation-findikwithfilters:


FindIKWithFilters
~~~~~~~~~~~~~~~~~

Samples IK solutions using custom filters that constrain the end effector in the world. Parameters:

- cone - Constraint the direction of a local axis with respect to a cone in the world. Takes in: worldaxis(3), localaxis(3), anglelimit. 
- solveall - When specified, will return all possible solutions.
- ikparam - The serialized ik parameterization to use for FindIKSolution(s).
- filteroptions


~~~~


.. _module-basemanipulation-grabbody:


GrabBody
~~~~~~~~

Robot calls ::Grab on a body with its current manipulator

~~~~


.. _module-basemanipulation-help:


help
~~~~

display help commands.

~~~~


.. _module-basemanipulation-jitteractive:


JitterActive
~~~~~~~~~~~~

Jitters the active DOF for a collision-free position.

~~~~


.. _module-basemanipulation-moveactivejoints:


MoveActiveJoints
~~~~~~~~~~~~~~~~

Moves the current active joints to a specified goal destination:

- maxiter - The maximum number of iterations on the internal planner.
- maxtries - The maximum number of times to restart the planner.
- steplength - See PlannerParameters::_fStepLength



~~~~


.. _module-basemanipulation-movehandstraight:


MoveHandStraight
~~~~~~~~~~~~~~~~

Move the active end-effector in a straight line until collision or IK fails. Parameters:

- steplength - the increments in workspace in which the robot tests for the next configuration.

- minsteps - The minimum number of steps that need to be taken in order for success to declared. If robot doesn't reach this number of steps, it fails.

- maxsteps - The maximum number of steps the robot should take.

- direction - The workspace direction to move end effector in.

Method wraps the WorkspaceTrajectoryTracker planner. For more details on parameters, check out its documentation.

~~~~


.. _module-basemanipulation-movemanipulator:


MoveManipulator
~~~~~~~~~~~~~~~

Moves arm joints of active manipulator to a given set of joint values

~~~~


.. _module-basemanipulation-movetohandposition:


MoveToHandPosition
~~~~~~~~~~~~~~~~~~

Move the manipulator's end effector to reach a set of 6D poses. Parameters:

- 

~~~~


.. _module-basemanipulation-moveunsyncjoints:


MoveUnsyncJoints
~~~~~~~~~~~~~~~~

Moves the active joints to a position where the inactive (hand) joints can
fully move to their goal. This is necessary because synchronization with arm
and hand isn't guaranteed.
Options: handjoints savetraj planner

~~~~


.. _module-basemanipulation-releaseall:


ReleaseAll
~~~~~~~~~~

Releases all grabbed bodies (RobotBase::ReleaseAllGrabbed).

~~~~


.. _module-basemanipulation-setactivemanip:


SetActiveManip
~~~~~~~~~~~~~~

Set the active manipulator

~~~~


.. _module-basemanipulation-traj:


Traj
~~~~

Execute a trajectory from a file on the local filesystem

~~~~


.. _module-basemanipulation-verifytrajectory:


VerifyTrajectory
~~~~~~~~~~~~~~~~

Verifies the robot trajectory by checking collisions with the environment and other user-specified constraints.

~~~~

