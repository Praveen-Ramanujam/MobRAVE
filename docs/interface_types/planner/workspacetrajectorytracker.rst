.. _planner-workspacetrajectorytracker:

WorkspaceTrajectoryTracker - rplanners
--------------------------------------

:Type: :ref:`interface-planner`

:Plugin: :ref:`plugin-rplanners`

:Interface Author:  Rosen Diankov

Given a workspace trajectory of the end effector of a manipulator (active manipulator of the robot), finds a configuration space trajectory that tracks it using analytical inverse kinematics.
Options can be specified to prioritize trajectory time, trajectory smoothness, and planning time
In the simplest case, the workspace trajectory can be a straight line from one point to another.

Planner Parameters
==================

- **dReal maxdeviationangle** - the maximum angle the next iksolution can deviate from the expected direction computed by the jacobian.

- **bool maintaintiming** - maintain timing with input trajectory

- **dReal ignorefirstcollision** - if > 0, will allow the robot to be in environment collision for the initial 'ignorefirstcollision' seconds of the trajectory. Once the robot gets out of collision, it will execute its normal following phase until it gets into collision again. This option is used when lifting objects from a surface, where the object is already in collision with the surface.

- **dReal minimumcompletetime** - specifies the minimum trajectory that must be followed for planner to declare success. If 0, then the entire trajectory has to be followed.

- **TrajectoryBasePtr workspacetraj** - workspace trajectory of the end effector, needs to hold 'ikparam_values' groups




WorkspaceTrajectoryTracker Commands
===================================


.. _planner-workspacetrajectorytracker-help:


help
~~~~

display help commands.

~~~~

